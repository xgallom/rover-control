#ifndef XRINFOWIDGET_H
#define XRINFOWIDGET_H

#include "XRWidget.h"
#include <QWidget>

namespace Ui {
	class XRInfoWidget;
}

class XRInfo;

class XRInfoWidget : public QWidget
{
	Q_OBJECT
	XR_WIDGET
public:
	explicit XRInfoWidget(QWidget *parent = nullptr);
	~XRInfoWidget();

private:
	static QString MemoryToString(unsigned long memory, unsigned int memoryUnit);

	XRInfo *m_info;

	Ui::XRInfoWidget *ui;

private slots:
	void onDataUpdated();
	void onModulesUpdated();
};

#endif // XRINFOWIDGET_H
