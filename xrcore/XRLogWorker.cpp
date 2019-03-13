#include "XRLogWorker.h"
#include "XRLogModule.h"

#include <QSettings>
#include <QStandardPaths>
#include <QDateTime>
#include <QDebug>

XRLogWorker::XRLogWorker(XRLogModule *parent)
	: XRModuleWorker(parent)
{
	m_logSettings = new QSettings(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + "/xrover/log.ini",
								  QSettings::IniFormat, this
								  );
}

void XRLogWorker::logImpl(const QString &logLevelString, const QString &moduleName, const QString &data)
{
	if(!m_logSettings->contains(moduleName))
		m_logSettings->setValue(moduleName, "INFO");

	QString minimalLogLevelString = m_logSettings->value(moduleName).toString();
	LogLevel minimalLogLevel = LogLevelFromString(minimalLogLevelString);

	if(minimalLogLevel == Invalid)
		qCritical()
				<< GeneratePrefix("ERROR", "XRLog")
				<< QString("Invalid loglevel \"%1\" for module %2")
				   .arg(minimalLogLevelString)
				   .arg(moduleName);

	LogLevel logLevel = LogLevelFromString(logLevelString);
	if(logLevel >= minimalLogLevel) {
		QString message = GeneratePrefix(logLevelString, moduleName) + data;

		switch(logLevel) {
		case Debug: qDebug().noquote().nospace() << message; break;
		case Info : qInfo().noquote().nospace() << message; break;
		case Warn : qWarning().noquote().nospace() << message; break;
		case Error: qCritical().noquote().nospace() << message; break;
		case Fatal: qFatal("%s", message.toLatin1().constData());
		default: break;
		}
	}
}

QString XRLogWorker::GeneratePrefix(const QString &logLevelString, const QString &moduleName)
{
	return QString("[%1] %2 %3: ")
			.arg(QDateTime::currentDateTime().toString(Qt::ISODate))
			.arg(moduleName)
			.arg(logLevelString);
}

XRLogWorker::LogLevel XRLogWorker::LogLevelFromString(const QString &logLevel)
{
		 if(logLevel == "DEBUG") return Debug;
	else if(logLevel == "INFO" ) return Info ;
	else if(logLevel == "WARN" ) return Warn ;
	else if(logLevel == "ERROR") return Error;
	else if(logLevel == "FATAL") return Fatal;

	return Invalid;
}
