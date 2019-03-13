#ifndef APPLICATION_H
#define APPLICATION_H

#include "XRApplication.h"

class XRModule;
class XRUi;
class QSplashScreen;

class Application : public XRApplication
{
	Q_OBJECT
public:
	Application();

private:
	void loadModules();
	void loadUi();

private slots:
	void on_moduleRegistered(const QString &name, XRModule *module);
	void on_uiRegistered(const QString &name, XRUi *ui);

private:
	QSplashScreen *m_splashScreen;
};

#endif // APPLICATION_H
