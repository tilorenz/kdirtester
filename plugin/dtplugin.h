#ifndef DTPLUGIN_H
#define DTPLUGIN_H
#include <QQmlEngine>
#include <QQmlExtensionPlugin>
#include <qobjectdefs.h>


class DTPlugin: public QQmlExtensionPlugin{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

	public:
	void registerTypes(const char *uri) override;
};

#endif

