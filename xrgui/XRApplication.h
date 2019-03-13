#ifndef XRAPPLICATION_H
#define XRAPPLICATION_H

#include "xrgui_global.h"
#include "XRCoreApplication.h"

class XRUiManager;

/**
 * @brief The XRApplication class is the most top-level ui class, instantiates XRUiManager and loads XRUis
 */
class XRGUISHARED_EXPORT XRApplication : public XRCoreApplication
{
	Q_OBJECT
public:
	XRApplication();

	XRUiManager *uiManager() const;

	static XRApplication *Instance();

private:
	XRUiManager *m_uiManager;
};

#ifdef app
#undef app
#endif
#define app XRApplication::Instance()

#endif // XRAPPLICATION_H
