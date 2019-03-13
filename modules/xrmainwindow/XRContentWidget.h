#ifndef XRCONTENTWIDGET_H
#define XRCONTENTWIDGET_H

#include "xrmainwindow_global.h"
#include "XRObject.h"

class XRContentWidgetDelegate;

class XRMAINWINDOWSHARED_EXPORT XRContentWidget : public XRObject
{
	Q_OBJECT
public:
	explicit XRContentWidget(XRContentWidgetDelegate *delegate, XRObject *parent = nullptr);
	~XRContentWidget();

	QString title() const;
	QIcon icon() const;
	QWidget *widget() const;

private:
	QWidget *m_widget;
};

#endif // XRCONTENTWIDGET_H
