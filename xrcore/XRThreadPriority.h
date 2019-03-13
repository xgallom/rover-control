#ifndef XRTHREADPRIORITY_H
#define XRTHREADPRIORITY_H

#include "xrcore_global.h"

namespace XRThreadPriority
{
/**
  @brief The XRThreadPriority::Enum is a list of possible priorities that a XRThread can run in
  */
enum XRCORESHARED_EXPORT Enum {
	IdlePriority = 0,		//	scheduled only when no other threads are running.
	LowestPriority,			//	scheduled less often than LowPriority.
	LowPriority,			// scheduled less often than NormalPriority.
	NormalPriority,			// the default priority of the operating system.
	HighPriority,			// scheduled more often than NormalPriority.
	HighestPriority,		// scheduled more often than HighPriority.
	TimeCriticalPriority,	// scheduled as often as possible.
	InheritPriority,		// use the same priority as the creating thread. This is the default.
};
}

#endif // XRTHREADPRIORITY_H
