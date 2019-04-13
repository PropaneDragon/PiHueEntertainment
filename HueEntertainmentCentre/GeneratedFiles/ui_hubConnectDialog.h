/********************************************************************************
** Form generated from reading UI file 'hubConnectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUBCONNECTDIALOG_H
#define UI_HUBCONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HubConnectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QProgressBar *progressBar;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *HubConnectDialog)
    {
        if (HubConnectDialog->objectName().isEmpty())
            HubConnectDialog->setObjectName(QStringLiteral("HubConnectDialog"));
        HubConnectDialog->resize(400, 273);
        verticalLayout = new QVBoxLayout(HubConnectDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(HubConnectDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(HubConnectDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        progressBar = new QProgressBar(HubConnectDialog);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setMaximum(0);
        progressBar->setValue(0);
        progressBar->setTextVisible(false);

        verticalLayout->addWidget(progressBar);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(HubConnectDialog);

        QMetaObject::connectSlotsByName(HubConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *HubConnectDialog)
    {
        HubConnectDialog->setWindowTitle(QApplication::translate("HubConnectDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("HubConnectDialog", "Connecting to hub", Q_NULLPTR));
        label->setProperty("class", QVariant(QApplication::translate("HubConnectDialog", "header", Q_NULLPTR)));
        label_2->setText(QApplication::translate("HubConnectDialog", "If this is your first time connecting, press the connect button in the centre of the Hue hub you wish to connect to now.", Q_NULLPTR));
        label_2->setProperty("class", QVariant(QApplication::translate("HubConnectDialog", "footer", Q_NULLPTR)));
    } // retranslateUi

};

namespace Ui {
    class HubConnectDialog: public Ui_HubConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUBCONNECTDIALOG_H
