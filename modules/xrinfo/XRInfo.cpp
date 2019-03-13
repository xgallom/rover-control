#include "XRInfo.h"
#include "XRCoreApplication.h"
#include "XRModuleManager.h"
#include "XRInfoWorker.h"

XRInfo::XRInfo(XRObject *parent)
	: XRObject(parent)
	, m_worker(nullptr)
	, m_data()
{
	m_worker = app->moduleManager()->getWorkerByType<XRInfoWorker>();
	connect(m_worker, SIGNAL(updateInfo(const XRInfoData &)), this, SLOT(on_data_updated(const XRInfoData &)));
}

XRInfoData XRInfo::data() const
{
	return m_data;
}

void XRInfo::on_data_updated(const XRInfoData &data)
{
	m_data = data;
	emit dataUpdated();
}
