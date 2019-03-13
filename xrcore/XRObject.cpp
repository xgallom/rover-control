#include "XRObject.h"

#include "XRThread.h"

XRObject::XRObject(QObject *parent, bool) : QObject(parent)
{}

XRObject::XRObject(XRObject *parent) : QObject(parent)
{}

XRObject *XRObject::parent() const
{
	return qobject_cast<XRObject *>(QObject::parent());
}

void XRObject::moveToThread(XRThread *thread)
{
	QObject::moveToThread(thread);
}

XRObject *XRObject::CreateComposite(QObject *parent)
{
	return new XRObject(parent, true);
}
