#include "dirtester.h"
#include <qobjectdefs.h>
#include <KDirLister>

void DirTester::activate(){
	QUrl testUrl = QUrl("file:///home/tino/projects/plasmoids/notes/testDir/");
	beModel.openUrl(testUrl);
	qDebug() << "RowCount: " << beModel.rowCount(QModelIndex()) << Qt::endl;
	QModelIndex rootIndex = beModel.indexForUrl(testUrl);
	qDebug() << "Root Index: " << rootIndex << Qt::endl;
	qDebug() << "Root File Name: " << beModel.itemForIndex(rootIndex).text();
}

