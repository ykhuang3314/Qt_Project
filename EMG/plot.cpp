#include "plot.h"
#include "qcustomplot.h"
#include <QPen>
#include <QFont>
#include <QTimer>
#include <QTime>
#include <qmath.h>

plot::plot(QCustomPlot *customPlot, QObject *parent) : QObject(parent)
{
    this->customPlot = customPlot;
    xRangeSize = 8;
    minY = -5.0;
    maxY = 5.0;
    new_value = 2;
    this->RealTimePlotting();

}

void plot::set_xRangeSize(double size){
    xRangeSize = size;

}

void plot::set_yAxis(double min, double max){
    minY = min;
    maxY = max;
}

void plot::setAxisName(const QString &xAxis, const QString &yAxis){
    xAxisName = xAxis;
    yAxisName = yAxis;
}

void plot::getValue(quint16 data){
    new_value = data;
    //this->realtimeDataSlot();
}

void plot::RealTimePlotting(void){

    //include this section to fully disable antialiasing for higher performance
    customPlot->setNotAntialiasedElement(QCP::aeAll);
    QFont font;
    font.setStyleStrategy(QFont::NoAntialias);
    customPlot->xAxis->setTickLabelFont(font);
    customPlot->yAxis->setTickLabelFont(font);
    customPlot->legend->setFont(font);

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%m:%s");
    customPlot->xAxis->setTicker(timeTicker);
    customPlot->axisRect()->setupFullAxesBox();
    customPlot->yAxis->setRange(minY,maxY);

    //add a blue line graph
    customPlot->addGraph();
    customPlot->graph(0)->setPen(QPen(Qt::blue));

    //make xAxis and yAxis transfer their range to xAxis2 and yAxis2 respectively
    connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

    //setup a timer that repeatedly calls plot::RealTimePlotting
    //connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    //dataTimer.start(0); //Interval 0: refresh as fast as possible
}

void plot::realtimeDataSlotTest(void){

    static QTime time(QTime::currentTime());

    double key = time.elapsed()/1000.0; //time elapse since start of measurment (in seconds)
    static double lastPointKey = 0;

    //at most add point every 2ms
    double value = new_value;
    if (key-lastPointKey>0.002){
        //use self-defined data for testing
        customPlot->graph(0)->addData(key, value);
        lastPointKey = key;
    }

    //make xAxis range scoll with the data(at constant xRangeSize)
    customPlot->xAxis->setRange(key, xRangeSize, Qt::AlignRight);
    customPlot->replot();
}

void plot::realtimeDataSlot(quint16 new_value){

    static QTime time(QTime::currentTime());

    double key = time.elapsed()/1000.0; //time elapse since start of measurment (in seconds)
    static double lastPointKey = 0;

    //at most add point every 2ms
    //quint16 value = new_value;
    if (key-lastPointKey>0.002){
        //use self-defined data for testing
        customPlot->graph(0)->addData(key, new_value);
        lastPointKey = key;
    }

    //make xAxis range scoll with the data(at constant xRangeSize)
    customPlot->xAxis->setRange(key, xRangeSize, Qt::AlignRight);
    customPlot->replot();
}

