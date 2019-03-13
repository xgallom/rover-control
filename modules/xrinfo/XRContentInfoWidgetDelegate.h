#ifndef XRCONTENTINFOWIDGETDELEGATE_H
#define XRCONTENTINFOWIDGETDELEGATE_H

#include "xrinfo_global.h"
#include "XRContentWidgetDelegate.h"

class XRINFOSHARED_EXPORT XRContentInfoWidgetDelegate : public XRContentWidgetDelegate
{
public:
	XRContentInfoWidgetDelegate();

protected:
	QWidget *constructWidgetImpl() const final;
};

#endif // XRCONTENTINFOWIDGETDELEGATE_H
