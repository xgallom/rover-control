#ifndef XRMAINWINDOW_H
#define XRMAINWINDOW_H

#include "xrmainwindow_global.h"
#include "XRWidget.h"
#include <QMainWindow>

class XRStatusBar;
class XRCentralWidget;

class XRMAINWINDOWSHARED_EXPORT XRMainWindow : public QMainWindow
{
	Q_OBJECT
	XR_WIDGET
public:
	XRMainWindow();

	XRCentralWidget *centralWidget() const;
	XRStatusBar *statusBar() const;

private:
	XRCentralWidget *m_centralWidget;
	XRStatusBar *m_statusBar;
};


#endif // XRMAINWINDOW_H
