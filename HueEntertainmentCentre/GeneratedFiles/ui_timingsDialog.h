/********************************************************************************
** Form generated from reading UI file 'timingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMINGSDIALOG_H
#define UI_TIMINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TimingsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTreeView *treeView;

    void setupUi(QDialog *TimingsDialog)
    {
        if (TimingsDialog->objectName().isEmpty())
            TimingsDialog->setObjectName(QStringLiteral("TimingsDialog"));
        TimingsDialog->resize(498, 584);
        verticalLayout = new QVBoxLayout(TimingsDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeView = new QTreeView(TimingsDialog);
        treeView->setObjectName(QStringLiteral("treeView"));

        verticalLayout->addWidget(treeView);


        retranslateUi(TimingsDialog);

        QMetaObject::connectSlotsByName(TimingsDialog);
    } // setupUi

    void retranslateUi(QDialog *TimingsDialog)
    {
        TimingsDialog->setWindowTitle(QApplication::translate("TimingsDialog", "Timings", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TimingsDialog: public Ui_TimingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMINGSDIALOG_H
