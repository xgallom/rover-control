#ifndef XRSERIALROVERWORKER_H
#define XRSERIALROVERWORKER_H

#include "XRModuleWorker.h"
#include <QSerialPort>

class XRSerialRoverModule;
class XRSettings;
class XRUi;

class XRSerialRoverWorker : public XRModuleWorker
{
	Q_OBJECT
public:
	XRSerialRoverWorker(XRSerialRoverModule *parent);

	static QString Name();

protected:
	QString port() const;
	QSerialPort::BaudRate baudRate() const;
	QSerialPort::DataBits dataBits() const;
	QSerialPort::FlowControl flowControl() const;
	QSerialPort::Parity parity() const;
	QSerialPort::StopBits stopBits() const;

signals:
	void readyRead();
	void aboutToWrite();

	void opened();
	void aboutToClose();
	void closed();

public slots:
	QByteArray read(qint64 maxSize);
	QByteArray readAll();
	void write(const QByteArray &data);

	void setPort(const QString &port);
	void setBaudRate(QSerialPort::BaudRate baudRate);
	void setDataBits(QSerialPort::DataBits dataBits);
	void setFlowControl(QSerialPort::FlowControl flowControl);
	void setParity(QSerialPort::Parity parity);
	void setStopBits(QSerialPort::StopBits stopBits);

	bool isOpen() const;

	void open();
	void close();

private slots:
	void on_uiRegistered(const QString &name, XRUi *ui);
	void on_aboutToClose();
	void on_readyRead();

private:
	XRSettings *m_settings;
	QSerialPort *m_serialPort;
};

#endif // XRSERIALROVERWORKER_H
