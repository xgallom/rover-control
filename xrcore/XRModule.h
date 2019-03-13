#ifndef XRMODULE_H
#define XRMODULE_H

#include "xrcore_global.h"
#include "XRObject.h"

class XRModuleWorker;
class XRCoreApplication;
class XRThread;
class XRModuleManager;

/**
 * @brief The XRModule class is a single application module runing its worker in its own thread
**/
class XRCORESHARED_EXPORT XRModule : public XRObject
{
	Q_OBJECT
public:
	XRModule(XRModuleManager *parent, const QString &name);
	XRModule(XRCoreApplication *parent);
	~XRModule();

	void initialize();
	bool isInitialized() const;
	QString name() const;

	XRModuleWorker *worker() const;

protected:
	virtual XRModuleWorker *constructWorker() = 0;

private:
	XRThread *m_workerThread;
	XRModuleWorker *m_worker;
	const QString m_name;
};

#endif // XRMODULE_H
