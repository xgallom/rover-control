#include "XRStatusBarTextStatus.h"
#include <QLabel>

XRStatusBarTextStatus::XRStatusBarTextStatus(XRObject *parent)
	: XRStatusBarStatus(parent)
{}

XRStatusBarTextStatus::XRStatusBarTextStatus(const QString &text, XRObject *parent)
	: XRStatusBarStatus(text, parent)
{}

QString XRStatusBarTextStatus::text() const
{
	return context().toString();
}

void XRStatusBarTextStatus::setText(const QString &text)
{
	setContext(text);
}

QWidget *XRStatusBarTextStatus::createStatus() const
{
	return new QLabel(text());
}

void XRStatusBarTextStatus::refreshStatus(QWidget *widget) const
{
	qobject_cast<QLabel *>(widget)->setText(text());
}
