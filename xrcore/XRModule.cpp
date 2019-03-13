#include "XRModule.h"

#include "XRThread.h"
#include "XRModuleWorker.h"
#include "XRModuleManager.h"
#include "XRCoreApplication.h"

XRModule::XRModule(XRModuleManager *parent, const QString &name)
	: XRObject (parent)
	, m_workerThread(nullptr)
	, m_worker(nullptr)
	, m_name(name)
{	
	m_workerThread = new XRThread(this);

	parent->registerModule(m_name, this);
}

XRModule::XRModule(XRCoreApplication *parent)
	: XRObject(parent)
	, m_workerThread(nullptr)
	, m_worker(nullptr)
	, m_name(QString())
{
	m_workerThread = new XRThread(this);
}

XRModule::~XRModule()
{
	m_workerThread->quit();
	m_workerThread->wait();
}

void XRModule::initialize()
{
	if(isInitialized())
		return;

	m_worker = constructWorker();

	m_worker->moveToThread(m_workerThread);
	connect(m_workerThread, SIGNAL(finished()), m_worker, SLOT(deleteLater()));

	m_workerThread->start();
}

bool XRModule::isInitialized() const
{
	return m_worker;
}

QString XRModule::name() const
{
	return m_name;
}

XRModuleWorker *XRModule::worker() const
{
	return m_worker;
}
