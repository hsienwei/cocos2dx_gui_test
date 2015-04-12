#ifndef __EDITOR_SCENE_H__
#define __EDITOR_SCENE_H__

#include "cocos2d.h"

class EditorLayer : public cocos2d::Layer
{
public:
	static EditorLayer* getInstance();

	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
	virtual void update(float dt);
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(EditorLayer);


	

	void testAdd();
	void testAction();

	cocos2d::Sprite *sprite;
};

#endif // __EDITOR_SCENE_H__
