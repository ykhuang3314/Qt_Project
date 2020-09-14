#ifndef SST26VF016B_H
#define SST26VF016B_H

#include "wiringPi.h"
#include "wiringPiSPI.h"
#include "stdint.h"
#include "string.h"

class SST26VF016B
{
public:
    SST26VF016B();
    void Read_JEDEC_ID(uint8_t *buf);
    uint8_t* Read_JEDEC_ID2();
    uint8_t jedecid[3];
    int SPI_Channel;

private:


};

#endif // SST26VF016B_H
