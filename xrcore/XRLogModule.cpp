#include "XRLogModule.h"
#include "XRLogWorker.h"

XRLogModule::XRLogModule(XRCoreApplication *parent)
	: XRModule(parent)
{
	initialize();
}


XRModuleWorker *XRLogModule::constructWorker()
{
	return new XRLogWorker(this);
}
