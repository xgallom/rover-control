#ifndef XRSETTINGSMODULE_H
#define XRSETTINGSMODULE_H

#include "xrsettings_global.h"
#include "XRModule.h"

class XRSETTINGSSHARED_EXPORT XRSettingsModule : public XRModule
{
	Q_OBJECT
public:
	XRSettingsModule(XRModuleManager *parent);

	static QString Name();

protected:
	XRModuleWorker *constructWorker() final;
};

#endif // XRSETTINGSMODULE_H
