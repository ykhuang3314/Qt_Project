#include "sst26vf016b.h"

#define JEDECID 0x9F
#define UNUSED(a) ((void)(a))

SST26VF016B::SST26VF016B()
{
    SPI_Channel = 0;
    memset(jedecid, 0, sizeof(jedecid));
}



void SST26VF016B::Read_JEDEC_ID(uint8_t *buf){
    unsigned char data[4];
    int rc;
    UNUSED(rc);
    data[0] = JEDECID;
    rc = wiringPiSPIDataRW(SPI_Channel, data, sizeof(data));
    memcpy(buf, &data[1], 3);
}

uint8_t* SST26VF016B::Read_JEDEC_ID2(){
    unsigned char data[4];
    uint8_t result[3];
    int rc;
    UNUSED(rc);
    data[0] = JEDECID;
    rc = wiringPiSPIDataRW(SPI_Channel, data, sizeof(data));
    memcpy(result, &data[1], 3);
    return result;
}
