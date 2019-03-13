#include "XRContentWidgetDelegate.h"
#include <QWidget>

XRContentWidgetDelegate::XRContentWidgetDelegate(const QString &title, const QIcon &icon)
	: m_title(title)
	, m_icon(icon)
{}

QString XRContentWidgetDelegate::title() const
{
	return m_title;
}

QIcon XRContentWidgetDelegate::icon() const
{
	return m_icon;
}

QWidget *XRContentWidgetDelegate::constructWidget() const
{
	QWidget *constructedWidget = constructWidgetImpl();

	constructedWidget->setWindowTitle(title());
	constructedWidget->setWindowIcon(icon());

	return constructedWidget;
}

