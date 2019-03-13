#include "ModuleLoader.h"
#include "XRSerialRoverModule.h"
#include "XRSettingsModule.h"
#include "XRInfoModule.h"

#include "Application.h"
#include "XRModuleManager.h"
#include "XRSerialRoverWorker.h"
#include <QTimer>

void ModuleLoader::LoadModules(XRModuleManager *moduleManager)
{
	new XRSettingsModule(moduleManager);
	new XRSerialRoverModule(moduleManager);
	new XRInfoModule(moduleManager);

	QTimer::singleShot(2000, []() {
		QMetaObject::invokeMethod(app->moduleManager()->getWorkerByType<XRSerialRoverWorker>(), "write",
								  Qt::QueuedConnection, Q_ARG(const QByteArray &, "Data")
								  );
	});
}
