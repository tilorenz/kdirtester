#include "dtplugin.h"
#include "dirtreemodel.h"
#include <qqml.h>

void DTPlugin::registerTypes(const char *uri){
    Q_ASSERT(QLatin1String(uri) == QLatin1String("com.github.tilorenz.dtplugin"));

    qmlRegisterType<DirTreeModel>(uri, 1, 0, "DirTreeModel");

    qmlProtectModule("com.github.tilorenz.dtplugin", 1);
}



#include "dtplugin.moc"

