#include "XRInfoWidget.h"
#include "ui_XRInfoWidget.h"
#include "XRApplication.h"
#include "XRModuleManager.h"
#include "XRInfo.h"
#include <QtMath>

XRInfoWidget::XRInfoWidget(QWidget *parent)
	: QWidget(parent)
	, XR_WIDGET_CONSTRUCT
	, m_info(nullptr)
	, ui(new Ui::XRInfoWidget)
{
	ui->setupUi(this);

	m_info = new XRInfo(xrObject());
	connect(m_info, SIGNAL(dataUpdated()), this, SLOT(onDataUpdated()));
	onDataUpdated();

	connect(app->moduleManager(), SIGNAL(moduleRegistered(const QString &, XRModule *)),
			this, SLOT(onModulesUpdated())
			);

	onModulesUpdated();
}

XRInfoWidget::~XRInfoWidget()
{
	delete ui;
}

QString XRInfoWidget::MemoryToString(unsigned long memory, unsigned int memoryUnit)
{
	return QString::number(static_cast<double>(memory * memoryUnit) / static_cast<double>(1 << 30), 'f', 2) + " GB";
}

void XRInfoWidget::onDataUpdated()
{
	static const auto computePercentage = [](double total, double free) {
		return qRound(100.0 * (total - free) / total);
	};

	XRInfoData data = m_info->data();
	ui->systemInfoCpuCoresValue->setText(QString::number(data.cpuCores));
	ui->systemInfoCpuUsageValue->setValue(qRound(100.0 * data.cpuUsage / data.cpuCores));
	ui->systemInfoFreeMemoryValue->setText(MemoryToString(data.freeRam, data.memUnit));
	ui->systemInfoTotalMemoryValue->setText(MemoryToString(data.totalRam, data.memUnit));
	ui->systemInfoFreeSwapValue->setText(MemoryToString(data.freeSwap, data.memUnit));
	ui->systemInfoTotalSwapValue->setText(MemoryToString(data.totalSwap, data.memUnit));
	ui->systemInfoUsedMemoryValue->setValue(computePercentage(data.totalRam, data.freeRam));
	ui->systemInfoUsedSwapValue->setValue(computePercentage(data.totalSwap, data.freeSwap));
}

void XRInfoWidget::onModulesUpdated()
{
	ui->moduleListWidget->clear();
	ui->moduleListWidget->addItems(app->moduleManager()->modulesList());
}

XR_WIDGET_IMPL(XRInfoWidget)
