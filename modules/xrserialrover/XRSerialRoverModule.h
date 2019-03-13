#ifndef XRSERIALROVERMODULE_H
#define XRSERIALROVERMODULE_H

#include "xrserialrover_global.h"
#include "XRModule.h"

class XRSERIALROVERSHARED_EXPORT XRSerialRoverModule : public XRModule
{
	Q_OBJECT
public:
	XRSerialRoverModule(XRModuleManager *parent);

	static QString Name();

protected:
	XRModuleWorker *constructWorker() final;
};

#endif // XRSERIALROVERMODULE_H
