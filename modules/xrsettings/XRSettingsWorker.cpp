#include "XRSettingsWorker.h"
#include "XRSettingsModule.h"
#include "XRLog.h"
#include <QStandardPaths>
#include <QDebug>

XR_MODULE(XRSettings)

XRSettingsWorker::XRSettingsWorker(XRSettingsModule *parent)
	: XRModuleWorker(parent)
	, m_settings(nullptr)
	, m_defaults(nullptr)
{
	QString settingsPath = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/xrover";
	m_settings = new QSettings(settingsPath + "/config.ini", QSettings::IniFormat, this);
	m_defaults = new QSettings(APPLICATION_BIN "/defaults.ini", QSettings::IniFormat, this);

	LOG_INFO("Initializing settings with:" <<
			 "\n  rw " << m_settings->fileName() <<
			 "\n  r- " << m_defaults->fileName());
}

QString XRSettingsWorker::Name()
{
	return XRSettingsModule::Name();
}

QVariant XRSettingsWorker::getValue(const QString &key) const
{
	return m_settings->value(key, m_defaults->value(key));
}

void XRSettingsWorker::requestValue(const QString &key)
{
	emit valueBroadcasted(key, getValue(key));
}

void XRSettingsWorker::setValue(const QString &key, const QVariant &value)
{
	m_settings->setValue(key, value);
}
