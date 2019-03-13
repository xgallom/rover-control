#ifndef XRCENTRALCONTENTWIDGET_H
#define XRCENTRALCONTENTWIDGET_H

#include "xrmainwindow_global.h"
#include "XRContentWidget.h"

class XRCentralWidget;

class XRMAINWINDOWSHARED_EXPORT XRCentralContentWidget : public XRContentWidget
{
	Q_OBJECT
public:
	XRCentralContentWidget(XRContentWidgetDelegate *delegate, XRCentralWidget *parent);
	~XRCentralContentWidget();
};

#endif // XRCENTRALCONTENTWIDGET_H
