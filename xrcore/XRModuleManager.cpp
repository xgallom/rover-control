#include "XRModuleManager.h"

XRModuleManager::XRModuleManager(XRObject *parent)
	: XRObject(parent)
{}

void XRModuleManager::registerModule(const QString &name, XRModule *module)
{
	if(!hasModule(name)) {
		m_modules[name] = module;
		emit moduleRegistered(name, module);
	}
}

XRModule *XRModuleManager::getModuleByName(const QString &name) const
{
	if(hasModule(name))
		return m_modules[name];

	return nullptr;
}

bool XRModuleManager::hasModule(const QString &name) const
{
	return m_modules.contains(name);
}

QVector<QString> XRModuleManager::modules() const
{
	return modulesList().toVector();
}

QStringList XRModuleManager::modulesList() const
{
	return m_modules.keys();
}
