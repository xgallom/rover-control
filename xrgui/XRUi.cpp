#include "XRUi.h"
#include "XRUiManager.h"
#include <QWidget>

XRUi::XRUi(XRUiManager *parent, const QString &name, QWidget *widget)
	: XRObject(parent)
	, m_widget(widget)
	, m_name(name)
{
	parent->registerUi(name, this);

	connect(widget, SIGNAL(destroyed()), this, SLOT(onWidgetDestroyed()));
}

QString XRUi::name() const
{
	return m_name;
}

QWidget *XRUi::widget() const
{
	return m_widget;
}

void XRUi::onWidgetDestroyed()
{
	qobject_cast<XRUiManager *>(parent())->removeUi(name());
	deleteLater();
}
