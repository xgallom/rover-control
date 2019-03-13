#include "XRModuleWorker.h"

#include "XRModule.h"

XRModuleWorker::XRModuleWorker(XRModule *parent)
	: XRObject(nullptr)
	, m_module(parent)
{}

XRModule *XRModuleWorker::module() const
{
	return m_module;
}
