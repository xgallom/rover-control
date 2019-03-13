#ifndef XRMODULEMANAGER_H
#define XRMODULEMANAGER_H

#include "xrcore_global.h"
#include "XRObject.h"
#include "XRModule.h"
#include <QString>
#include <QHash>
#include <QVector>

/**
 * @brief The XRModuleManager class manages provides XRModules to classes needing between module communication
 */
class XRCORESHARED_EXPORT XRModuleManager : public XRObject
{
	Q_OBJECT
public:
	XRModuleManager(XRObject *parent = nullptr);

	void registerModule(const QString &name, XRModule *module);
	XRModule *getModuleByName(const QString &name) const;
	bool hasModule(const QString &name) const;
	QVector<QString> modules() const;
	QStringList modulesList() const;

	template<typename T>
	T *getWorkerByType() { XRModule *m; return qobject_cast<T *>((m = getModuleByName(T::Name())) ? m->worker() : nullptr); }

signals:
	void moduleRegistered(const QString &name, XRModule *module);

private:
	QHash<QString, XRModule *> m_modules;
};

#endif // XRMODULEMANAGER_H
