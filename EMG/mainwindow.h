#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "rhd2132.h"
#include "plot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void display_data(quint16 data);

private slots:
    void on_actionExit_Program_triggered();

    void on_pushButton_spisetup_clicked();

    void on_pushButton_BW_clicked();

    void on_pushButton_ADC_Cal_clicked();

    void on_pushButton_Clear_Cal_clicked();

    void on_pushButton_REG_Config_clicked();

    void on_pushButton_Show_REG_clicked();

    void on_actionPause_triggered();

    void on_actionRun_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    RHD2132 *my_RHD2132;
    plot *channel1;
    plot *channel2;
    QTimer *plotting_timer;
    bool isPaused;
    QThread *thread;
};

#endif // MAINWINDOW_H
