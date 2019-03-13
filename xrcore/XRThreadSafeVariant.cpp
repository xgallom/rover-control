#include "XRThreadSafeVariant.h"
#include "XRThread.h"

XRThreadSafeVariant::XRThreadSafeVariant(XRObject *parent)
	: XRObject(parent)
{}

XRThreadSafeVariant::XRThreadSafeVariant(const QVariant &value, XRObject *parent)
	: XRObject(parent)
	, m_value(value)
{}

QVariant XRThreadSafeVariant::value() const
{
	if(XRThread::IsObjectInCurrentThread(this))
		return getValueSync();
	else
		return getValueAsync();
}

void XRThreadSafeVariant::setValue(const QVariant &value)
{
	if(XRThread::IsObjectInCurrentThread(this))
		setValueSync(value);
	else
		setValueAsync(value);
}

XRThreadSafeVariant &XRThreadSafeVariant::operator =(const QVariant &value)
{
	setValue(value);
	return *this;
}

XRThreadSafeVariant::operator QVariant()
{
	return value();
}

QVariant XRThreadSafeVariant::getValueSync() const
{
	return m_value;
}

void XRThreadSafeVariant::setValueSync(const QVariant &value)
{
	m_value = value;
}

QVariant XRThreadSafeVariant::getValueAsync() const
{
	QVariant rv;

	QMetaObject::invokeMethod(const_cast<XRThreadSafeVariant *>(this), "getValueSync", Qt::BlockingQueuedConnection,
							  Q_RETURN_ARG(QVariant, rv)
							  );

	return rv;
}

void XRThreadSafeVariant::setValueAsync(const QVariant &value)
{
	QMetaObject::invokeMethod(this, "setValueSync", Qt::QueuedConnection, Q_ARG(const QVariant &, value));
}
