#include "XRInfoModule.h"
#include "XRInfoWorker.h"

XRInfoModule::XRInfoModule(XRModuleManager *parent)
	: XRModule(parent, Name())
{
	initialize();
}

QString XRInfoModule::Name()
{
	return "XRInfo";
}

XRModuleWorker *XRInfoModule::constructWorker()
{
	return new XRInfoWorker(this);
}
