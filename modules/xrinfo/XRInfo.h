#ifndef XRINFO_H
#define XRINFO_H

#include "xrinfo_global.h"
#include "XRObject.h"

struct XRInfoData {
	unsigned long freeRam, totalRam;
	unsigned long freeSwap, totalSwap;
	double cpuUsage;
	int cpuCores;
	unsigned int memUnit;
};
Q_DECLARE_METATYPE(XRInfoData);

class XRInfoWorker;

class XRINFOSHARED_EXPORT XRInfo : public XRObject
{
	Q_OBJECT
public:
	XRInfo(XRObject *parent = nullptr);

	XRInfoData data() const;

signals:
	void dataUpdated();

private slots:
	void on_data_updated(const XRInfoData &data);

private:
	XRInfoWorker *m_worker;
	XRInfoData m_data;
};

#endif // XRINFO_H
