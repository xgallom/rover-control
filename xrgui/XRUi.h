#ifndef XRUI_H
#define XRUI_H

#include "xrgui_global.h"
#include "XRObject.h"

class XRUiManager;
class QWidget;

/**
 * @brief The XRUi class is an access wrapper for a single application toplevel widget
**/
class XRGUISHARED_EXPORT XRUi : public XRObject
{
	Q_OBJECT
public:
	XRUi(XRUiManager *parent, const QString &name, QWidget *widget);

	QString name() const;

	QWidget *widget() const;

private slots:
	void onWidgetDestroyed();

private:
	QWidget *m_widget;
	XRUiManager *m_uiManager;

	const QString m_name;
};

#endif // XRUI_H
