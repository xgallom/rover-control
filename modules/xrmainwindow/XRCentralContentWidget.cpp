#include "XRCentralContentWidget.h"
#include "XRCentralWidget.h"

XRCentralContentWidget::XRCentralContentWidget(XRContentWidgetDelegate *delegate, XRCentralWidget *parent)
	: XRContentWidget(delegate, parent)
{
	parent->addWidget(this);
}

XRCentralContentWidget::~XRCentralContentWidget()
{
	qobject_cast<XRCentralWidget *>(parent())->removeWidget(this);
}
