/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionDisconnectHub;
    QAction *actionConnectHub;
    QAction *actionConnectCamera;
    QAction *actionDisconnectCamera;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_cameraImage;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHuib;
    QMenu *menuCamera;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setToolTipDuration(-5);
        MainWindow->setStyleSheet(QLatin1String(".header {\n"
"	font-size: 12pt;\n"
"	color: rgba(0,0,0,200);\n"
"}\n"
"\n"
"QWidget {\n"
"	font-family: \"Segoe UI\", sans-serif;\n"
"	font-size: 9pt;\n"
"}"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionDisconnectHub = new QAction(MainWindow);
        actionDisconnectHub->setObjectName(QStringLiteral("actionDisconnectHub"));
        actionConnectHub = new QAction(MainWindow);
        actionConnectHub->setObjectName(QStringLiteral("actionConnectHub"));
        actionConnectCamera = new QAction(MainWindow);
        actionConnectCamera->setObjectName(QStringLiteral("actionConnectCamera"));
        actionDisconnectCamera = new QAction(MainWindow);
        actionDisconnectCamera->setObjectName(QStringLiteral("actionDisconnectCamera"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_cameraImage = new QLabel(widget);
        label_cameraImage->setObjectName(QStringLiteral("label_cameraImage"));
        label_cameraImage->setScaledContents(true);

        horizontalLayout->addWidget(label_cameraImage);


        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHuib = new QMenu(menubar);
        menuHuib->setObjectName(QStringLiteral("menuHuib"));
        menuCamera = new QMenu(menubar);
        menuCamera->setObjectName(QStringLiteral("menuCamera"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHuib->menuAction());
        menubar->addAction(menuCamera->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHuib->addAction(actionConnectHub);
        menuHuib->addAction(actionDisconnectHub);
        menuCamera->addAction(actionConnectCamera);
        menuCamera->addAction(actionDisconnectCamera);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionConnectCamera, SIGNAL(triggered()), MainWindow, SLOT(connectToNewCamera()));
        QObject::connect(actionConnectHub, SIGNAL(triggered()), MainWindow, SLOT(connectToNewBridge()));
        QObject::connect(actionDisconnectCamera, SIGNAL(triggered()), MainWindow, SLOT(disconnectFromCamera()));
        QObject::connect(actionDisconnectHub, SIGNAL(triggered()), MainWindow, SLOT(disconnectFromBridge()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        actionDisconnectHub->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        actionConnectHub->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        actionConnectCamera->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        actionDisconnectCamera->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        label_cameraImage->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuHuib->setTitle(QApplication::translate("MainWindow", "Hub", Q_NULLPTR));
        menuCamera->setTitle(QApplication::translate("MainWindow", "Camera", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
