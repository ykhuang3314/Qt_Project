/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRun;
    QAction *actionPause;
    QAction *actionSave;
    QAction *actionDelete;
    QAction *actionExit_Program;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *comboBox_spich;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QComboBox *comboBox_fsclk;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_spisetup;
    QLabel *label_spi;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox_fH;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *comboBox_fL;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QComboBox *comboBox_fdsp;
    QPushButton *pushButton_BW;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_REG_Config;
    QLabel *label_6;
    QLineEdit *lineEdit;
    QPushButton *ReadREG;
    QPushButton *pushButton_Show_REG;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_ADC_Cal;
    QPushButton *pushButton_Clear_Cal;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPlainTextEdit *plainTextEdit_test;
    QWidget *tab_2;
    QCustomPlot *plot_ch1;
    QCustomPlot *plot_ch2;
    QLabel *label_showdata;
    QMenuBar *menuBar;
    QMenu *menuMeasurement;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1140, 798);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/rec/img/run_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/rec/img/pause_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/rec/img/save_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName(QString::fromUtf8("actionDelete"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/rec/img/clear_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon3);
        actionExit_Program = new QAction(MainWindow);
        actionExit_Program->setObjectName(QString::fromUtf8("actionExit_Program"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/rec/img/exit_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit_Program->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_8 = new QHBoxLayout(groupBox_2);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        comboBox_spich = new QComboBox(groupBox_2);
        comboBox_spich->setObjectName(QString::fromUtf8("comboBox_spich"));

        horizontalLayout->addWidget(comboBox_spich);


        horizontalLayout_8->addLayout(horizontalLayout);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        comboBox_fsclk = new QComboBox(groupBox_2);
        comboBox_fsclk->setObjectName(QString::fromUtf8("comboBox_fsclk"));

        horizontalLayout_6->addWidget(comboBox_fsclk);


        horizontalLayout_8->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        pushButton_spisetup = new QPushButton(groupBox_2);
        pushButton_spisetup->setObjectName(QString::fromUtf8("pushButton_spisetup"));

        horizontalLayout_7->addWidget(pushButton_spisetup);

        label_spi = new QLabel(groupBox_2);
        label_spi->setObjectName(QString::fromUtf8("label_spi"));

        horizontalLayout_7->addWidget(label_spi);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_9 = new QHBoxLayout(groupBox);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        comboBox_fH = new QComboBox(groupBox);
        comboBox_fH->setObjectName(QString::fromUtf8("comboBox_fH"));

        horizontalLayout_2->addWidget(comboBox_fH);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        comboBox_fL = new QComboBox(groupBox);
        comboBox_fL->setObjectName(QString::fromUtf8("comboBox_fL"));

        horizontalLayout_3->addWidget(comboBox_fL);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        comboBox_fdsp = new QComboBox(groupBox);
        comboBox_fdsp->setObjectName(QString::fromUtf8("comboBox_fdsp"));

        horizontalLayout_5->addWidget(comboBox_fdsp);

        pushButton_BW = new QPushButton(groupBox);
        pushButton_BW->setObjectName(QString::fromUtf8("pushButton_BW"));

        horizontalLayout_5->addWidget(pushButton_BW);


        horizontalLayout_4->addLayout(horizontalLayout_5);


        horizontalLayout_9->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(groupBox);

        groupBox_3 = new QGroupBox(tab);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_3);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        pushButton_REG_Config = new QPushButton(groupBox_3);
        pushButton_REG_Config->setObjectName(QString::fromUtf8("pushButton_REG_Config"));

        horizontalLayout_10->addWidget(pushButton_REG_Config);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_10->addWidget(label_6);

        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_10->addWidget(lineEdit);

        ReadREG = new QPushButton(groupBox_3);
        ReadREG->setObjectName(QString::fromUtf8("ReadREG"));

        horizontalLayout_10->addWidget(ReadREG);

        pushButton_Show_REG = new QPushButton(groupBox_3);
        pushButton_Show_REG->setObjectName(QString::fromUtf8("pushButton_Show_REG"));

        horizontalLayout_10->addWidget(pushButton_Show_REG);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        pushButton_ADC_Cal = new QPushButton(groupBox_3);
        pushButton_ADC_Cal->setObjectName(QString::fromUtf8("pushButton_ADC_Cal"));

        horizontalLayout_10->addWidget(pushButton_ADC_Cal);

        pushButton_Clear_Cal = new QPushButton(groupBox_3);
        pushButton_Clear_Cal->setObjectName(QString::fromUtf8("pushButton_Clear_Cal"));

        horizontalLayout_10->addWidget(pushButton_Clear_Cal);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_11 = new QHBoxLayout(groupBox_4);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        pushButton_2 = new QPushButton(groupBox_4);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_11->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_11->addWidget(pushButton_3);


        verticalLayout_2->addWidget(groupBox_4);

        plainTextEdit_test = new QPlainTextEdit(tab);
        plainTextEdit_test->setObjectName(QString::fromUtf8("plainTextEdit_test"));

        verticalLayout_2->addWidget(plainTextEdit_test);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        plot_ch1 = new QCustomPlot(tab_2);
        plot_ch1->setObjectName(QString::fromUtf8("plot_ch1"));
        plot_ch1->setGeometry(QRect(10, 20, 381, 151));
        plot_ch2 = new QCustomPlot(tab_2);
        plot_ch2->setObjectName(QString::fromUtf8("plot_ch2"));
        plot_ch2->setGeometry(QRect(10, 210, 381, 151));
        label_showdata = new QLabel(tab_2);
        label_showdata->setObjectName(QString::fromUtf8("label_showdata"));
        label_showdata->setGeometry(QRect(440, 90, 84, 21));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1140, 26));
        menuMeasurement = new QMenu(menuBar);
        menuMeasurement->setObjectName(QString::fromUtf8("menuMeasurement"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMeasurement->menuAction());
        menuMeasurement->addAction(actionRun);
        menuMeasurement->addAction(actionPause);
        menuMeasurement->addAction(actionSave);
        menuMeasurement->addAction(actionDelete);
        menuMeasurement->addSeparator();
        menuMeasurement->addAction(actionExit_Program);
        mainToolBar->addAction(actionRun);
        mainToolBar->addAction(actionPause);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionDelete);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionExit_Program);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionRun->setText(QApplication::translate("MainWindow", "Run", nullptr));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionDelete->setText(QApplication::translate("MainWindow", "Delete", nullptr));
        actionExit_Program->setText(QApplication::translate("MainWindow", "Exit Program", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "SPI ", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Channel: ", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Clock Frequency:", nullptr));
        pushButton_spisetup->setText(QApplication::translate("MainWindow", "Setup", nullptr));
        label_spi->setText(QApplication::translate("MainWindow", "SPI status: ", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "Bandwidth ", nullptr));
        label->setText(QApplication::translate("MainWindow", "Upper Bandwidth:", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Lower Bandwidth:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "DSP Cutoff:", nullptr));
        pushButton_BW->setText(QApplication::translate("MainWindow", "Set", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "RAM Registers / ADC Calibration", nullptr));
        pushButton_REG_Config->setText(QApplication::translate("MainWindow", "RAM REG Config.", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Address: ", nullptr));
        ReadREG->setText(QApplication::translate("MainWindow", "Read Value", nullptr));
        pushButton_Show_REG->setText(QApplication::translate("MainWindow", "Show All", nullptr));
        pushButton_ADC_Cal->setText(QApplication::translate("MainWindow", "Run ADC Calibraition", nullptr));
        pushButton_Clear_Cal->setText(QApplication::translate("MainWindow", "Clear Calibraion", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Communication Testing", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "WRITE", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "READ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Configuration", nullptr));
        label_showdata->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Plot", nullptr));
        menuMeasurement->setTitle(QApplication::translate("MainWindow", "Measurement", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
