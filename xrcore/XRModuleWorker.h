#ifndef XRMODULEWORKER_H
#define XRMODULEWORKER_H

#include "xrcore_global.h"
#include "XRObject.h"

class XRModule;

/**
 * @brief The XRWorker class is a single XRObject living in its own thread created by XRModule
**/
class XRCORESHARED_EXPORT XRModuleWorker : public XRObject
{
	Q_OBJECT
public:
	explicit XRModuleWorker(XRModule *parent);

	XRModule *module() const;

private:
	XRModule *m_module;
};

#endif // XRMODULEWORKER_H
