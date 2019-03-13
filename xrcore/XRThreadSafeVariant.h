#ifndef XRTHREADSAFEVARIANT_H
#define XRTHREADSAFEVARIANT_H

#include "xrcore_global.h"
#include "XRObject.h"
#include <QVariant>

class XRCORESHARED_EXPORT XRThreadSafeVariant : public XRObject
{
	Q_OBJECT
public:
	explicit XRThreadSafeVariant(XRObject *parent = nullptr);
	explicit XRThreadSafeVariant(const QVariant &value, XRObject *parent = nullptr);

	QVariant value() const;
	void setValue(const QVariant &value);

	XRThreadSafeVariant &operator =(const QVariant &value);

	operator QVariant();

private slots:
	QVariant getValueSync() const;
	void setValueSync(const QVariant &value);

private:
	QVariant getValueAsync() const;
	void setValueAsync(const QVariant &value);

	QVariant m_value;
};

#endif // XRTHREADSAFEVARIANT_H
