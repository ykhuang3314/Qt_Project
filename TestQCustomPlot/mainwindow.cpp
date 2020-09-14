#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    TestPlot(ui->widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TestPlot(QCustomPlot *customplot){
    int size=101;
    QVector<double> x(size), y(size);
    for(int i=0; i<size; i++){
        x[i]=i/50.0-1;
        y[i]=x[i]*x[i];
    }
    customplot->addGraph();
    customplot->graph(0)->addData(x,y);
    customplot->replot();
}
