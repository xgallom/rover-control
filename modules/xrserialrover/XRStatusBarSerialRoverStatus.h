#ifndef XRSTATUSBARSERIALROVERSTATUS_H
#define XRSTATUSBARSERIALROVERSTATUS_H

#include "XRStatusBarStatus.h"

class XRSerialRoverWorker;
class QTimer;

class XRStatusBarSerialRoverStatus : public XRStatusBarStatus
{
	Q_OBJECT
public:
	enum State {
		Disconnected = 0,
		Connected = 1,
		TransferIn = 2,
		TransferOut = 4,
		TransferBoth = 2|4
	};
	Q_DECLARE_FLAGS(Status, State)

	XRStatusBarSerialRoverStatus(XRSerialRoverWorker *parent);

	QWidget *createStatus() const final;
	void refreshStatus(QWidget *widget) const final;

protected:
	Status status() const;

private slots:
	void on_serialRover_opened();
	void on_serialRover_closed();
	void on_serialRover_readyRead();
	void on_serialRover_aboutToWrite();

	void on_timer_timeout();

private:
	QTimer *m_resetTimer;
};

Q_DECLARE_METATYPE(XRStatusBarSerialRoverStatus::Status)

#endif // XRSTATUSBARSERIALROVERSTATUS_H
