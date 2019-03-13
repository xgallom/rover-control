#ifndef XRCOREAPPLICATION_H
#define XRCOREAPPLICATION_H

#include "xrcore_global.h"
#include "XRObject.h"

class XRModuleManager;
class XRLogModule;

/**
 * @brief The XRCoreApplication class is the most top-level class, instantiates XRModuleManager and loads XRModules
 */
class XRCORESHARED_EXPORT XRCoreApplication : public XRObject
{
	Q_OBJECT
public:
	XRCoreApplication();

	XRModuleManager *moduleManager() const;
	XRLogModule *logModule() const;

	static XRCoreApplication *Instance();

private:
	XRModuleManager *m_moduleManager;
	XRLogModule *m_logModule;
};

#ifdef app
#undef app
#endif
#define app XRCoreApplication::Instance()

#endif // XRCOREAPPLICATION_H
