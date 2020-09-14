#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sst26vf016b.h"
#include <QtGlobal>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_updatestatus_clicked();

    void on_pushButton_StatusReg_clicked();

private:
    Ui::MainWindow *ui;
    SST26VF016B *my_flashMem;
    int SPI_Ch;
};

#endif // MAINWINDOW_H
