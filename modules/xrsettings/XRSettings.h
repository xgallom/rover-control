#ifndef XRSETTINGS_H
#define XRSETTINGS_H

#include "xrsettings_global.h"
#include "XRObject.h"

class XRSettingsWorker;

class XRSETTINGSSHARED_EXPORT XRSettings : public XRObject
{
	Q_OBJECT
public:
	XRSettings(XRObject *parent = nullptr);

	QVariant getValue(const QString &key) const;
	void getValueAsync(const QString &key);
	void setValue(const QString &key, const QVariant &value);

signals:
	void valueBroadcast(const QString &key, const QVariant &value) const;

private slots:
	void valueReceived(const QString &key, const QVariant &value) const;

private:
	XRSettingsWorker *m_worker;
	mutable bool m_isReceiveValueConnected;
};

#endif // XRSETTINGS_H
