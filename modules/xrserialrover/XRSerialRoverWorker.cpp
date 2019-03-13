#include "XRSerialRoverWorker.h"
#include "XRSerialRoverModule.h"
#include "XRSettings.h"
#include "XRLog.h"
#include "XRStatusBarSerialRoverStatus.h"
#include "XRMainWindow.h"
#include "XRApplication.h"
#include "XRUiManager.h"
#include <QVariant>
#include <QDataStream>

XR_MODULE(XRSerialRover)

XRSerialRoverWorker::XRSerialRoverWorker(XRSerialRoverModule *parent)
	: XRModuleWorker(parent)
	, m_serialPort(nullptr)
{
	m_settings = new XRSettings(this);
	m_serialPort = new QSerialPort(this);

	connect(app->uiManager(), SIGNAL(uiRegistered(const QString &, XRUi *)),
			this, SLOT(on_uiRegistered(const QString &, XRUi *))
			);
	connect(m_serialPort, SIGNAL(aboutToClose()), this, SLOT(on_aboutToClose()));
	connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
}

QString XRSerialRoverWorker::Name()
{
	return XRSerialRoverModule::Name();
}

QByteArray XRSerialRoverWorker::read(qint64 maxSize)
{
	if(isOpen())
		return m_serialPort->read(maxSize);

	return QByteArray();
}

QByteArray XRSerialRoverWorker::readAll()
{
	if(isOpen())
		return m_serialPort->readAll();

	return QByteArray();
}

void XRSerialRoverWorker::write(const QByteArray &data)
{
	emit aboutToWrite();
	m_serialPort->write(data);
	LOG_DEBUG("Writing " << data.size() << " bytes");
}

QString XRSerialRoverWorker::port() const
{
	return m_settings->getValue("XRSerialRover/Port").toString();
}

void XRSerialRoverWorker::setPort(const QString &port)
{
	bool reopen = false;

	if(isOpen()) {
		close();
		reopen = true;
	}

	m_settings->setValue("XRSerialRover/Port", port);
	m_serialPort->setPortName(port);

	if(reopen)
		open();
}

QSerialPort::BaudRate XRSerialRoverWorker::baudRate() const
{
	return static_cast<QSerialPort::BaudRate>(m_settings->getValue("XRSerialRover/BaudRate").toInt());
}

void XRSerialRoverWorker::setBaudRate(QSerialPort::BaudRate baudRate)
{
	m_settings->setValue("XRSerialRover/BaudRate", baudRate);
	QMetaObject::invokeMethod(m_serialPort, "setBaudRate", Qt::AutoConnection, Q_ARG(QSerialPort::BaudRate, baudRate));
}

QSerialPort::DataBits XRSerialRoverWorker::dataBits() const
{
	return static_cast<QSerialPort::DataBits>(m_settings->getValue("XRSerialRover/DataBits").toInt());
}

void XRSerialRoverWorker::setDataBits(QSerialPort::DataBits dataBits)
{
	m_settings->setValue("XRSerialRover/DataBits", dataBits);
	QMetaObject::invokeMethod(m_serialPort, "setDataBits", Qt::AutoConnection, Q_ARG(QSerialPort::DataBits, dataBits));
}

QSerialPort::FlowControl XRSerialRoverWorker::flowControl() const
{
	return static_cast<QSerialPort::FlowControl>(m_settings->getValue("XRSerialRover/FlowControl").toInt());
}

void XRSerialRoverWorker::setFlowControl(QSerialPort::FlowControl flowControl)
{
	m_settings->setValue("XRSerialRover/FlowControl", flowControl);
	QMetaObject::invokeMethod(m_serialPort, "setFlowControl", Qt::AutoConnection,
							  Q_ARG(QSerialPort::FlowControl, flowControl)
							  );
}

QSerialPort::Parity XRSerialRoverWorker::parity() const
{
	return static_cast<QSerialPort::Parity>(m_settings->getValue("XRSerialRover/Parity").toInt());
}

void XRSerialRoverWorker::setParity(QSerialPort::Parity parity)
{
	m_settings->setValue("XRSerialRover/Parity", parity);
	QMetaObject::invokeMethod(m_serialPort, "setParity", Qt::AutoConnection, Q_ARG(QSerialPort::Parity, parity));
}

QSerialPort::StopBits XRSerialRoverWorker::stopBits() const
{
	return static_cast<QSerialPort::StopBits>(m_settings->getValue("XRSerialRover/StopBits").toInt());
}

void XRSerialRoverWorker::setStopBits(QSerialPort::StopBits stopBits)
{
	m_settings->setValue("XRSerialRover/StopBits", stopBits);
	QMetaObject::invokeMethod(m_serialPort, "setStopBits", Qt::AutoConnection, Q_ARG(QSerialPort::StopBits, stopBits));
}

bool XRSerialRoverWorker::isOpen() const
{
	return m_serialPort->isOpen();
}

void XRSerialRoverWorker::open()
{
	if(!isOpen()) {
		m_serialPort->setPortName(port());
		m_serialPort->setBaudRate(baudRate());
		m_serialPort->setDataBits(dataBits());
		m_serialPort->setFlowControl(flowControl());
		m_serialPort->setParity(parity());
		m_serialPort->setStopBits(stopBits());

		m_serialPort->open(QIODevice::ReadWrite);
		if(isOpen()) {
			LOG_INFO("Serial port " << port() << " opened with " << baudRate() << ":" <<
					 dataBits() << flowControl() << parity() << stopBits()
					 );

			emit opened();
		}
		else {

			LOG_ERROR("Error opening serial port " << port() << ": " << m_serialPort->errorString());
		}
	}
}

void XRSerialRoverWorker::close()
{
	if(isOpen()) {
		m_serialPort->close();
		if(!isOpen()) {
			LOG_INFO("Closed");
			emit closed();
		}
		else
			LOG_ERROR("Close failed");
	}
}

void XRSerialRoverWorker::on_uiRegistered(const QString &name, XRUi *)
{
	if(name == XRMainWindow::Name()) {
		XRStatusBarSerialRoverStatus *status = new XRStatusBarSerialRoverStatus(this);
		status->show();
	}
}

void XRSerialRoverWorker::on_aboutToClose()
{
	emit aboutToClose();
}

void XRSerialRoverWorker::on_readyRead()
{
	emit readyRead();
}
