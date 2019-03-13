#ifndef XRUIMANAGER_H
#define XRUIMANAGER_H

#include "xrgui_global.h"
#include "XRObject.h"
#include "XRUi.h"
#include <QString>
#include <QHash>

/**
 * @brief The XRUiManager class provides XRUis to classes needing to access gui
 */
class XRGUISHARED_EXPORT XRUiManager : public XRObject
{
	Q_OBJECT
public:
	XRUiManager(XRObject *parent = nullptr);

	void registerUi(const QString &name, XRUi *ui);
	void removeUi(const QString &name);
	XRUi *getUiByName(const QString &name) const;
	bool hasUi(const QString &name) const;

	template<typename T>
	T *getWidgetByType() { XRUi *ui; return qobject_cast<T *>((ui = getUiByName(T::Name())) ? ui->widget() : nullptr); }

signals:
	void uiRegistered(const QString &name, XRUi *ui);

private:
	QHash<QString, XRUi *> m_uis;
};

#endif // XRUIMANAGER_H
