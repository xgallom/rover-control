#include "XRSettingsModule.h"
#include "XRSettingsWorker.h"

XRSettingsModule::XRSettingsModule(XRModuleManager *parent)
	: XRModule(parent, Name())
{
	initialize();
}

QString XRSettingsModule::Name()
{
	return "XRSettings";
}

XRModuleWorker *XRSettingsModule::constructWorker()
{
	return new XRSettingsWorker(this);
}

