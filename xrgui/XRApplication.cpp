#include "XRApplication.h"
#include "XRUiManager.h"

XRApplication::XRApplication()
	: XRCoreApplication()
	, m_uiManager(nullptr)
{
	m_uiManager = new XRUiManager(this);
}

XRUiManager *XRApplication::uiManager() const
{
	return m_uiManager;
}

XRApplication *XRApplication::Instance()
{
	return qobject_cast<XRApplication *>(XRCoreApplication::Instance());
}

