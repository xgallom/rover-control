#include "UiLoader.h"
#include "XRUi.h"
#include "XRMainWindow.h"
#include "XRContentInfoWidgetDelegate.h"
#include "XRCentralContentWidget.h"

void UiLoader::LoadUi(XRUiManager *uiManager)
{
	XRMainWindow *mainWindow = new XRMainWindow();
	new XRUi(uiManager, XRMainWindow::Name(), mainWindow);

	new XRCentralContentWidget(new XRContentInfoWidgetDelegate, mainWindow->centralWidget());
}
