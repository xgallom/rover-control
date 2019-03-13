#include "XRSerialRoverModule.h"
#include "XRSerialRoverWorker.h"
#include "XRResources.h"

XRSerialRoverModule::XRSerialRoverModule(XRModuleManager *parent)
	: XRModule(parent, Name())
{
	initialize();

	QMetaObject::invokeMethod(worker(), "open", Qt::AutoConnection);
}

QString XRSerialRoverModule::Name()
{
	return "XRSerialRover";
}

XRModuleWorker *XRSerialRoverModule::constructWorker()
{
	return new XRSerialRoverWorker(this);
}
