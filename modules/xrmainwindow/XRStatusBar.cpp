#include "XRStatusBar.h"
#include "XRMainWindow.h"
#include "XRStatusBarStatus.h"
#include <QStatusBar>

XRStatusBar::XRStatusBar(XRMainWindow *parent)
	: XRObject(parent->xrObject())
	, m_statusBar(parent->QMainWindow::statusBar())
{
	qRegisterMetaType<XRStatusBarStatus *>();
}

void XRStatusBar::showMessage(const QString &message, int timeout)
{
	m_statusBar->showMessage(message, timeout);
}

void XRStatusBar::addStatus(XRStatusBarStatus *status)
{
	if(!hasStatus(status)) {
		QWidget *statusWidget = status->createStatus();

		m_registeredStatuses[status] = statusWidget;
	}

	showStatus(status);
}

void XRStatusBar::showStatus(XRStatusBarStatus *status)
{
	if(hasStatus(status)) {
		m_statusBar->addWidget(m_registeredStatuses[status]);
	}
}

void XRStatusBar::hideStatus(XRStatusBarStatus *status)
{
	if(hasStatus(status))
		m_statusBar->removeWidget(m_registeredStatuses[status]);
}

void XRStatusBar::refreshStatus(XRStatusBarStatus *status)
{
	if(hasStatus(status))
		status->refreshStatus(m_registeredStatuses[status]);
}

void XRStatusBar::removeStatus(XRStatusBarStatus *status)
{
	if(hasStatus(status)) {
		hideStatus(status);

		m_registeredStatuses[status]->deleteLater();

		m_registeredStatuses.remove(status);
	}
}

bool XRStatusBar::hasStatus(XRStatusBarStatus *status) const
{
	return m_registeredStatuses.contains(status);
}
