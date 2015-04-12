#include "EditorDelegate.h"
#include "EditorScene.h"
#include "CCQGLView.h"

USING_NS_CC;

/*EditorDelegate::EditorDelegate() 
{

}*/

EditorDelegate::~EditorDelegate()
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void EditorDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool EditorDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    /*auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
    }*/
	auto glview = CCQGLView::getInstance();
	glview->setBgColor(Color4B(50, 50, 50, 255));
	director->setOpenGLView(glview);

	_mainWindow.setGLView(glview->getGLWidget());
	_mainWindow.show();

    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
	auto scene = EditorLayer::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void EditorDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void EditorDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
