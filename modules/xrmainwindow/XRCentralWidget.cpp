#include "XRCentralWidget.h"
#include "XRCentralContentWidget.h"
#include "XRMainWindow.h"
#include <QTabWidget>
#include <QVBoxLayout>

XRCentralWidget::XRCentralWidget(XRMainWindow *parent)
	: XRObject(parent->xrObject())
	, m_tabWidget(nullptr)
{
	QWidget *centralWidget = new QWidget(parent);

	QVBoxLayout *centralWidgetLayout = new QVBoxLayout;

	m_tabWidget = new QTabWidget;
	centralWidgetLayout->addWidget(m_tabWidget);

	centralWidget->setLayout(centralWidgetLayout);
	centralWidget->setObjectName("CentralWidget");
	centralWidget->setStyleSheet("#CentralWidget { border: 1px solid #fff; }");

	parent->setCentralWidget(centralWidget);
}

void XRCentralWidget::addWidget(XRCentralContentWidget *widget)
{
	m_widgets.append(widget);
	m_tabWidget->addTab(widget->widget(), widget->icon(), widget->title());
}

void XRCentralWidget::removeWidget(XRCentralContentWidget *widget)
{
	int indexOfWidget = m_widgets.indexOf(widget);

	if(indexOfWidget != -1) {
		m_widgets.removeAt(indexOfWidget);
		m_tabWidget->removeTab(indexOfWidget);
	}
}

bool XRCentralWidget::hasWidget(XRCentralContentWidget *widget) const
{
	return m_widgets.contains(widget);
}
