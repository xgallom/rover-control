#ifndef XRTHREAD_H
#define XRTHREAD_H

#include "xrcore_global.h"
#include "XRObject.h"
#include <QThread>

#include "XRThreadPriority.h"

/**
 * @brief The Thread class is a single process thread
**/
class XRCORESHARED_EXPORT XRThread : public QThread
{
	Q_OBJECT
public:
	explicit XRThread(XRObject *parent = nullptr);
	explicit XRThread(XRThreadPriority::Enum threadPriority, XRObject *parent = nullptr);

	XRThreadPriority::Enum priority() const;
	void setPriority(XRThreadPriority::Enum threadPriority);

	static bool IsObjectInCurrentThread(const XRObject *object);
};

#endif // XRTHREAD_H
