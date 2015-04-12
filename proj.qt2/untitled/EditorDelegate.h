#ifndef  _EDITOR_DELEGATE_H_
#define  _EDITOR_DELEGATE_H_

#include "CCQApplication.h"
#include "cocos2d.h"
#include "mainwindow.h"

/**
@brief    The cocos2d Application.

The reason for implement as private inheritance is to hide some interface call by Director.
*/
class  EditorDelegate : private  cocos2d::CCQApplication
{
public:
	//EditorDelegate();
	EditorDelegate(int argc, char *argv[]) : cocos2d::CCQApplication(argc, argv) {};
	virtual ~EditorDelegate();

    virtual void initGLContextAttrs();

    /**
    @brief    Implement Director and Scene init code here.
    @return true    Initialize success, app continue.
    @return false   Initialize failed, app terminate.
    */
    virtual bool applicationDidFinishLaunching();

    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();

protected:
	MainWindow _mainWindow;
};

#endif // _EDITOR_DELEGATE_H_

