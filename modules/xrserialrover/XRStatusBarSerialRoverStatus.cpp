#include "XRStatusBarSerialRoverStatus.h"
#include "XRSerialRoverWorker.h"
#include "XRStatusBarSerialRoverStatusWidget.h"
#include <QTimer>

XRStatusBarSerialRoverStatus::XRStatusBarSerialRoverStatus(XRSerialRoverWorker *parent)
	: XRStatusBarStatus(parent)
{
	m_resetTimer = new QTimer(this);
	m_resetTimer->setInterval(500);
	m_resetTimer->setSingleShot(true);
	connect(m_resetTimer, SIGNAL(timeout()), this, SLOT(on_timer_timeout()));

	connect(parent, SIGNAL(opened()), this, SLOT(on_serialRover_opened()));
	connect(parent, SIGNAL(closed()), this, SLOT(on_serialRover_closed()));
	connect(parent, SIGNAL(readyRead()), this, SLOT(on_serialRover_readyRead()));
	connect(parent, SIGNAL(aboutToWrite()), this, SLOT(on_serialRover_aboutToWrite()));

	setContext(QVariant::fromValue<Status>(parent->isOpen() ? Connected : Disconnected));
}

QWidget *XRStatusBarSerialRoverStatus::createStatus() const
{
	XRStatusBarSerialRoverStatusWidget *widget = new XRStatusBarSerialRoverStatusWidget(status());

	return widget;
}

void XRStatusBarSerialRoverStatus::refreshStatus(QWidget *widget) const
{
	qobject_cast<XRStatusBarSerialRoverStatusWidget *>(widget)->setStatus(status());
}

XRStatusBarSerialRoverStatus::Status XRStatusBarSerialRoverStatus::status() const
{
	return context().value<Status>();
}

void XRStatusBarSerialRoverStatus::on_serialRover_opened()
{
	setContext(QVariant::fromValue<Status>(Connected));
}

void XRStatusBarSerialRoverStatus::on_serialRover_closed()
{
	setContext(QVariant::fromValue<Status>(Disconnected));
}

void XRStatusBarSerialRoverStatus::on_serialRover_readyRead()
{
	setContext(QVariant::fromValue<Status>(status() | TransferIn));
	m_resetTimer->start();
}

void XRStatusBarSerialRoverStatus::on_serialRover_aboutToWrite()
{
	setContext(QVariant::fromValue<Status>(status() | TransferOut));
	m_resetTimer->start();
}

void XRStatusBarSerialRoverStatus::on_timer_timeout()
{
	setContext(QVariant::fromValue<Status>(status() & Connected));
}
