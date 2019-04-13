/********************************************************************************
** Form generated from reading UI file 'entertainmentGroupConnectDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERTAINMENTGROUPCONNECTDIALOG_H
#define UI_ENTERTAINMENTGROUPCONNECTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EntertainmentGroupConnectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QListView *list_groups;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttons_bottom;

    void setupUi(QDialog *EntertainmentGroupConnectDialog)
    {
        if (EntertainmentGroupConnectDialog->objectName().isEmpty())
            EntertainmentGroupConnectDialog->setObjectName(QStringLiteral("EntertainmentGroupConnectDialog"));
        EntertainmentGroupConnectDialog->resize(400, 305);
        verticalLayout = new QVBoxLayout(EntertainmentGroupConnectDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(EntertainmentGroupConnectDialog);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(EntertainmentGroupConnectDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        list_groups = new QListView(EntertainmentGroupConnectDialog);
        list_groups->setObjectName(QStringLiteral("list_groups"));

        verticalLayout->addWidget(list_groups);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttons_bottom = new QDialogButtonBox(EntertainmentGroupConnectDialog);
        buttons_bottom->setObjectName(QStringLiteral("buttons_bottom"));
        buttons_bottom->setStandardButtons(QDialogButtonBox::Cancel);

        verticalLayout->addWidget(buttons_bottom);


        retranslateUi(EntertainmentGroupConnectDialog);
        QObject::connect(buttons_bottom, SIGNAL(clicked(QAbstractButton*)), EntertainmentGroupConnectDialog, SLOT(bottomButtonClicked(QAbstractButton*)));

        QMetaObject::connectSlotsByName(EntertainmentGroupConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *EntertainmentGroupConnectDialog)
    {
        EntertainmentGroupConnectDialog->setWindowTitle(QApplication::translate("EntertainmentGroupConnectDialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("EntertainmentGroupConnectDialog", "Select an entertainment group", Q_NULLPTR));
        label->setProperty("class", QVariant(QApplication::translate("EntertainmentGroupConnectDialog", "header", Q_NULLPTR)));
        label_2->setText(QApplication::translate("EntertainmentGroupConnectDialog", "It appears you have multiple entertainment groups. Please select the group to control below.", Q_NULLPTR));
        label_2->setProperty("class", QVariant(QApplication::translate("EntertainmentGroupConnectDialog", "footer", Q_NULLPTR)));
    } // retranslateUi

};

namespace Ui {
    class EntertainmentGroupConnectDialog: public Ui_EntertainmentGroupConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERTAINMENTGROUPCONNECTDIALOG_H
