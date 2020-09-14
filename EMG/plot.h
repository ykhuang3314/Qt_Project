#ifndef PLOT_H
#define PLOT_H

#include <QObject>
#include "qcustomplot.h"
#include <QString>
#include <QTimer>

class plot : public QObject
{
    Q_OBJECT
public:
    explicit plot(QCustomPlot *customPlot=nullptr, QObject *parent = nullptr);
    void set_xRangeSize(double size);
    void set_yAxis(double min, double max);
    void setAxisName(const QString &xAxis, const QString &yAxis);
    void RealTimePlotting(void);


signals:

public slots:
    void realtimeDataSlot(quint16 new_value);
    void realtimeDataSlotTest(void);
    void getValue(quint16 data);

private:
    QString xAxisName;
    QString yAxisName;
    double xRangeSize;
    double minY;
    double maxY;
    QTimer dataTimer;
    QCustomPlot *customPlot;
    quint16 new_value;
};

#endif // PLOT_H
