#pragma once

#include <QDialog>
#include <QVariant>
#include <QSettings>
#include <QWidget>
#include <QSpinBox>
#include <QSlider>

#include <vector>
#include <utility>

#include "ui_optionsDialog.h"

class OptionsDialog : public QDialog, public Ui_OptionsDialog
{
	Q_OBJECT;

public:
	OptionsDialog(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

	void load();
	void save();

protected slots:
	void bottomButtonPressed(QAbstractButton *button);

private:
	void load(QWidget *widget, QString optionName);
	void save(QWidget *widget, QString optionName);
	void checkAndSave(QWidget *widget, QString optionName);
	void setValue(QWidget *widget, QVariant value);
	void setValue(QSpinBox *spinbox, QVariant value);
	void setValue(QSlider *slider, QVariant value);

	bool getValue(QSpinBox *spinBox, QVariant &value);
	bool getValue(QSlider *slider, QVariant &value);

	QVariant getValue(QWidget *widget);

	std::vector<std::pair<QWidget *, QString>> getOptionWidgets() const;
};
