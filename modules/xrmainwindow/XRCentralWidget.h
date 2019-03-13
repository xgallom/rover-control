#ifndef XRCENTRALWIDGET_H
#define XRCENTRALWIDGET_H

#include "xrmainwindow_global.h"
#include "XRObject.h"
#include <QVector>

class XRMainWindow;
class XRCentralContentWidget;
class QTabWidget;

class XRMAINWINDOWSHARED_EXPORT XRCentralWidget : public XRObject
{
	Q_OBJECT
public:
	XRCentralWidget(XRMainWindow *parent);

public slots:
	void addWidget(XRCentralContentWidget *widget);
	void removeWidget(XRCentralContentWidget *widget);

private:
	bool hasWidget(XRCentralContentWidget *widget) const;

private:
	QTabWidget *m_tabWidget;
	QVector<XRCentralContentWidget *> m_widgets;
};

#endif // XRCENTRALWIDGET_H
