#include "XRStatusBarSerialRoverStatusWidget.h"
#include "XRResources.h"
#include <QHBoxLayout>

XRStatusBarSerialRoverStatusWidget::XRStatusBarSerialRoverStatusWidget(XRStatusBarSerialRoverStatus::Status status)
{
	m_iconDisconnected = QPixmap(GetResource(Resource::Pixmap::IconDisconnected));
	m_iconConnected    = QPixmap(GetResource(Resource::Pixmap::IconTransferNone));
	m_iconTransferIn   = QPixmap(GetResource(Resource::Pixmap::IconTransferIn  ));
	m_iconTransferOut  = QPixmap(GetResource(Resource::Pixmap::IconTransferOut ));
	m_iconTransferBoth = QPixmap(GetResource(Resource::Pixmap::IconTransferBoth));

	QHBoxLayout *layout = new QHBoxLayout();

	m_icon = new QLabel(this);
	layout->addWidget(m_icon);

	m_label = new QLabel(this);
	layout->addWidget(m_label);

	setLayout(layout);

	setStatus(status);
}

void XRStatusBarSerialRoverStatusWidget::setStatus(XRStatusBarSerialRoverStatus::Status status)
{
	if(status & XRStatusBarSerialRoverStatus::Connected) {
		QPixmap *pixmap;

		if(status & XRStatusBarSerialRoverStatus::TransferIn) {
			if(status & XRStatusBarSerialRoverStatus::TransferOut)
				pixmap = &m_iconTransferBoth;
			else
				pixmap = &m_iconTransferIn;
		}
		else if(status & XRStatusBarSerialRoverStatus::TransferOut)
			pixmap = &m_iconTransferOut;
		else
			pixmap = &m_iconConnected;

		m_icon->setPixmap(*pixmap);
		m_label->setText("Connected");
	}
	else {
		m_icon->setPixmap(m_iconDisconnected);
		m_label->setText("Disconnected");
	}
}
