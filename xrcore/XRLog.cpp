#include "XRLog.h"
#include "XRCoreApplication.h"
#include "XRLogModule.h"
#include "XRLogWorker.h"

XRLog::XRLog(const QString &moduleName)
	: m_moduleName(moduleName)
{}

void XRLog::log(const QString &logLevel, const QString &data)
{
	QMetaObject::invokeMethod(
				qobject_cast<XRLogWorker *>(app->logModule()->worker()), "logImpl", Qt::AutoConnection,
				Q_ARG(const QString &, logLevel), Q_ARG(const QString &, m_moduleName), Q_ARG(const QString &, data)
				);
}

