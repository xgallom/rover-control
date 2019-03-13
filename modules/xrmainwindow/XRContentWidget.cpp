#include "XRContentWidget.h"
#include "XRContentWidgetDelegate.h"
#include <QWidget>

XRContentWidget::XRContentWidget(XRContentWidgetDelegate *delegate, XRObject *parent)
	: XRObject(parent)
	, m_widget(nullptr)
{
	m_widget = delegate->constructWidget();
}

XRContentWidget::~XRContentWidget()
{
	m_widget->deleteLater();
}

QString XRContentWidget::title() const
{
	return m_widget->windowTitle();
}

QIcon XRContentWidget::icon() const
{
	return m_widget->windowIcon();
}

QWidget *XRContentWidget::widget() const
{
	return m_widget;
}

