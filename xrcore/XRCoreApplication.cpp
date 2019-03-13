#include "XRCoreApplication.h"
#include "XRModuleManager.h"
#include "XRLogModule.h"

static XRCoreApplication *s_instance = nullptr;

XRCoreApplication::XRCoreApplication()
	: m_moduleManager(nullptr)
{
	s_instance = this;

	m_logModule = new XRLogModule(this);

	m_moduleManager = new XRModuleManager(this);
}

XRModuleManager *XRCoreApplication::moduleManager() const
{
	return m_moduleManager;
}

XRLogModule *XRCoreApplication::logModule() const
{
	return m_logModule;
}

XRCoreApplication *XRCoreApplication::Instance()
{
	return s_instance;
}
