#ifndef XRLOG_H
#define XRLOG_H

#include "xrcore_global.h"
#include <QVariant>
#include <QTextStream>

class QSettings;

class XRCORESHARED_EXPORT XRLog
{
public:
	explicit XRLog(const QString &moduleName);

	void log(const QString &logLevel, const QString &data);

private:
	const QString m_moduleName;
};

#define XR_MODULE(MODULE_NAME) \
	static XRLog S_XR_LOG(#MODULE_NAME);

#define XR_LOG(LOG_LEVEL, MESSAGE) \
	do{QString a;QTextStream b(&a);b<<MESSAGE;S_XR_LOG.log(#LOG_LEVEL, a);}while(false)

#define LOG_DEBUG(MESSAGE) XR_LOG(DEBUG, MESSAGE)
#define LOG_INFO(MESSAGE) XR_LOG(INFO, MESSAGE)
#define LOG_WARN(MESSAGE) XR_LOG(WARN, MESSAGE)
#define LOG_ERROR(MESSAGE) XR_LOG(ERROR, MESSAGE)
#define LOG_FATAL(MESSAGE) XR_LOG(FATAL, MESSAGE)

#endif // XRLOG_H
