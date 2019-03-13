#include "Application.h"
#include <QApplication>
#include <QDockWidget>
#include <QSerialPortInfo>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication qa(argc, argv);

	new Application();

	return qa.exec();
}
