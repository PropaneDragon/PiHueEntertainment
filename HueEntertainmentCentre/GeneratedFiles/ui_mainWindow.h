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
    QAction *actionChangeHub;
    QAction *actionChangeCamera;
    QAction *actionOptions;
    QAction *actionUpdate_image;
    QAction *actionRotate_90_clockwise;
    QAction *actionRotate_90_anti_clockwise;
    QAction *actionFlip_horizontal;
    QAction *actionFlip_vertical;
    QAction *actionPerformance;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_cameraImage;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHuib;
    QMenu *menuCamera;
    QMenu *menuDisplay;
    QMenu *menuSettings;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setToolTipDuration(-5);
        MainWindow->setStyleSheet(QLatin1String("QWidget, QMenuBar::item {\n"
"	font-family: \"Segoe UI\", sans-serif;\n"
"	font-size: 9pt;\n"
"\n"
"	color: #fff;\n"
"	background-color: #333;\n"
"\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QWidget::pressed {\n"
"	background-color: rgba(255, 255, 255, 10);\n"
"}\n"
"\n"
"QComboBox, QTextBox, QAbstractButton, QSpinBox, QScrollArea, QProgressBar, QListView {\n"
"	border: 1px solid rgba(255, 255, 255, 40);\n"
"}\n"
"\n"
"QAbstractButton {\n"
"	padding: 8px;\n"
"	min-width: 50px;\n"
"}\n"
"\n"
"QAbstractButton::hover, QMenuBar::item:hover, QMenuBar::item:selected, QMenu::item:hover, QMenu::item:selected {\n"
"	background-color: rgba(255, 255, 255, 30);\n"
"}\n"
"\n"
"QMenuBar, QMenu {\n"
"	padding: 4px;\n"
"}\n"
"\n"
"QMenuBar::item, QMenu::item {\n"
"	padding: 8px;\n"
"	background: transparent;\n"
"}\n"
"\n"
"QMenu::item {\n"
"	padding-left: 16px;\n"
"}\n"
"\n"
".header {\n"
"	font-size: 12pt;\n"
"	color: rgba(255,255,255,200);\n"
"}\n"
"\n"
".subheader {\n"
"	font-size: 10pt;\n"
"}\n"
"\n"
".footer, QMenuBar, QMen"
                        "u {\n"
"	background-color: rgba(255, 255, 255, 20);\n"
"	border: 1px solid rgba(255, 255, 255, 20);\n"
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
        actionChangeHub = new QAction(MainWindow);
        actionChangeHub->setObjectName(QStringLiteral("actionChangeHub"));
        actionChangeCamera = new QAction(MainWindow);
        actionChangeCamera->setObjectName(QStringLiteral("actionChangeCamera"));
        actionChangeCamera->setEnabled(false);
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionOptions->setEnabled(true);
        actionUpdate_image = new QAction(MainWindow);
        actionUpdate_image->setObjectName(QStringLiteral("actionUpdate_image"));
        actionUpdate_image->setCheckable(true);
        actionUpdate_image->setChecked(true);
        actionRotate_90_clockwise = new QAction(MainWindow);
        actionRotate_90_clockwise->setObjectName(QStringLiteral("actionRotate_90_clockwise"));
        actionRotate_90_clockwise->setEnabled(true);
        actionRotate_90_anti_clockwise = new QAction(MainWindow);
        actionRotate_90_anti_clockwise->setObjectName(QStringLiteral("actionRotate_90_anti_clockwise"));
        actionRotate_90_anti_clockwise->setEnabled(true);
        actionFlip_horizontal = new QAction(MainWindow);
        actionFlip_horizontal->setObjectName(QStringLiteral("actionFlip_horizontal"));
        actionFlip_horizontal->setCheckable(true);
        actionFlip_vertical = new QAction(MainWindow);
        actionFlip_vertical->setObjectName(QStringLiteral("actionFlip_vertical"));
        actionFlip_vertical->setCheckable(true);
        actionPerformance = new QAction(MainWindow);
        actionPerformance->setObjectName(QStringLiteral("actionPerformance"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_cameraImage = new QLabel(widget);
        label_cameraImage->setObjectName(QStringLiteral("label_cameraImage"));
        label_cameraImage->setScaledContents(true);

        horizontalLayout->addWidget(label_cameraImage);


        verticalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 42));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHuib = new QMenu(menubar);
        menuHuib->setObjectName(QStringLiteral("menuHuib"));
        menuCamera = new QMenu(menubar);
        menuCamera->setObjectName(QStringLiteral("menuCamera"));
        menuDisplay = new QMenu(menubar);
        menuDisplay->setObjectName(QStringLiteral("menuDisplay"));
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuHuib->menuAction());
        menubar->addAction(menuCamera->menuAction());
        menubar->addAction(menuDisplay->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuHuib->addAction(actionConnectHub);
        menuHuib->addAction(actionDisconnectHub);
        menuHuib->addSeparator();
        menuHuib->addAction(actionChangeHub);
        menuCamera->addAction(actionConnectCamera);
        menuCamera->addAction(actionDisconnectCamera);
        menuCamera->addSeparator();
        menuCamera->addAction(actionChangeCamera);
        menuDisplay->addAction(actionUpdate_image);
        menuDisplay->addSeparator();
        menuDisplay->addAction(actionRotate_90_clockwise);
        menuDisplay->addAction(actionRotate_90_anti_clockwise);
        menuDisplay->addSeparator();
        menuDisplay->addAction(actionFlip_horizontal);
        menuDisplay->addAction(actionFlip_vertical);
        menuSettings->addAction(actionOptions);
        menuSettings->addAction(actionPerformance);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionConnectCamera, SIGNAL(triggered()), MainWindow, SLOT(connectToCamera()));
        QObject::connect(actionConnectHub, SIGNAL(triggered()), MainWindow, SLOT(connectToBridge()));
        QObject::connect(actionDisconnectCamera, SIGNAL(triggered()), MainWindow, SLOT(disconnectFromCamera()));
        QObject::connect(actionDisconnectHub, SIGNAL(triggered()), MainWindow, SLOT(disconnectFromBridge()));
        QObject::connect(actionChangeHub, SIGNAL(triggered()), MainWindow, SLOT(connectToNewBridge()));
        QObject::connect(actionChangeCamera, SIGNAL(triggered()), MainWindow, SLOT(connectToNewCamera()));
        QObject::connect(actionUpdate_image, SIGNAL(toggled(bool)), MainWindow, SLOT(changeImageUpdatePreference(bool)));
        QObject::connect(actionRotate_90_clockwise, SIGNAL(triggered()), MainWindow, SLOT(rotateImageClockwise()));
        QObject::connect(actionRotate_90_anti_clockwise, SIGNAL(triggered()), MainWindow, SLOT(rotateImageAntiClockwise()));
        QObject::connect(actionFlip_horizontal, SIGNAL(toggled(bool)), MainWindow, SLOT(flipImageHorizontal(bool)));
        QObject::connect(actionFlip_vertical, SIGNAL(toggled(bool)), MainWindow, SLOT(flipImageVertical(bool)));
        QObject::connect(actionOptions, SIGNAL(triggered()), MainWindow, SLOT(showOptions()));
        QObject::connect(actionPerformance, SIGNAL(triggered()), MainWindow, SLOT(showPerformance()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "PHE", Q_NULLPTR));
        actionExit->setText(QApplication::translate("MainWindow", "Close", Q_NULLPTR));
        actionDisconnectHub->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        actionConnectHub->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        actionConnectCamera->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        actionDisconnectCamera->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        actionChangeHub->setText(QApplication::translate("MainWindow", "Change", Q_NULLPTR));
        actionChangeCamera->setText(QApplication::translate("MainWindow", "Change", Q_NULLPTR));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        actionUpdate_image->setText(QApplication::translate("MainWindow", "Update image", Q_NULLPTR));
        actionRotate_90_clockwise->setText(QApplication::translate("MainWindow", "Rotate 90\302\260 clockwise", Q_NULLPTR));
        actionRotate_90_anti_clockwise->setText(QApplication::translate("MainWindow", "Rotate 90\302\260 anti-clockwise", Q_NULLPTR));
        actionFlip_horizontal->setText(QApplication::translate("MainWindow", "Flip horizontal", Q_NULLPTR));
        actionFlip_vertical->setText(QApplication::translate("MainWindow", "Flip vertical", Q_NULLPTR));
        actionPerformance->setText(QApplication::translate("MainWindow", "Performance", Q_NULLPTR));
        label_cameraImage->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
        menuHuib->setTitle(QApplication::translate("MainWindow", "Hub", Q_NULLPTR));
        menuCamera->setTitle(QApplication::translate("MainWindow", "Camera", Q_NULLPTR));
        menuDisplay->setTitle(QApplication::translate("MainWindow", "Display", Q_NULLPTR));
        menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
