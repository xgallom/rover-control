#ifndef XRSTATUSBARSTATUS_H
#define XRSTATUSBARSTATUS_H

#include "xrmainwindow_global.h"
#include "XRObject.h"
#include "XRThreadSafeVariant.h"
#include <QVariant>

class QWidget;
class XRStatusBar;

class XRMAINWINDOWSHARED_EXPORT XRStatusBarStatus : public XRObject
{
	Q_OBJECT
public:
	explicit XRStatusBarStatus(XRObject *parent = nullptr);
	explicit XRStatusBarStatus(const QVariant &initialContext, XRObject *parent = nullptr);
	virtual ~XRStatusBarStatus();

	void show();
	void hide();

	virtual QWidget *createStatus() const = 0;
	virtual void refreshStatus(QWidget *statusWidget) const = 0;

	static void ShowMessage(const QString &message, int timeout = 0);

protected:
	void setContext(const QVariant &context);
	QVariant context() const;
	void invokeStandardStatusBarMethod(const char method[]);

private:
	static XRStatusBar *findStatusBar();

	XRThreadSafeVariant *m_context;
	XRStatusBar *m_statusBar;
};

#endif // XRSTATUSBARSTATUS_H
