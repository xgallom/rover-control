#ifndef XRINFOWORKER_H
#define XRINFOWORKER_H

#include "XRModuleWorker.h"
#include "XRInfo.h"
#include <QTimer>

class XRInfoModule;

class XRInfoWorker : public XRModuleWorker
{
	Q_OBJECT
public:
	XRInfoWorker(XRInfoModule *parent);

	static QString Name();

signals:
	void updateInfo(const XRInfoData &);

private slots:
	void on_updateTimer_timeout();

private:
	QTimer *m_updateTimer;
	XRInfoData m_data;
};

#endif // XRINFOWORKER_H
