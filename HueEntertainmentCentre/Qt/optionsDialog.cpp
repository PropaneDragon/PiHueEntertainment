#include <QAbstractButton>
#include <QPushButton>

#include "optionsDialog.h"

OptionsDialog::OptionsDialog(QWidget *parent, Qt::WindowFlags flags) : QDialog(parent, flags)
{
	setupUi(this);

	load();
}

void OptionsDialog::load()
{
	auto optionWidgets = getOptionWidgets();
	for (auto optionWidget : optionWidgets) {
		load(optionWidget.first, optionWidget.second);
	}
}

void OptionsDialog::save()
{
	auto optionWidgets = getOptionWidgets();
	for (auto optionWidget : optionWidgets) {
		save(optionWidget.first, optionWidget.second);
	}
}

void OptionsDialog::bottomButtonPressed(QAbstractButton *button)
{
	if (button == buttons_bottom->button(QDialogButtonBox::StandardButton::Apply)) {
		save();
	}
	else if (button == buttons_bottom->button(QDialogButtonBox::StandardButton::Ok)) {
		save();
		accept();
	}
}

void OptionsDialog::load(QWidget *widget, QString optionName)
{
	QSettings settings;
	if (settings.contains(optionName)) {

		auto value = settings.value(optionName);
		if (!value.isNull() && value.isValid()) {
			setValue(widget, value);
		}
	}
	else {
		save(widget, optionName);
	}
}

void OptionsDialog::save(QWidget *widget, QString optionName)
{
	checkAndSave(widget, optionName);
}

void OptionsDialog::checkAndSave(QWidget *widget, QString optionName)
{
	QVariant value = getValue(widget);
	if (!value.isNull() && value.isValid()) {

		QSettings settings;
		settings.setValue(optionName, value);
	}
}

void OptionsDialog::setValue(QWidget *widget, QVariant value)
{
	setValue(dynamic_cast<QSpinBox *>(widget), value);
	setValue(dynamic_cast<QSlider *>(widget), value);
}

void OptionsDialog::setValue(QSpinBox *spinbox, QVariant value)
{
	if (spinbox) {
		spinbox->setValue(value.toInt());
	}
}

void OptionsDialog::setValue(QSlider *slider, QVariant value)
{
	if (slider) {
		slider->setValue(value.toInt());
	}
}

QVariant OptionsDialog::getValue(QWidget *widget)
{
	QVariant variant;

	getValue(dynamic_cast<QSpinBox *>(widget), variant);
	getValue(dynamic_cast<QSlider *>(widget), variant);

	return variant;
}

bool OptionsDialog::getValue(QSpinBox *spinBox, QVariant &value)
{
	if (spinBox) {
		value = spinBox->value();
		return true;
	}

	return false;
}

bool OptionsDialog::getValue(QSlider *slider, QVariant &value)
{
	if (slider) {
		value = slider->value();
		return true;
	}

	return false;
}

std::vector<std::pair<QWidget *, QString>> OptionsDialog::getOptionWidgets() const
{
	std::vector<std::pair<QWidget *, QString>> widgets;

	auto children = scrollArea->findChildren<QWidget*>();
	for (auto child : children) {

		auto attachedOptionProperty = child->property("option");
		if (!attachedOptionProperty.isNull() && attachedOptionProperty.isValid() && attachedOptionProperty.type() == QVariant::Type::String) {

			auto optionName = attachedOptionProperty.toString();
			if (!optionName.isEmpty()) {

				widgets.push_back(std::pair<QWidget *, QString>(child, optionName));
			}
		}
	}

	return widgets;
}