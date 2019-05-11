/********************************************************************************
** Form generated from reading UI file 'updateDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATEDIALOG_H
#define UI_UPDATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UpdateDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttons_bottom;

    void setupUi(QDialog *UpdateDialog)
    {
        if (UpdateDialog->objectName().isEmpty())
            UpdateDialog->setObjectName(QStringLiteral("UpdateDialog"));
        UpdateDialog->resize(392, 118);
        verticalLayout = new QVBoxLayout(UpdateDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QWidget(UpdateDialog);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setWordWrap(true);

        verticalLayout_2->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setWordWrap(true);

        verticalLayout_2->addWidget(label_2);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(widget);

        buttons_bottom = new QDialogButtonBox(UpdateDialog);
        buttons_bottom->setObjectName(QStringLiteral("buttons_bottom"));
        buttons_bottom->setStandardButtons(QDialogButtonBox::Cancel);

        verticalLayout->addWidget(buttons_bottom);


        retranslateUi(UpdateDialog);
        QObject::connect(buttons_bottom, SIGNAL(accepted()), UpdateDialog, SLOT(accept()));
        QObject::connect(buttons_bottom, SIGNAL(rejected()), UpdateDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(UpdateDialog);
    } // setupUi

    void retranslateUi(QDialog *UpdateDialog)
    {
        UpdateDialog->setWindowTitle(QApplication::translate("UpdateDialog", "Update available", Q_NULLPTR));
        label->setText(QApplication::translate("UpdateDialog", "Update available", Q_NULLPTR));
        label->setProperty("class", QVariant(QApplication::translate("UpdateDialog", "header", Q_NULLPTR)));
        label_2->setText(QApplication::translate("UpdateDialog", "There's a new update available to download. Would you like to download the update now?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UpdateDialog: public Ui_UpdateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATEDIALOG_H
