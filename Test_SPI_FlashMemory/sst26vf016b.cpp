#include "sst26vf016b.h"
#include "wiringPi.h"
#include "wiringPiSPI.h"


SST26VF016B::SST26VF016B(QObject *parent) : QObject(parent)
{
    SPI_Ch = 0;
    fSCLK = 1000000;
}

void SST26VF016B::setSPI(int ch, int speed){
    SPI_Ch=ch;
    fSCLK=speed;
}

bool SST26VF016B::SPI_Setup(){
    return (!(wiringPiSPISetup(SPI_Ch, fSCLK)<0));
}

quint8 SST26VF016B::READ_STATUS_REG(void){
    unsigned char tmp[2];
    int rc;
    UNUSED(rc);
    tmp[0] = RDSR;
    rc = wiringPiSPIDataRW(SPI_Ch, tmp, sizeof(tmp));
    return tmp[1];
}

void SST26VF016B::JEDECID(quint8 *data){
    unsigned char tmp[4];
    int rc;
    UNUSED(rc);
    tmp[0] = RDJEDECID;
    rc = wiringPiSPIDataRW(SPI_Ch, tmp, sizeof(tmp));
    memcpy(data, &tmp[1], 3);
}

void SST26VF016B::WRITE_ENABLE(void){
    unsigned char tmp[1];
    int rc;
    UNUSED(rc);
    tmp[0] = WREN;
    rc = wiringPiSPIDataRW(SPI_Ch, tmp, sizeof(tmp));
}

void SST26VF016B::WRITE_DISABLE(void){
    unsigned char tmp[1];
    int rc;
    UNUSED(rc);
    tmp[0] = WRDI;
    rc = wiringPiSPIDataRW(SPI_Ch, tmp, sizeof(tmp));
}

bool SST26VF016B::IS_BUSY(void){
    unsigned char status = READ_STATUS_REG();
    if(status & isBUSY_MASK)    return true;
    return false;
}

bool SST26VF016B::IS_WRITEABLE(void){
    unsigned char status = READ_STATUS_REG();
    if(status & isWRITEALBE_MASK)    return true;
    return false;
}

void SST26VF016B::READ_MEM(quint32 addr, quint8 *data, quint16 n){
    unsigned char *tmp;
    tmp = new unsigned char [n+4];
    int rc;
    UNUSED(rc);
    tmp[0] = READ;
    tmp[1] = (addr>>16) & 0xFF;
    tmp[2] = (addr>>8) & 0xFF;
    tmp[3] = addr & 0xFF;
    rc = wiringPiSPIDataRW(SPI_Ch, tmp, sizeof(tmp));
    memcpy(data, &tmp[4], n);
    delete[] tmp;
}

quint16 SST26VF016B::PAGE_PROGRAM(quint16 sec_no, quint16 addr, quint8* data, uint16_t n){

    //maximun data cycle = 256
    if(n>256) return 0;
    unsigned char *tmp;
    int rc;

    // starting address to be written
    quint32 address = sec_no;
    address<<=12;
    address += addr;

    // set to be writealbe and check if it's busy
    if(!(IS_WRITEABLE()))
        WRITE_ENABLE();
    if(IS_BUSY())   return 0;

    // write data
    tmp = new unsigned char [n+4];
    tmp[0] = PP;
    tmp[1] = (addr>>16) & 0xFF;
    tmp[2] = (addr>>8) & 0xFF;
    tmp[3] = addr & 0xFF;
    memcpy(&tmp[4], data, n);
    rc = wiringPiSPIDataRW(SPI_Ch, tmp, sizeof(tmp));

    //waiting
    while(IS_BUSY());

    delete[] tmp;
    return rc;
}
