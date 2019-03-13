#include "XRStatusBarStatus.h"
#include "XRApplication.h"
#include "XRUiManager.h"
#include "XRMainWindow.h"
#include "XRStatusBar.h"
#include "XRThread.h"

XRStatusBarStatus::XRStatusBarStatus(XRObject *parent)
	: XRObject(parent)
	, m_context(nullptr)
	, m_statusBar(findStatusBar())
{
	m_context = new XRThreadSafeVariant(this);
}

XRStatusBarStatus::XRStatusBarStatus(const QVariant &initialContext, XRObject *parent)
	: XRObject(parent)
	, m_context(nullptr)
	, m_statusBar(findStatusBar())
{
	m_context = new XRThreadSafeVariant(initialContext, this);
}

XRStatusBarStatus::~XRStatusBarStatus()
{
	invokeStandardStatusBarMethod("removeStatus");
}

void XRStatusBarStatus::show()
{
	invokeStandardStatusBarMethod("addStatus");
}

void XRStatusBarStatus::hide()
{
	invokeStandardStatusBarMethod("hideStatus");
}

void XRStatusBarStatus::ShowMessage(const QString &message, int timeout)
{
	QMetaObject::invokeMethod(findStatusBar(), "showMessage", Qt::AutoConnection,
							  Q_ARG(const QString &, message), Q_ARG(int, timeout)
							  );
}

void XRStatusBarStatus::setContext(const QVariant &context)
{
	m_context->setValue(context);
	invokeStandardStatusBarMethod("refreshStatus");
}

void XRStatusBarStatus::invokeStandardStatusBarMethod(const char method[])
{
	QMetaObject::invokeMethod(m_statusBar, method, Qt::AutoConnection, Q_ARG(XRStatusBarStatus *, this));
}

QVariant XRStatusBarStatus::context() const
{
	return m_context->value();
}

XRStatusBar *XRStatusBarStatus::findStatusBar()
{
	return app->uiManager()->getWidgetByType<XRMainWindow>()->statusBar();
}
