#ifndef XRLOGMODULE_H
#define XRLOGMODULE_H

#include "XRModule.h"

class XRLogModule : public XRModule
{
public:
	XRLogModule(XRCoreApplication *parent);

protected:
	XRModuleWorker *constructWorker() final;
};

#endif // XRLOGMODULE_H
