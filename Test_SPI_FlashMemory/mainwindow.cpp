#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QComboBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //initailize a flash memory object
    my_flashMem = new SST26VF016B();

    ui->comboBox_spich->addItem("Channel 0");
    ui->comboBox_spich->addItem("Channel 1");
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    QString input_speed = ui->lineEdit_fSCLK->text();
    int fSCLK = input_speed.toInt();
    SPI_Ch = ui->comboBox_spich->currentIndex();
    if(my_flashMem->SPI_Setup()){
        ui->statusBar->showMessage("SPI Setup sucessful", 3000);
    }
    else {
        ui->statusBar->showMessage("SPI Setup unsucessful", 3000);
    }
    my_flashMem->setSPI(SPI_Ch, fSCLK);
}


void MainWindow::on_pushButton_2_clicked()
{
    quint8 ID[3];
    my_flashMem->JEDECID(ID);
    QString result;
    for(int i=0; i<3; i++ ){
        result += QString::number(ID[i],16);
        result += " ";
    }
    ui->lineEdit_ID->setText(result);
}

void MainWindow::on_pushButton_updatestatus_clicked()
{
    if(ui->radioButton_ENWR->isChecked()){
        my_flashMem->WRITE_ENABLE();
    }
    else{
        my_flashMem->WRITE_DISABLE();
    }
}


void MainWindow::on_pushButton_StatusReg_clicked()
{
    quint8 statusreg = my_flashMem->READ_STATUS_REG();
    QString result = QString::number(statusreg,2);
    ui->lineEdit_status->setText(result);
}

