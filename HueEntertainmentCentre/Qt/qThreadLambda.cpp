#include "qThreadLambda.h"

QThreadLambda::QThreadLambda(QObject *parent) : QThread(parent)
{
}

QThreadLambda::QThreadLambda(std::function<void()> function, QObject *parent) : QThreadLambda(parent)
{
	setFunction(function);
}

void QThreadLambda::run()
{
	if (_function) {
		_function();
	}
}

void QThreadLambda::setFunction(std::function<void()> function)
{
	_function = function;
}
