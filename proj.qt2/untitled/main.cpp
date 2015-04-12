#include "mainwindow.h"
#include <QApplication>
#include "EditorDelegate.h"
#include "cocos2d.h"

USING_NS_CC;

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();*/

	EditorDelegate app( argc, argv );
	//Application::getInstance()->run();
	cocos2d::CCQApplication::getInstance()->run();

	return 0;//a.exec();
}
