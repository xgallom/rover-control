#include "XRThread.h"
#include "XRObject.h"

XRThread::XRThread(XRObject *parent) : QThread(parent)
{}

XRThread::XRThread(XRThreadPriority::Enum threadPriority, XRObject *parent) : QThread(parent)
{
	setPriority(threadPriority);
}

XRThreadPriority::Enum XRThread::priority() const
{
	return static_cast<XRThreadPriority::Enum>(QThread::priority());
}

void XRThread::setPriority(XRThreadPriority::Enum threadPriority)
{
	QThread::setPriority(static_cast<QThread::Priority>(threadPriority));
}

bool XRThread::IsObjectInCurrentThread(const XRObject *object)
{
	return object->thread() == QThread::currentThread();
}
