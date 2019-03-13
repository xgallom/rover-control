#ifndef XRCONTENTWIDGETDELEGATE_H
#define XRCONTENTWIDGETDELEGATE_H

#include "xrmainwindow_global.h"
#include "XRWidget.h"
#include <QIcon>

class XRContentWidget;

class XRMAINWINDOWSHARED_EXPORT XRContentWidgetDelegate
{
public:
	XRContentWidgetDelegate(const QString &title, const QIcon &icon = QIcon());
	virtual ~XRContentWidgetDelegate() = default;

	QString title() const;
	QIcon icon() const;
	QWidget *constructWidget() const;

protected:
	virtual QWidget *constructWidgetImpl() const = 0;

private:
	QString m_title;
	QIcon m_icon;
};

#endif // XRCONTENTWIDGETDELEGATE_H
