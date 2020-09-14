#ifndef RHD2132_H
#define RHD2132_H

#include <QObject>
#include <QtGlobal>
#include <QVector>
#include <QMutex>
#include <QWaitCondition>

class RHD2132 : public QObject
{
    Q_OBJECT

public:
    explicit RHD2132(QObject *parent = nullptr);

    void setSPI_Param(int ch, int speed);
    bool SetupSPI(void);

    quint16 CONVERT(quint8 Channel);
    quint16 CALIBRATE_ADC(void);
    quint16 CLEAR_ADC(void);
    bool WRITE(quint8 reg_addr, quint8 data);
    quint8 READ(quint8 reg_addr);

    void CONFIG_ADC(void);
    void SET_SamplingRate(double rate);
    void Setup_REG(double SamplingRate);
    void SET_BANDWIDTH(int RH1_DAC1, int RH1_DAC2, int RH2_DAC1, int RH2_DAC2, int RL_DAC1, int RL_DAC2, int RL_DAC3);
    void SET_Rh_Rl(int RH1_DAC1, int RH1_DAC2, int RH2_DAC1, int RH2_DAC2, int RL_DAC1, int RL_DAC2, int RL_DAC3);
    quint8 GET_REG_Value(int REG);
    quint8 GET_ID(void);
    void CONFIG_REG(void);

    void SetupThread (QThread &thread);
    void pause(void);
    void restart(void);

    bool WRITE_TEST(quint8 reg_addr, quint8 data, quint8* d);
    quint8 READ_TEST(quint8 reg_addr, quint8* d);
signals:
    void new_data(quint16 recorded_data);
    void finished();

public slots:
    void thread_init(void);
    void thread_finished(void);

private:
    //thread
    QMutex m_continue;
    QWaitCondition m_pause;
    bool m_cancelRequested;
    bool m_pauseRequested;

    //SPI Param.
    int SPI_Channel, SPI_Mode, fSCLK;

    double Sampling_Rate;

    //REG0 variables (ADC Config. & Amp. fast settle)
    int ADC_Ref_BW, Amp_Fast_Settle, En_Amp_Ref, ADC_Comp_Bias, ADC_Comp_Sel;

    //REG1 variables (Supply sensor & ADC buffer bias current)
    int VDD_Sense_EN, ADC_Ibuffer;

    //REG2 variables (Mux bias curent)
    int Mux_Bias;

    //REG3 variables (Mux load, temp. sensor , aux dig out)
    int Mux_Load, Temp_S2, Temp_S1, Temp_EN, DigOut_HiZ, DigOut;

    //REG4 variables (ADC output format, DSP offset removal)
    int Weak_MISO, Twos_Comp, Abs_Mode, DSP_En, DSP_Cutoff;

    //REG5 variables (Impedance Check Control)
    int Zcheck_DACpwr, Zcheck_load, Zcheck_scale, Zcheck_ConnAll, Zcheck_Sel_Pol, Zcheck_EN;

    //REG6 variables (Check DAC)
    int Zcheck_DAC;

    //REG7 variables (Impedance check amp sel)
    int Zcheck_Sel;

    //REG8-13 (Amplifier bandwidth selection)
    int RH1_DAC1, RH1_DAC2, RH2_DAC1, RH2_DAC2, RL_DAC1, RL_DAC2, RL_DAC3;
    int offchip_RH1, offchip_RH2, offchip_RL;
    int ADC_aux1, ADC_aux2, ADC_aux3;

    //REG14-17 (Individual Amp power)
    QVector<int> Amp_Pwr;


};

#endif // RHD2132_H
