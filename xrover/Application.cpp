#include "Application.h"
#include "XRResources.h"

#include "ModuleLoader.h"
#include "XRModuleManager.h"

#include "UiLoader.h"
#include "XRUiManager.h"
#include "XRMainWindow.h"

#include "XRLog.h"
#include <QSplashScreen>

XR_MODULE(Application)

Application::Application()
	: XRApplication()
{
	INIT_RESOURCES

	m_splashScreen = new QSplashScreen(QPixmap(GetResource(Resource::Pixmap::SplashScreen)));
	m_splashScreen->show();

	m_splashScreen->showMessage("XRover: Loading", Qt::AlignBottom);

	connect(moduleManager(), SIGNAL(moduleRegistered(const QString &, XRModule *)),
			this, SLOT(on_moduleRegistered(const QString &, XRModule *))
			);
	connect(uiManager(), SIGNAL(uiRegistered(const QString &, XRUi *)),
			this, SLOT(on_uiRegistered(const QString &, XRUi *))
			);

	loadModules();
	loadUi();

	XRMainWindow *mainWindow = uiManager()->getWidgetByType<XRMainWindow>();
	m_splashScreen->finish(mainWindow);
	mainWindow->show();
}

void Application::loadModules()
{
	ModuleLoader::LoadModules(moduleManager());
}

void Application::loadUi()
{
	UiLoader::LoadUi(uiManager());
}

void Application::on_moduleRegistered(const QString &name, XRModule *)
{
	LOG_INFO("Module registered: " << name);
	m_splashScreen->showMessage("XRover: Loaded " + name, Qt::AlignBottom);
}

void Application::on_uiRegistered(const QString &name, XRUi *)
{
	LOG_INFO("Ui registered: " << name);
	m_splashScreen->showMessage("XRover: Loaded " + name, Qt::AlignBottom);
}


