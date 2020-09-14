#include "rhd2132.h"
#include <QtGlobal>
#include "wiringPi.h"
#include "wiringPiSPI.h"
#include <QVector>
#include <QThread>
#include <QTime>
#include <qmath.h>

#define UNUSED(a) ((void)(a))

// RHD2132 16bit command word
#define CALIBRATE 0x55
#define CLEAR 0x6A
#define REG_WRITE 0x80
#define REG_READ 0xC0

// Address of specific ROM register
#define REG_ADDR_DieRevision 60
#define REG_ADDR_Amp_Polarity 61
#define REG_ADDR_Amp_Num 62
#define REG_ADDR_Chip_ID 63

#define Dummy_commad_MSB 0xE8;
#define Dummy_commad_LSB 0x00;

RHD2132::RHD2132(QObject *parent) : QObject(parent)
{
    SPI_Channel = 0;
    SPI_Mode = 0; // CPOL=0; CPHA=0
    fSCLK = 10000000;
    //this->Setup_REG(this->Sampling_Rate);

}

void RHD2132::setSPI_Param(int ch, int speed){
    SPI_Channel = ch;
    fSCLK = speed;
}


bool RHD2132::SetupSPI(void){

    //Maximum SCLK freq. is 24MHz
    bool result = wiringPiSPISetupMode(SPI_Channel, fSCLK, SPI_Mode)<0;
    return !result;

}

quint16 RHD2132::CONVERT(quint8 channel){
    int rc;
    UNUSED(rc);
    quint8 buf[6];
    buf[0] = channel;
    buf[1] = 0x00;
    buf[2] = 0xE8;
    buf[3] = 0x00;
    buf[4] = 0xE8;
    buf[5] = 0x00;
    rc = wiringPiSPIDataRW(SPI_Channel, buf, sizeof(buf));
    quint16 result = (buf[4]<<8) + buf[5];
    return result;
}

quint16 RHD2132::CALIBRATE_ADC(void){
    int rc;
    UNUSED(rc);
    quint8 buf[22];
    memset(buf, 0, sizeof(buf));
    buf[0] = CALIBRATE;
    buf[1] = 0x00;
    rc = wiringPiSPIDataRW(SPI_Channel, buf, sizeof(buf));
    quint16 result = (buf[20]<<8) + buf[21];
    return result;
}

quint16 RHD2132::CLEAR_ADC(void){
    int rc;
    UNUSED(rc);
    quint8 buf[4];
    //memset(buf, 0, sizeof(buf));
    buf[0] = CLEAR;
    buf[1] = 0x00;
    rc = wiringPiSPIDataRW(SPI_Channel, buf, sizeof(buf));
    quint16 result = (buf[2]<<8) + buf[3];
    return result;
}

bool RHD2132::WRITE(quint8 reg_addr, quint8 data){
    int rc;
    UNUSED(rc);
    quint8 buf[4];
    buf[0] = REG_WRITE+reg_addr;
    buf[1] = data;
    rc = wiringPiSPIDataRW(SPI_Channel, buf, sizeof(buf));
    return (buf[3]==data);
}

quint8 RHD2132::READ(quint8 reg_addr){
    int rc;
    UNUSED(rc);
    quint8 buf[6];
    memset(buf, 0, sizeof(buf));
    buf[0] = REG_READ+reg_addr;
    buf[1] = 0x00;
    rc = wiringPiSPIDataRW(SPI_Channel, buf, sizeof(buf));
    return buf[5];
}

void RHD2132::CONFIG_ADC(){
    int rc;
    UNUSED(rc);
    quint8 data = (ADC_Ref_BW<<6)|(Amp_Fast_Settle<<5)|(En_Amp_Ref<<4)|(ADC_Comp_Bias<<2)|ADC_Comp_Sel;
    quint8 reg_addr = 0x00;
    WRITE(reg_addr, data);
}

void RHD2132::SET_BANDWIDTH(int RH1_DAC1, int RH1_DAC2, int RH2_DAC1, int RH2_DAC2, int RL_DAC1, int RL_DAC2, int RL_DAC3){

    // set reg 8
    quint8 data = 0x00|RH1_DAC1;
    quint8 reg_addr = 0x08;
    this->WRITE(reg_addr, data);
    // set reg 9
    data = (ADC_aux1<<7)+RH1_DAC2;
    reg_addr = 0x09;
    this->WRITE(reg_addr, data);
    // set reg 10
    data = 0x00+RH2_DAC1;
    reg_addr = 0x0A;
    this->WRITE(reg_addr, data);
    // set reg 11
    data = (ADC_aux2<<7)+RH2_DAC2;
    reg_addr = 0x0B;
    this->WRITE(reg_addr, data);
    // set reg 12
    data = 0x00+RL_DAC1;
    reg_addr = 0x0B;
    this->WRITE(reg_addr, data);
    // set reg13
    data = (ADC_aux3<<7)+(RL_DAC3<<6)+RL_DAC2;
    reg_addr = 0x0C;
    this->WRITE(reg_addr, data);
}

quint8 RHD2132::GET_ID(void){
    quint8 addr=REG_ADDR_Chip_ID;
    return this->READ(addr);
}

void RHD2132::SET_SamplingRate(double rate){
    Sampling_Rate = rate;
}

void RHD2132::Setup_REG(double SamplingRate){

    Amp_Pwr.resize(32);
    //Set default value for all register

    //REG0
    ADC_Ref_BW = 3; //always be set to 3
    Amp_Fast_Settle = 0;
    En_Amp_Ref = 1; // 1: enable 0: power off
    ADC_Comp_Bias = 3; //always be set to 3
    ADC_Comp_Sel = 2; //always be set to 3

    //REG1.REG2 param depends on fsampling
    VDD_Sense_EN = 0; // disable on-chip supply voltage sensor

    if(SamplingRate < 121.0){
        Mux_Bias = 40;
        ADC_Ibuffer = 32;
    }
    else if(SamplingRate < 141.0){
        Mux_Bias = 40;
        ADC_Ibuffer = 16;
    }
    else if(SamplingRate < 176.0){
        Mux_Bias = 40;
        ADC_Ibuffer = 8;
    }
    else if(SamplingRate < 221.0){
        Mux_Bias = 32;
        ADC_Ibuffer = 8;
    }
    else if(SamplingRate < 281.0){
        Mux_Bias = 26;
        ADC_Ibuffer = 8;
    }
    else if(SamplingRate < 351.0){
        Mux_Bias = 18;
        ADC_Ibuffer = 4;
    }
    else if(SamplingRate < 441.0){
        Mux_Bias = 16;
        ADC_Ibuffer = 3;
    }
    else if(SamplingRate < 526.0){
        Mux_Bias = 7;
        ADC_Ibuffer = 3;
    }
    else{
        Mux_Bias = 4;
        ADC_Ibuffer = 2;
    }

    //REG3
    Mux_Load = 0; //always be set to 0
    Temp_S1 = 0;
    Temp_S2 = 0;
    Temp_EN = 0;
    DigOut_HiZ = 1;
    DigOut = 0;

    //REG4
    Weak_MISO = 1;
    Twos_Comp = 0;
    Abs_Mode = 0;
    DSP_En = 1; //DSP offset removal enabled
    DSP_Cutoff =1;

    /*Disable impedance checking*/

    //REG5
    Zcheck_DACpwr = 0;
    Zcheck_load = 0;
    Zcheck_scale = 0;
    Zcheck_ConnAll = 0;
    Zcheck_Sel_Pol = 0;
    Zcheck_EN = 0;

    //REG6
    Zcheck_DAC = 0;

    //REG7
    Zcheck_Sel = 0;

    //REG8-13
    offchip_RH1 = 0;
    offchip_RH2 = 0;
    offchip_RL = 0;
    ADC_aux1 = 1;
    ADC_aux2 = 1;
    ADC_aux3 = 1;

    //REG14-17 enable all amplifiers
    for(int i = 0; i<32; i++){
        Amp_Pwr[i] = 1;
    }

}

void RHD2132::SET_Rh_Rl(int RH1_DAC1, int RH1_DAC2, int RH2_DAC1, int RH2_DAC2, int RL_DAC1, int RL_DAC2, int RL_DAC3){
    this->RH1_DAC1 = RH1_DAC1;
    this->RH1_DAC2 = RH1_DAC2;
    this->RH2_DAC1 = RH2_DAC1;
    this->RH2_DAC2 = RH2_DAC2;
    this->RL_DAC1 = RL_DAC1;
    this->RL_DAC2 = RL_DAC2;
    this->RL_DAC3 = RL_DAC3;

}

quint8 RHD2132::GET_REG_Value(int REG){

    quint8 value;
    switch(REG){

    case 0:
        value = (ADC_Ref_BW<<6) + (Amp_Fast_Settle<<5) + (En_Amp_Ref<<4) + (ADC_Comp_Bias<<2) + ADC_Comp_Sel;
        break;
    case 1:
        value = (VDD_Sense_EN<<6) + ADC_Ibuffer;
        break;
    case 2:
        value = Mux_Bias;
        break;
    case 3:
        value = (Mux_Load<<6) + (Temp_S2<<4) + (Temp_S1<<3) + (Temp_EN<<2) + (DigOut_HiZ<<1) + DigOut;
        break;
    case 4:
        value = (Weak_MISO<<7) + (Twos_Comp<<6) + (Abs_Mode<<5) + (DSP_En<<4) + DSP_Cutoff;
        break;
    case 5:
        value = (Zcheck_DACpwr<<6) + (Zcheck_load<<5) + (Zcheck_scale<<3) + (Zcheck_ConnAll<<2) + (Zcheck_Sel_Pol<<1) + Zcheck_EN;
        break;
    case 6:
        value = Zcheck_DAC;
        break;
    case 7:
        value = Zcheck_Sel;
        break;
    case 8:
        value = (offchip_RH1<<7) + RH1_DAC1;
        break;
    case 9:
        value = (ADC_aux1<<7) + RH1_DAC2;
        break;
    case 10:
        value = (offchip_RH2<<7) + RH2_DAC1;
        break;
    case 11:
        value = (ADC_aux2<<7) + RH2_DAC2;
        break;
    case 12:
        value = (offchip_RL<<7) + RL_DAC1;
        break;
    case 13:
        value = (ADC_aux3<<7) + (RL_DAC3<<6) + RL_DAC2;
        break;
    case 14:
        value = (Amp_Pwr[7]<<7) + (Amp_Pwr[6]<<6) + (Amp_Pwr[5]<<5) + (Amp_Pwr[4]<<4) + (Amp_Pwr[3]<<3) + (Amp_Pwr[2]<<2) + (Amp_Pwr[1]<<1) + Amp_Pwr[0];
        break;
    case 15:
        value = (Amp_Pwr[15]<<7) + (Amp_Pwr[14]<<6) + (Amp_Pwr[13]<<5) + (Amp_Pwr[12]<<4) + (Amp_Pwr[11]<<3) + (Amp_Pwr[10]<<2) + (Amp_Pwr[8]<<1) + Amp_Pwr[8];
        break;
    case 16:
        value = (Amp_Pwr[23]<<7) + (Amp_Pwr[22]<<6) + (Amp_Pwr[21]<<5) + (Amp_Pwr[20]<<4) + (Amp_Pwr[19]<<3) + (Amp_Pwr[18]<<2) + (Amp_Pwr[17]<<1) + Amp_Pwr[16];
        break;
    case 17:
        value = (Amp_Pwr[31]<<7) + (Amp_Pwr[30]<<6) + (Amp_Pwr[29]<<5) + (Amp_Pwr[28]<<4) + (Amp_Pwr[27]<<3) + (Amp_Pwr[26]<<2) + (Amp_Pwr[25]<<1) + Amp_Pwr[24];
        break;
    default:
        value = 0;
        break;
    }
    return value;
}

void RHD2132::CONFIG_REG(void){
    this->Setup_REG(Sampling_Rate);
    int Total_REG = 18;
    for(int i=0; i<Total_REG; i++){
        quint8 data = this->GET_REG_Value(i);
        this->WRITE(i, data);
    }
}

void RHD2132::SetupThread(QThread &thread){
    connect(&thread, SIGNAL(started()), this, SLOT(thread_init()));
}

void RHD2132::thread_init(void){
    while (1) {
        if(m_pauseRequested){
            m_pause.wait(&m_continue);
        }
        quint16 data = 1;
        emit new_data(data);
        QThread::msleep(50);
        if(m_cancelRequested){
            emit finished();
        }
    }
}

void RHD2132::restart(){
    this->m_pauseRequested = false;
    this->m_pause.wakeAll();
}

void RHD2132::pause(){
    this->m_pauseRequested = true;
}

void RHD2132::thread_finished(){
    this->restart();
    this->m_cancelRequested = true;
}

bool RHD2132::WRITE_TEST(quint8 reg_addr, quint8 data, quint8* d){
    int rc;
    UNUSED(rc);
    quint8 buf[2], Dummy1[2], Dummy2[2], comm[6];
    memset(buf,0,sizeof(buf));
    buf[0] = REG_WRITE+reg_addr;
    buf[1] = data;
    rc = wiringPiSPIDataRW(SPI_Channel, buf, sizeof(buf));
    Dummy1[0] = Dummy_commad_MSB;
    Dummy1[1] = Dummy_commad_LSB;
    rc = wiringPiSPIDataRW(SPI_Channel, Dummy1, sizeof(Dummy1));
    Dummy2[0] = Dummy_commad_MSB;
    Dummy2[1] = Dummy_commad_LSB;
    rc = wiringPiSPIDataRW(SPI_Channel, Dummy2, sizeof(Dummy2));
    comm[0] = buf[0];
    comm[1] = buf[1];
    comm[2] = Dummy1[0];
    comm[3] = Dummy1[1];
    comm[4] = Dummy2[0];
    comm[5] = Dummy2[1];
    memcpy(d, &comm[0], 6);
    return (Dummy2[1]==data);
}

quint8 RHD2132::READ_TEST(quint8 reg_addr, quint8* d){
    int rc;
    UNUSED(rc);
    quint8 buf[2], Dummy1[2], Dummy2[2], comm[6];
    memset(buf, 0, sizeof(buf));
    buf[0] = REG_READ+reg_addr;
    buf[1] = 0x00;
    rc = wiringPiSPIDataRW(SPI_Channel, buf, sizeof(buf));
    Dummy1[0] = REG_READ+reg_addr;
    Dummy1[1] = 0x00;
    rc = wiringPiSPIDataRW(SPI_Channel, Dummy1, sizeof(Dummy1));
    Dummy2[0] = REG_READ+reg_addr;
    Dummy2[1] = 0x00;
    rc = wiringPiSPIDataRW(SPI_Channel, Dummy2, sizeof(Dummy2));
    comm[0] = buf[0];
    comm[1] = buf[1];
    comm[2] = Dummy1[0];
    comm[3] = Dummy1[1];
    comm[4] = Dummy2[0];
    comm[5] = Dummy2[1];
    memcpy(d, &comm[0], 6);
    return Dummy2[2];
}

