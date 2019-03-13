#ifndef XRLOGWORKER_H
#define XRLOGWORKER_H

#include "XRModuleWorker.h"

class XRLogModule;
class QSettings;
class QDebug;

class XRLogWorker : public XRModuleWorker
{
	Q_OBJECT
public:
	XRLogWorker(XRLogModule *parent);

public slots:
	void logImpl(const QString &logLevelString, const QString &moduleName, const QString &data);

private:
	static const int ValidLogLevels = 5;
	enum LogLevel {
		Debug = 0,
		Info,
		Warn,
		Error,
		Fatal,
		Invalid
	};

	static QString GeneratePrefix(const QString &logLevelString, const QString &moduleName);
	static LogLevel LogLevelFromString(const QString &logLevel);

	QSettings *m_logSettings;
};

#endif // XRLOGWORKER_H
