#include "XRMainWindow.h"
#include "XRCentralWidget.h"
#include "XRStatusBar.h"
#include <QVBoxLayout>

XRMainWindow::XRMainWindow()
	: XR_WIDGET_CONSTRUCT
	, m_centralWidget(nullptr)
	, m_statusBar(nullptr)
{
	m_centralWidget = new XRCentralWidget(this);
	m_statusBar = new XRStatusBar(this);
}

XRCentralWidget *XRMainWindow::centralWidget() const
{
	return m_centralWidget;
}

XRStatusBar *XRMainWindow::statusBar() const
{
	return m_statusBar;
}

XR_WIDGET_IMPL(XRMainWindow)
