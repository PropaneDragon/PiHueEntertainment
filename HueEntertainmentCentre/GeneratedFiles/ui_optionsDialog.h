/********************************************************************************
** Form generated from reading UI file 'optionsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONSDIALOG_H
#define UI_OPTIONSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OptionsDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QLabel *label_5;
    QSlider *horizontalSlider_2;
    QLabel *label_6;
    QSlider *slider_maxBrightness;
    QLabel *label_7;
    QSlider *slider_minBrightness;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QDialogButtonBox *buttons_bottom;

    void setupUi(QDialog *OptionsDialog)
    {
        if (OptionsDialog->objectName().isEmpty())
            OptionsDialog->setObjectName(QStringLiteral("OptionsDialog"));
        OptionsDialog->resize(362, 372);
        OptionsDialog->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(OptionsDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_2 = new QWidget(OptionsDialog);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setStyleSheet(QStringLiteral(""));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, -1, -1, 9);
        label = new QLabel(widget_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setWordWrap(true);

        verticalLayout_2->addWidget(label);

        scrollArea = new QScrollArea(widget_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::StyledPanel);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 342, 292));
        formLayout_2 = new QFormLayout(scrollAreaWidgetContents);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setRowWrapPolicy(QFormLayout::DontWrapRows);
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setWordWrap(true);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(10);
        spinBox->setMaximum(999999999);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinBox);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setWordWrap(true);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_4);

        spinBox_2 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(120);
        spinBox_2->setValue(30);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, spinBox_2);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setWordWrap(true);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        horizontalSlider = new QSlider(scrollAreaWidgetContents);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMaximum(20);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedAppearance(false);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        horizontalSlider->setTickInterval(2);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, horizontalSlider);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setWordWrap(true);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_5);

        horizontalSlider_2 = new QSlider(scrollAreaWidgetContents);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(50);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setInvertedAppearance(false);
        horizontalSlider_2->setTickPosition(QSlider::TicksAbove);
        horizontalSlider_2->setTickInterval(5);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, horizontalSlider_2);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setWordWrap(true);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_6);

        slider_maxBrightness = new QSlider(scrollAreaWidgetContents);
        slider_maxBrightness->setObjectName(QStringLiteral("slider_maxBrightness"));
        slider_maxBrightness->setMaximum(100);
        slider_maxBrightness->setValue(100);
        slider_maxBrightness->setOrientation(Qt::Horizontal);
        slider_maxBrightness->setInvertedAppearance(false);
        slider_maxBrightness->setTickPosition(QSlider::TicksAbove);
        slider_maxBrightness->setTickInterval(5);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, slider_maxBrightness);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setWordWrap(true);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_7);

        slider_minBrightness = new QSlider(scrollAreaWidgetContents);
        slider_minBrightness->setObjectName(QStringLiteral("slider_minBrightness"));
        slider_minBrightness->setMaximum(100);
        slider_minBrightness->setValue(0);
        slider_minBrightness->setOrientation(Qt::Horizontal);
        slider_minBrightness->setInvertedAppearance(false);
        slider_minBrightness->setTickPosition(QSlider::TicksAbove);
        slider_minBrightness->setTickInterval(5);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, slider_minBrightness);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        verticalLayout->addWidget(widget_2);

        widget = new QWidget(OptionsDialog);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(9, 9, 9, 9);
        buttons_bottom = new QDialogButtonBox(widget);
        buttons_bottom->setObjectName(QStringLiteral("buttons_bottom"));
        buttons_bottom->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttons_bottom);


        verticalLayout->addWidget(widget);


        retranslateUi(OptionsDialog);
        QObject::connect(buttons_bottom, SIGNAL(clicked(QAbstractButton*)), OptionsDialog, SLOT(bottomButtonPressed(QAbstractButton*)));
        QObject::connect(buttons_bottom, SIGNAL(rejected()), OptionsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(OptionsDialog);
    } // setupUi

    void retranslateUi(QDialog *OptionsDialog)
    {
        OptionsDialog->setWindowTitle(QApplication::translate("OptionsDialog", "Options", Q_NULLPTR));
        label->setText(QApplication::translate("OptionsDialog", "Options", Q_NULLPTR));
        label->setProperty("class", QVariant(QApplication::translate("OptionsDialog", "header", Q_NULLPTR)));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("OptionsDialog", "<html><head/><body><p>The processing resolution.</p><p>The higher this resolution, the more accurate the colour will be. This will increase processing time however.</p><p>Lower resolutions will perform better.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("OptionsDialog", "Camera capture resolution", Q_NULLPTR));
        spinBox->setSuffix(QApplication::translate("OptionsDialog", "px", Q_NULLPTR));
        spinBox->setProperty("option", QVariant(QApplication::translate("OptionsDialog", "camera/resolution", Q_NULLPTR)));
#ifndef QT_NO_TOOLTIP
        label_4->setToolTip(QApplication::translate("OptionsDialog", "<html><head/><body><p>The processing framerate.</p><p>The higher this framerate, the faster changes will appear on the lights. This drastically increases processing time however.</p><p>Lower framerates will perform better, but will result in a slower response time.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("OptionsDialog", "Camera capture framerate", Q_NULLPTR));
        spinBox_2->setSuffix(QApplication::translate("OptionsDialog", "fps", Q_NULLPTR));
        spinBox_2->setProperty("option", QVariant(QApplication::translate("OptionsDialog", "camera/framerate", Q_NULLPTR)));
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("OptionsDialog", "<html><head/><body><p>Specifies whether to change the light colour if the last light colour was similar.</p><p>The lower the value the lower the change limit which smooths light transitions, however very slight colour changes given by the camera will result in this being reflected in the lighting which could cause slight pulsing, even if the image is static.</p><p>Increasing this value limits the amount of low level pulsing given off by the camera, but will make smooth transitions jumpier.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("OptionsDialog", "Snapping level", Q_NULLPTR));
        horizontalSlider->setProperty("option", QVariant(QApplication::translate("OptionsDialog", "processing/snapping", Q_NULLPTR)));
#ifndef QT_NO_TOOLTIP
        label_5->setToolTip(QApplication::translate("OptionsDialog", "<html><head/><body><p>Smooths lighting changes out, so dramatic lighting changes given by the camera will be smoothed out and transitioned gradually.</p><p>Quick changes will be less dramatic at higher values.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_5->setText(QApplication::translate("OptionsDialog", "Smoothing level", Q_NULLPTR));
        horizontalSlider_2->setProperty("option", QVariant(QApplication::translate("OptionsDialog", "processing/smoothing", Q_NULLPTR)));
#ifndef QT_NO_TOOLTIP
        label_6->setToolTip(QApplication::translate("OptionsDialog", "<html><head/><body><p>The processing framerate.</p><p>The higher this framerate, the faster changes will appear on the lights. This drastically increases processing time however.</p><p>Lower framerates will perform better, but will result in a slower response time.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_6->setText(QApplication::translate("OptionsDialog", "Maximum brightness", Q_NULLPTR));
        slider_maxBrightness->setProperty("option", QVariant(QApplication::translate("OptionsDialog", "processing/maxBrightness", Q_NULLPTR)));
#ifndef QT_NO_TOOLTIP
        label_7->setToolTip(QApplication::translate("OptionsDialog", "<html><head/><body><p>The processing framerate.</p><p>The higher this framerate, the faster changes will appear on the lights. This drastically increases processing time however.</p><p>Lower framerates will perform better, but will result in a slower response time.</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("OptionsDialog", "Minimum brightness", Q_NULLPTR));
        slider_minBrightness->setProperty("option", QVariant(QApplication::translate("OptionsDialog", "processing/minBrightness", Q_NULLPTR)));
        widget->setProperty("class", QVariant(QApplication::translate("OptionsDialog", "footer", Q_NULLPTR)));
    } // retranslateUi

};

namespace Ui {
    class OptionsDialog: public Ui_OptionsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONSDIALOG_H
