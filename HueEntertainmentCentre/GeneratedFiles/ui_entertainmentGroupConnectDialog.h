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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EntertainmentGroupConnectDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QListView *list_groups;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QDialogButtonBox *buttons_bottom;

    void setupUi(QDialog *EntertainmentGroupConnectDialog)
    {
        if (EntertainmentGroupConnectDialog->objectName().isEmpty())
            EntertainmentGroupConnectDialog->setObjectName(QStringLiteral("EntertainmentGroupConnectDialog"));
        EntertainmentGroupConnectDialog->resize(605, 433);
        EntertainmentGroupConnectDialog->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(EntertainmentGroupConnectDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(EntertainmentGroupConnectDialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setWordWrap(true);

        verticalLayout_3->addWidget(label);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setWordWrap(true);

        verticalLayout_3->addWidget(label_2);

        list_groups = new QListView(widget_2);
        list_groups->setObjectName(QStringLiteral("list_groups"));

        verticalLayout_3->addWidget(list_groups);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(EntertainmentGroupConnectDialog);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        buttons_bottom = new QDialogButtonBox(widget);
        buttons_bottom->setObjectName(QStringLiteral("buttons_bottom"));
        buttons_bottom->setStandardButtons(QDialogButtonBox::Cancel);

        verticalLayout_2->addWidget(buttons_bottom);


        verticalLayout->addWidget(widget);


        retranslateUi(EntertainmentGroupConnectDialog);
        QObject::connect(buttons_bottom, SIGNAL(clicked(QAbstractButton*)), EntertainmentGroupConnectDialog, SLOT(bottomButtonClicked(QAbstractButton*)));

        QMetaObject::connectSlotsByName(EntertainmentGroupConnectDialog);
    } // setupUi

    void retranslateUi(QDialog *EntertainmentGroupConnectDialog)
    {
        EntertainmentGroupConnectDialog->setWindowTitle(QApplication::translate("EntertainmentGroupConnectDialog", "Select an entertainment area", Q_NULLPTR));
        label->setText(QApplication::translate("EntertainmentGroupConnectDialog", "Select an entertainment area", Q_NULLPTR));
        label->setProperty("class", QVariant(QApplication::translate("EntertainmentGroupConnectDialog", "header", Q_NULLPTR)));
        label_2->setText(QApplication::translate("EntertainmentGroupConnectDialog", "It appears you have multiple entertainment areas. Please select the area to control below.", Q_NULLPTR));
        label_2->setProperty("class", QVariant(QApplication::translate("EntertainmentGroupConnectDialog", "subheader", Q_NULLPTR)));
        widget->setProperty("class", QVariant(QApplication::translate("EntertainmentGroupConnectDialog", "footer", Q_NULLPTR)));
    } // retranslateUi

};

namespace Ui {
    class EntertainmentGroupConnectDialog: public Ui_EntertainmentGroupConnectDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERTAINMENTGROUPCONNECTDIALOG_H
