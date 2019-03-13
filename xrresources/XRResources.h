#ifndef XRRESOURCES_H
#define XRRESOURCES_H

#include "xrresources_global.h"

#define INIT_RESOURCES \
	Q_INIT_RESOURCE(pixmap);

namespace Resource {
	namespace Pixmap {
		enum Enum {
			SplashScreen,
			IconConnected,
			IconDisconnected,
			IconTransferNone,
			IconTransferBoth,
			IconTransferIn,
			IconTransferOut
		};
	}
}

constexpr const char *GetResource(Resource::Pixmap::Enum id)
{
	const char *data = nullptr;

	switch(id) {
	case Resource::Pixmap::SplashScreen: data = ":/pixmap/splash.png"; break;
	case Resource::Pixmap::IconConnected: data = ":/pixmap/icon-connected-16.png"; break;
	case Resource::Pixmap::IconDisconnected: data = ":/pixmap/icon-disconnected-16.png"; break;
	case Resource::Pixmap::IconTransferNone: data = ":/pixmap/icon-connected-no-data-16.png"; break;
	case Resource::Pixmap::IconTransferBoth: data = ":/pixmap/icon-data-transfer-16.png"; break;
	case Resource::Pixmap::IconTransferIn: data = ":/pixmap/icon-incoming-data-16.png"; break;
	case Resource::Pixmap::IconTransferOut: data = ":/pixmap/icon-outgoing-data-16.png"; break;
	}

	return data;
}

#endif // XRRESOURCES_H
