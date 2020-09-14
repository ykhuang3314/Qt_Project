#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rhd2132.h"
#include "wiringPi.h"
#include "wiringPiSPI.h"
#include "qcustomplot.h"
#include "plot.h"
#include <QMessageBox>
#include <QtGlobal>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QFont>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

    // initialize plot widget
    this->channel1 = new plot(ui->plot_ch1);
    this->channel2 = new plot(ui->plot_ch2);
    // initialize a RHD2132 object
    this->my_RHD2132 = new RHD2132();

    this->isPaused = false;
    //ComboBox for Bandwidth selection

    ui->comboBox_fH->addItem("100 Hz");
    ui->comboBox_fH->addItem("150 Hz");
    ui->comboBox_fH->addItem("200 Hz");
    ui->comboBox_fH->addItem("250 Hz");
    ui->comboBox_fH->addItem("300 Hz");
    ui->comboBox_fH->addItem("500 Hz");
    ui->comboBox_fH->addItem("750 Hz");
    ui->comboBox_fH->addItem("1.0 kHz");
    ui->comboBox_fH->addItem("1.5 kHz");
    ui->comboBox_fH->addItem("2.0 kHz");
    ui->comboBox_fH->addItem("2.5 kHz");
    ui->comboBox_fH->addItem("3.0 kHz");
    ui->comboBox_fH->addItem("5.0 kHz");
    ui->comboBox_fH->addItem("7.5 kHz");
    ui->comboBox_fH->addItem("10.0 kHz");
    ui->comboBox_fH->addItem("15.0 kHz");
    ui->comboBox_fH->addItem("20.0 kHz");

    ui->comboBox_fL->addItem("0.10 Hz");
    ui->comboBox_fL->addItem("0.25 Hz");
    ui->comboBox_fL->addItem("0.30 Hz");
    ui->comboBox_fL->addItem("0.40 Hz");
    ui->comboBox_fL->addItem("0.75 Hz");
    ui->comboBox_fL->addItem("1.0 Hz");
    ui->comboBox_fL->addItem("1.5 Hz");
    ui->comboBox_fL->addItem("2.0 Hz");
    ui->comboBox_fL->addItem("2.5 Hz");
    ui->comboBox_fL->addItem("3.0 Hz");
    ui->comboBox_fL->addItem("5.0 Hz");
    ui->comboBox_fL->addItem("7.5 Hz");
    ui->comboBox_fL->addItem("10 Hz");
    ui->comboBox_fL->addItem("15 Hz");
    ui->comboBox_fL->addItem("20 Hz");
    ui->comboBox_fL->addItem("25 Hz");
    ui->comboBox_fL->addItem("30 Hz");
    ui->comboBox_fL->addItem("50 Hz");
    ui->comboBox_fL->addItem("75 Hz");
    ui->comboBox_fL->addItem("100 Hz");
    ui->comboBox_fL->addItem("150 Hz");
    ui->comboBox_fL->addItem("200 Hz");
    ui->comboBox_fL->addItem("250 Hz");
    ui->comboBox_fL->addItem("300 Hz");
    ui->comboBox_fL->addItem("500 Hz");

    // ComboBox for SPI param.
    ui->comboBox_spich->addItem("Channel 0");
    ui->comboBox_spich->addItem("Channel 1");

    ui->comboBox_fsclk->addItem("5 MHz");
    ui->comboBox_fsclk->addItem("10 MHz");
    ui->comboBox_fsclk->addItem("15 MHz");
    ui->comboBox_fsclk->addItem("20 MHz");
    ui->comboBox_fsclk->addItem("24 MHz");


    //real-time plotting
    this->plotting_timer = new QTimer(this);
    this->plotting_timer->setTimerType(Qt::PreciseTimer);
    connect(plotting_timer, SIGNAL(timeout()), channel1, SLOT(realtimeDataSlotTest()));
    connect(plotting_timer, SIGNAL(timeout()), channel2, SLOT(realtimeDataSlotTest()));

    //Sample data continuously by using thread
    this->thread = new QThread;
    my_RHD2132->moveToThread(thread);
    connect(thread, SIGNAL(started()), my_RHD2132, SLOT(thread_init()));
    connect(my_RHD2132, SIGNAL(new_data(quint16)), channel2, SLOT(getValue(quint16)));
    connect(my_RHD2132, SIGNAL(new_data(quint16)), this, SLOT(display_data(quint16)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_Program_triggered() // close application
{
   QMessageBox::StandardButton decision = QMessageBox::question(this, "Exit Program", "Do you want to exit?", QMessageBox::Yes|QMessageBox::No);
   if (decision==QMessageBox::Yes)
       QApplication::quit();

}


void MainWindow::on_pushButton_spisetup_clicked() // SPI initailization
{
    int fsclk;
    switch(ui->comboBox_fsclk->currentIndex()){
        case 0: fsclk=100000; break;
        case 1: fsclk=10000000; break;
        case 2: fsclk=15000000; break;
        case 3: fsclk=20000000; break;
        case 4: fsclk=24000000; break;
    }
    int SamplingRate = fsclk/48000;
    my_RHD2132->SET_SamplingRate(SamplingRate);
    my_RHD2132->setSPI_Param(ui->comboBox_spich->currentIndex(), fsclk);
    bool result = my_RHD2132->SetupSPI();
    if(result){
        ui->label_spi->setText("Setup Sucessful!");
        ui->statusBar->showMessage(QString("fsclk = %1; ch = %2").arg(fsclk).arg(ui->comboBox_spich->currentIndex()), 2000);
    }
    else {
        QMessageBox::warning(this, "warning", "SPI setup unsucessful.");
    }

}

void MainWindow::on_pushButton_BW_clicked() // Bandwidth setup for amplifier
{
    int RH1_DAC1, RH1_DAC2, RH2_DAC1, RH2_DAC2, RL_DAC1, RL_DAC2, RL_DAC3;
    switch(ui->comboBox_fH->currentIndex())
    {
        case 0: RH1_DAC1=8; RH1_DAC2=0; RH2_DAC1=4; RH2_DAC2=0; break;
        case 1: RH1_DAC1=11; RH1_DAC2=0; RH2_DAC1=8; RH2_DAC2=0; break;
        case 2: RH1_DAC1=17; RH1_DAC2=0; RH2_DAC1=16; RH2_DAC2=0; break;
        case 3: RH1_DAC1=22; RH1_DAC2=0; RH2_DAC1=23; RH2_DAC2=0; break;
        case 4: RH1_DAC1=33; RH1_DAC2=0; RH2_DAC1=37; RH2_DAC2=0; break;
        case 5: RH1_DAC1=3; RH1_DAC2=1; RH2_DAC1=13; RH2_DAC2=1; break;
        case 6: RH1_DAC1=13; RH1_DAC2=1; RH2_DAC1=25; RH2_DAC2=1; break;
        case 7: RH1_DAC1=27; RH1_DAC2=1; RH2_DAC1=44; RH2_DAC2=1; break;
        case 8: RH1_DAC1=1; RH1_DAC2=2; RH2_DAC1=23; RH2_DAC2=2; break;
        case 9: RH1_DAC1=46; RH1_DAC2=2; RH2_DAC1=30; RH2_DAC2=3; break;
        case 10: RH1_DAC1=41; RH1_DAC2=3; RH2_DAC1=36; RH2_DAC2=4; break;
        case 11: RH1_DAC1=30; RH1_DAC2=5; RH2_DAC1=43; RH2_DAC2=6; break;
        case 12: RH1_DAC1=6; RH1_DAC2=9; RH2_DAC1=2; RH2_DAC2=11; break;
        case 13: RH1_DAC1=42; RH1_DAC2=10; RH2_DAC1=5; RH2_DAC2=13; break;
        case 14: RH1_DAC1=24; RH1_DAC2=13; RH2_DAC1=7; RH2_DAC2=16; break;
        case 15: RH1_DAC1=44; RH1_DAC2=17; RH2_DAC1=8; RH2_DAC2=21; break;
        case 16: RH1_DAC1=38; RH1_DAC2=26; RH2_DAC1=5; RH2_DAC2=31; break;
    }
    switch(ui->comboBox_fL->currentIndex())
    {
        case 0: RL_DAC1=13; RL_DAC2=0; RL_DAC3=0; break;
        case 1: RL_DAC1=15; RL_DAC2=0; RL_DAC3=0; break;
        case 2: RL_DAC1=17; RL_DAC2=0; RL_DAC3=0; break;
        case 3: RL_DAC1=18; RL_DAC2=0; RL_DAC3=0; break;
        case 4: RL_DAC1=21; RL_DAC2=0; RL_DAC3=0; break;
        case 5: RL_DAC1=25; RL_DAC2=0; RL_DAC3=0; break;
        case 6: RL_DAC1=28; RL_DAC2=0; RL_DAC3=0; break;
        case 7: RL_DAC1=34; RL_DAC2=0; RL_DAC3=0; break;
        case 8: RL_DAC1=44; RL_DAC2=0; RL_DAC3=0; break;
        case 9: RL_DAC1=48; RL_DAC2=0; RL_DAC3=0; break;
        case 10: RL_DAC1=54; RL_DAC2=0; RL_DAC3=0; break;
        case 11: RL_DAC1=62; RL_DAC2=0; RL_DAC3=0; break;
        case 12: RL_DAC1=5; RL_DAC2=1; RL_DAC3=0; break;
        case 13: RL_DAC1=18; RL_DAC2=1; RL_DAC3=0; break;
        case 14: RL_DAC1=40; RL_DAC2=1; RL_DAC3=0; break;
        case 15: RL_DAC1=20; RL_DAC2=2; RL_DAC3=0; break;
        case 16: RL_DAC1=42; RL_DAC2=2; RL_DAC3=0; break;
        case 17: RL_DAC1=8; RL_DAC2=3; RL_DAC3=0; break;
        case 18: RL_DAC1=9; RL_DAC2=4; RL_DAC3=0; break;
        case 19: RL_DAC1=44; RL_DAC2=6; RL_DAC3=0; break;
        case 20: RL_DAC1=49; RL_DAC2=9; RL_DAC3=0; break;
        case 21: RL_DAC1=35; RL_DAC2=17; RL_DAC3=0; break;
        case 22: RL_DAC1=1; RL_DAC2=40; RL_DAC3=0; break;
        case 23: RL_DAC1=56; RL_DAC2=54; RL_DAC3=0; break;
        case 24: RL_DAC1=16; RL_DAC2=60; RL_DAC3=1; break;
    }
    my_RHD2132->SET_Rh_Rl(RH1_DAC1, RH1_DAC2, RH2_DAC1, RH2_DAC2, RL_DAC1, RL_DAC2, RL_DAC3);
}

void MainWindow::on_pushButton_ADC_Cal_clicked()
{
    my_RHD2132->CALIBRATE_ADC();
}


void MainWindow::on_pushButton_Clear_Cal_clicked()
{
    my_RHD2132->CLEAR_ADC();
}

void MainWindow::on_pushButton_REG_Config_clicked()
{
    my_RHD2132->CONFIG_REG();
}

void MainWindow::on_pushButton_Show_REG_clicked()
{
    QString text = "Reading Status Registers (REG0 to REG17)... \n";
    quint8 data;
    for(int addr = 0; addr<18; addr++){
        data = my_RHD2132->READ(addr);
        text += QString("REG %1: ").arg(addr)+QString::number(data,2)+"\n";
    }
    ui->plainTextEdit_test->setPlainText(text);
}

void MainWindow::on_actionPause_triggered()
{
    if(plotting_timer->isActive()){
        plotting_timer->stop();
    }
    my_RHD2132->pause();
    this->isPaused = true;
}

void MainWindow::on_actionRun_triggered()
{
    plotting_timer->start();
    this->thread->start();
}

void MainWindow::display_data(quint16 data){
    QString data_str;
    data_str = QString::number(data);
    ui->label_showdata->setText(data_str);
}

void MainWindow::on_pushButton_clicked()
{
    QString addr_string = ui->lineEdit->text();
    quint8 addr = addr_string.toUInt();
    quint8 data = my_RHD2132->READ(addr);
    QString text = QString("REG %1: ").arg(addr)+QString::number(data,2);
    //ui->plainTextEdit_test->clear();
    ui->plainTextEdit_test->setPlainText(text);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->plainTextEdit_test->clear();
    quint8 d1[6];
    quint8 addr = 0;
    quint8 data = my_RHD2132->GET_REG_Value(addr);
    QString text = "Communication Test: Write "+ QString::number(data,2) + " to REG0....";
    ui->plainTextEdit_test->appendPlainText(text);
    bool result = my_RHD2132->WRITE_TEST(addr, data, d1);
    ui->plainTextEdit_test->appendPlainText("Data received during the communication:");
    for(int i=0; i<6; i++){
        ui->plainTextEdit_test->appendPlainText(QString("buf[%1] value:").arg(i)+QString::number(d1[i],2));
    }
    if(result){
        ui->plainTextEdit_test->appendPlainText("Sucessful writing!\n\n");
    }
    else{
        ui->plainTextEdit_test->appendPlainText("Unsucessful writing!\n\n");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->plainTextEdit_test->clear();
    quint8 d1[6];
    quint8 addr = 42;
    QString text = "Communictaion Test: Read the value in REG41 ";
    ui->plainTextEdit_test->appendPlainText(text);
    quint8 result = my_RHD2132->READ_TEST(addr, d1);
    ui->plainTextEdit_test->appendPlainText("Data received during the communication:");
    for(int i=0; i<6; i++){
        ui->plainTextEdit_test->appendPlainText(QString("buf[%1] value:").arg(i)+QString::number(d1[i],2));
    }
    //ui->plainTextEdit_test->appendPlainText("read result: " + QString::number(result, 2));
    if (result == 0){
        ui->plainTextEdit_test->appendPlainText("Unsucessful reading\n\n");
    }
    else{
        ui->plainTextEdit_test->appendPlainText("read result: " + QString::number(result, 2)+"\n\n");
        if(result == 84){
            ui->plainTextEdit_test->appendPlainText("Succesful Reading!");
        }
    }

}

