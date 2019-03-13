#include "XRUiManager.h"

XRUiManager::XRUiManager(XRObject *parent)
	: XRObject(parent)
{}

void XRUiManager::registerUi(const QString &name, XRUi *ui)
{
	if(!hasUi(name)) {
		m_uis[name] = ui;
		emit uiRegistered(name, ui);
	}
}

void XRUiManager::removeUi(const QString &name)
{
	if(hasUi(name))
		m_uis.remove(name);
}

XRUi *XRUiManager::getUiByName(const QString &name) const
{
	if(hasUi(name))
		return m_uis[name];

	return nullptr;
}

bool XRUiManager::hasUi(const QString &name) const
{
	return m_uis.contains(name);
}
