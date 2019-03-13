#include "XRSettings.h"
#include "XRCoreApplication.h"
#include "XRModuleManager.h"
#include "XRThread.h"
#include "XRSettingsWorker.h"

XRSettings::XRSettings(XRObject *parent)
	: XRObject(parent)
	, m_worker(nullptr)
	, m_isReceiveValueConnected(false)
{
	m_worker = app->moduleManager()->getWorkerByType<XRSettingsWorker>();
}

QVariant XRSettings::getValue(const QString &key) const
{
	QVariant rv;
	QMetaObject::invokeMethod(m_worker, "getValue", Qt::BlockingQueuedConnection,
							  Q_RETURN_ARG(QVariant, rv), Q_ARG(const QString &, key)
							  );

	return rv;
}

void XRSettings::getValueAsync(const QString &key)
{
	// TODO: Implement correctly
	if(!m_isReceiveValueConnected) {
		connect(m_worker, SIGNAL(valueBroadcasted(const QString &, const QVariant &)), this,
				SLOT(valueReceived(const QString &, const QVariant &))
				);
		m_isReceiveValueConnected = true;
	}

	QMetaObject::invokeMethod(m_worker, "requestValue", Qt::QueuedConnection, Q_ARG(const QString &, key));
}

void XRSettings::setValue(const QString &key, const QVariant &value)
{
	QMetaObject::invokeMethod(m_worker, "setValue", Qt::QueuedConnection, Q_ARG(QString, key), Q_ARG(QVariant, value));
}

void XRSettings::valueReceived(const QString &key, const QVariant &value) const
{
	emit valueBroadcast(key, value);
}
