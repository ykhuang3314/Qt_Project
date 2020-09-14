#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    wiringPiSetup();
    pinMode(0,OUTPUT);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    while(true){
        digitalWrite(0, HIGH); delay(500);
        digitalWrite(0, LOW); delay(500);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QApplication::quit();
}
