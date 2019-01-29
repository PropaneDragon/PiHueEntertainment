#pragma once

#include <QMainWindow>

class QLabel;
class StartWindow : public QMainWindow
{
public:
	StartWindow(QWidget *parent = nullptr, Qt::WindowFlags flags = Qt::WindowFlags());

	virtual void showEvent(QShowEvent *event) override;

private:
	QLabel *_previewImage = nullptr;

};