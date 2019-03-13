#ifndef XRSTATUSBAR_H
#define XRSTATUSBAR_H

#include "XRObject.h"
#include <QHash>

class XRMainWindow;
class XRStatusBarStatus;
class QStatusBar;
class QWidget;

class XRStatusBar : public XRObject
{
	Q_OBJECT
public:
	explicit XRStatusBar(XRMainWindow *parent);
	virtual ~XRStatusBar() = default;

public slots:
	void showMessage(const QString &message, int timeout = 0);

	void addStatus(XRStatusBarStatus *status);
	void showStatus(XRStatusBarStatus *status);
	void hideStatus(XRStatusBarStatus *status);
	void refreshStatus(XRStatusBarStatus *status);
	void removeStatus(XRStatusBarStatus *status);

private:
	bool hasStatus(XRStatusBarStatus *status) const;

	QStatusBar *m_statusBar;
	QHash<XRStatusBarStatus *, QWidget *> m_registeredStatuses;
};

#endif // XRSTATUSBAR_H
