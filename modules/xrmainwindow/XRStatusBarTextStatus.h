#ifndef XRSTATUSBARTEXTSTATUS_H
#define XRSTATUSBARTEXTSTATUS_H

#include "xrmainwindow_global.h"
#include "XRStatusBarStatus.h"

class XRMAINWINDOWSHARED_EXPORT XRStatusBarTextStatus : public XRStatusBarStatus
{
	Q_OBJECT
public:
	explicit XRStatusBarTextStatus(XRObject *parent = nullptr);
	explicit XRStatusBarTextStatus(const QString &text, XRObject *parent = nullptr);

	QString text() const;
	void setText(const QString &text);

	QWidget *createStatus() const final;
	void refreshStatus(QWidget *widget) const final;
};

#endif // XRSTATUSBARTEXTSTATUS_H
