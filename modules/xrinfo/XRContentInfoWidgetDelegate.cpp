#include "XRContentInfoWidgetDelegate.h"
#include "XRInfoWidget.h"

XRContentInfoWidgetDelegate::XRContentInfoWidgetDelegate()
	: XRContentWidgetDelegate("Info")
{}

QWidget *XRContentInfoWidgetDelegate::constructWidgetImpl() const
{
	return new XRInfoWidget;
}
