#include <KDirModel>
#include <qabstractitemmodel.h>
#include <qnamespace.h>
#include <qqml.h>

class DirTester : public QObject{
	Q_OBJECT
	QML_ELEMENT

	public:
	DirTester(QObject *parent = nullptr):
		beModel(this)
	{}
	
    public Q_SLOTS:
    void activate();

	private:
	KDirModel beModel;
};

