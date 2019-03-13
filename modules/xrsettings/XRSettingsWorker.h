#ifndef XRSETTINGSWORKER_H
#define XRSETTINGSWORKER_H

#include "XRModuleWorker.h"

#include <QSettings>

class XRSettingsModule;

class XRSettingsWorker : public XRModuleWorker
{
	Q_OBJECT
public:
	XRSettingsWorker(XRSettingsModule *parent);

	static QString Name();

signals:
	void valueBroadcasted(const QString &key, const QVariant &value);

public slots:
	QVariant getValue(const QString &key) const;
	void requestValue(const QString &key);
	void setValue(const QString &key, const QVariant &value);

private:
	QSettings *m_settings, *m_defaults;
};

#endif // XRSETTINGSWORKER_H
