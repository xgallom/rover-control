#ifndef XRWIDGET_H
#define XRWIDGET_H

#include "XRObject.h"

#define XR_WIDGET \
	XRObject *m_xrObject; \
public: \
	XRObject *xrObject(); \
	static QString Name();

#define XR_WIDGET_CONSTRUCT \
	m_xrObject(XRObject::CreateComposite(this))

#define XR_WIDGET_IMPL(NAME) \
XRObject *NAME::xrObject() { return m_xrObject; } \
QString NAME::Name() { return #NAME; }


#endif // XRWIDGET_H
