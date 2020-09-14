#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    QString show = "obtaining JEDEC ID ...";
    ui->textBrowser->append(show);
    //Dev1.Read_JEDEC_ID(Dev1.jedecid);
    //ui->textBrowser->clear();
    uint8_t* tmp={0};
    tmp=Dev1.Read_JEDEC_ID2();
    QString result = QString::fromUtf8((char*)tmp);
    ui->textBrowser->append(result);

}

void MainWindow::on_pushButton_3_clicked()
{
    if (wiringPiSPISetup(Dev1.SPI_Channel, 2000000)<0){
        QMessageBox::warning(this, "waring", "SPI setup failed ....");
    }
    else{
        ui->textBrowser->setText("SPI setup sucessful");
    }
}
