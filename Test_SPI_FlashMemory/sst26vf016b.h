#ifndef SST26VF016B_H
#define SST26VF016B_H

#include <QObject>
#include <QtGlobal>

#define UNUSED(a) ((void)(a))

//Device Operation Instructions
#define RDSR 0x05
#define WRSR 0x01
#define RDCR 0x35
#define READ 0x03
#define RDJEDECID 0x9F
#define WREN 0x06
#define WRDI 0x04
#define PP 0x02

// Status regsiter mask
#define isBUSY_MASK 0x01
#define isWRITEALBE_MASK 0x02


class SST26VF016B : public QObject
{
    Q_OBJECT

public:
    explicit SST26VF016B(QObject *parent = nullptr);
    bool SPI_Setup(void);
    void setSPI(int ch, int speed);
    quint8 READ_STATUS_REG(void);
    void JEDECID(quint8 *data);
    void WRITE_ENABLE(void);
    void WRITE_DISABLE(void);
    bool IS_BUSY(void);
    bool IS_WRITEABLE(void);
    void READ_MEM(quint32 addr, quint8 *data, quint16 n);
    quint16 PAGE_PROGRAM(quint16 sec_no, quint16 addr, quint8* data, uint16_t n);


signals:

public slots:

private:
   int SPI_Ch, fSCLK;
};

#endif // SST26VF016B_H
