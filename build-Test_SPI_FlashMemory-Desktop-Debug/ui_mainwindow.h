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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_ID;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox_spich;
    QLabel *label_3;
    QLineEdit *lineEdit_fSCLK;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QRadioButton *radioButton_DISWR;
    QRadioButton *radioButton_ENWR;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_updatestatus;
    QPushButton *pushButton_StatusReg;
    QLineEdit *lineEdit_status;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_nums;
    QPushButton *pushButton_Read;
    QPushButton *pushButton_Write;
    QPlainTextEdit *plainTextEdit_output;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1072, 708);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/rec/exit_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        horizontalLayout_5 = new QHBoxLayout(groupBox_3);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_5->addWidget(pushButton_2);

        lineEdit_ID = new QLineEdit(groupBox_3);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));

        horizontalLayout_5->addWidget(lineEdit_ID);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox_spich = new QComboBox(groupBox);
        comboBox_spich->setObjectName(QString::fromUtf8("comboBox_spich"));

        horizontalLayout->addWidget(comboBox_spich);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);


        horizontalLayout_2->addLayout(horizontalLayout);

        lineEdit_fSCLK = new QLineEdit(groupBox);
        lineEdit_fSCLK->setObjectName(QString::fromUtf8("lineEdit_fSCLK"));

        horizontalLayout_2->addWidget(lineEdit_fSCLK);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_2);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        radioButton_DISWR = new QRadioButton(groupBox_2);
        radioButton_DISWR->setObjectName(QString::fromUtf8("radioButton_DISWR"));

        verticalLayout->addWidget(radioButton_DISWR);

        radioButton_ENWR = new QRadioButton(groupBox_2);
        radioButton_ENWR->setObjectName(QString::fromUtf8("radioButton_ENWR"));

        verticalLayout->addWidget(radioButton_ENWR);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_updatestatus = new QPushButton(groupBox_2);
        pushButton_updatestatus->setObjectName(QString::fromUtf8("pushButton_updatestatus"));

        verticalLayout_2->addWidget(pushButton_updatestatus);

        pushButton_StatusReg = new QPushButton(groupBox_2);
        pushButton_StatusReg->setObjectName(QString::fromUtf8("pushButton_StatusReg"));

        verticalLayout_2->addWidget(pushButton_StatusReg);


        horizontalLayout_4->addLayout(verticalLayout_2);

        lineEdit_status = new QLineEdit(groupBox_2);
        lineEdit_status->setObjectName(QString::fromUtf8("lineEdit_status"));

        horizontalLayout_4->addWidget(lineEdit_status);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_4);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        lineEdit_nums = new QLineEdit(groupBox_4);
        lineEdit_nums->setObjectName(QString::fromUtf8("lineEdit_nums"));

        horizontalLayout_6->addWidget(lineEdit_nums);

        pushButton_Read = new QPushButton(groupBox_4);
        pushButton_Read->setObjectName(QString::fromUtf8("pushButton_Read"));

        horizontalLayout_6->addWidget(pushButton_Read);

        pushButton_Write = new QPushButton(groupBox_4);
        pushButton_Write->setObjectName(QString::fromUtf8("pushButton_Write"));

        horizontalLayout_6->addWidget(pushButton_Write);


        verticalLayout_3->addWidget(groupBox_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        plainTextEdit_output = new QPlainTextEdit(centralWidget);
        plainTextEdit_output->setObjectName(QString::fromUtf8("plainTextEdit_output"));

        verticalLayout_4->addWidget(plainTextEdit_output);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1072, 26));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addAction(actionExit);
        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Identification", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Device ID", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "SPI", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Channel:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Speed:", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Setup", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Status Register", nullptr));
        label->setText(QApplication::translate("MainWindow", "Write", nullptr));
        radioButton_DISWR->setText(QApplication::translate("MainWindow", "Disable", nullptr));
        radioButton_ENWR->setText(QApplication::translate("MainWindow", "Enable", nullptr));
        pushButton_updatestatus->setText(QApplication::translate("MainWindow", "Update", nullptr));
        pushButton_StatusReg->setText(QApplication::translate("MainWindow", "Show Status", nullptr));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Memory Read/Write Test", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "Num of bytes:", nullptr));
        pushButton_Read->setText(QApplication::translate("MainWindow", "Read", nullptr));
        pushButton_Write->setText(QApplication::translate("MainWindow", "Write", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
