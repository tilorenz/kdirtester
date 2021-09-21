#include "kdirtestplugin.h"
#include "dirtester.h"
#include <qqml.h>

void WDNPlugin::registerTypes(const char *uri){
    Q_ASSERT(QLatin1String(uri) == QLatin1String("com.github.tilorenz.kdirtestplugin"));

    qmlRegisterType<DirTester>(uri, 1, 0, "KDirTest");

    qmlProtectModule("com.github.tilorenz.kdirtestplugin", 1);
}
//#include "wdnplugin.moc"

