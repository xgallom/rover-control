#ifndef XRSTATUSBARSERIALROVERSTATUSWIDGET_H
#define XRSTATUSBARSERIALROVERSTATUSWIDGET_H

#include "XRStatusBarSerialRoverStatus.h"
#include <QWidget>
#include <QLabel>

class XRStatusBarSerialRoverStatusWidget : public QWidget
{
	Q_OBJECT
public:
	XRStatusBarSerialRoverStatusWidget(XRStatusBarSerialRoverStatus::Status status);

	void setStatus(XRStatusBarSerialRoverStatus::Status status);

private:
	QPixmap
	m_iconDisconnected,
	m_iconConnected,
	m_iconTransferIn,
	m_iconTransferOut,
	m_iconTransferBoth;

	QLabel
	*m_icon,
	*m_label;
};

#endif // XRSTATUSBARSERIALROVERSTATUSWIDGET_H
