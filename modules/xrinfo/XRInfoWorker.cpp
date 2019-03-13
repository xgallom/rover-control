#include "XRInfoWorker.h"
#include "XRInfoModule.h"
#include "XRLog.h"

extern "C" {
#include <sys/sysinfo.h>
}

XR_MODULE(XRInfo)

XRInfoWorker::XRInfoWorker(XRInfoModule *parent)
	: XRModuleWorker(parent)
	, m_updateTimer(nullptr)
{
	qRegisterMetaType<XRInfoData>();

	m_updateTimer = new QTimer(this);
	m_updateTimer->setInterval(2000);

	connect(m_updateTimer, SIGNAL(timeout()), this, SLOT(on_updateTimer_timeout()));

	m_data.cpuCores = static_cast<int>(get_nprocs_conf());

	m_updateTimer->start();
}

QString XRInfoWorker::Name()
{
	return XRInfoModule::Name();
}

void XRInfoWorker::on_updateTimer_timeout()
{
	struct sysinfo rv;

	if(sysinfo(&rv) == 0) {
		m_data = {
			rv.freeram, rv.totalram,
			rv.freeswap, rv.totalswap,
			static_cast<double>(rv.loads[0]) / static_cast<double>(1 << SI_LOAD_SHIFT),
			m_data.cpuCores,
			rv.mem_unit
		};

		const QString logMessage = QString("\n free ram: %1,\n total ram: %2,\n free swap: %3,\n"
										   "total swap: %4,\n memory unit: %5,\n cpu usage: %6")
								   .arg(m_data.freeRam)
								   .arg(m_data.totalRam)
								   .arg(m_data.freeSwap)
								   .arg(m_data.totalSwap)
								   .arg(m_data.memUnit)
								   .arg(m_data.cpuUsage);

		LOG_DEBUG("Info updated: " << logMessage);

		emit updateInfo(m_data);
	}
	else
		LOG_ERROR("Error retrieving system info");
}
