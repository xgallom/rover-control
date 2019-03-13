#ifndef XRINFOMODULE_H
#define XRINFOMODULE_H

#include "xrinfo_global.h"
#include "XRModule.h"

class XRINFOSHARED_EXPORT XRInfoModule : public XRModule
{
public:
	Q_OBJECT
public:
	XRInfoModule(XRModuleManager *parent);

	static QString Name();

protected:
	XRModuleWorker *constructWorker() final;
};

#endif // XRINFOMODULE_H
