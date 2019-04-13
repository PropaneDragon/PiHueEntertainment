#pragma once

#include <QThread>

#include <functional>

class QThreadLambda : public QThread
{
public:
	QThreadLambda(QObject *parent = nullptr);
	QThreadLambda(std::function<void()> function, QObject *parent = nullptr);

	void run() override;
	void setFunction(std::function<void()> function);

private:
	std::function<void()> _function = nullptr;
};