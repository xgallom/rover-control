#ifndef XROBJECT_H
#define XROBJECT_H

#include "xrcore_global.h"
#include <QObject>

class XRThread;

/**
 * @brief The XRObject class is a single object in the system
**/
class XRCORESHARED_EXPORT XRObject : public QObject
{
	Q_OBJECT

	explicit XRObject(QObject *parent, bool constructInternal);
public:
	explicit XRObject(XRObject *parent = nullptr);

	XRObject *parent() const;

	void moveToThread(XRThread *thread);

	static XRObject *CreateComposite(QObject *parent);
};

#endif // XROBJECT_H
