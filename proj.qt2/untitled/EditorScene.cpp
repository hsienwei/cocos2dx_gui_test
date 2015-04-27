#include "EditorScene.h"

USING_NS_CC;
using namespace std;


static EditorLayer *instance = nullptr;


EditorLayer* EditorLayer::getInstance()
{
	return instance;
}

Scene* EditorLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = EditorLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool EditorLayer::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	instance = this;

	Size visibleSize = Director::getInstance()->getWinSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	

	// add "HelloWorld" splash screen"
	sprite = Sprite::create("CloseNormal.png");

	// position the sprite on the center of the screen
	
	// add the sprite as a child to this layer
	this->addChild(sprite, 0);

	cocos2d::DrawNode *BaseLine = cocos2d::DrawNode::create();
	BaseLine->drawLine(Vec2(-10000, 0), Vec2(10000, 0), cocos2d::Color4F::RED);
	BaseLine->drawLine(Vec2(0, -10000), Vec2(0, 10000), cocos2d::Color4F::GREEN);
	this->addChild(BaseLine);


	this->setPosition(visibleSize/2);

	auto listener1 = EventListenerTouchOneByOne::create();
	// When "swallow touches" is true, then returning 'true' from the onTouchBegan method will "swallow" the touch event, preventing other listeners from using it.
	listener1->setSwallowTouches(true);

	listener1->onTouchBegan = [](Touch* touch, Event* event){

		return true;
	};

	listener1->onTouchMoved = [](Touch* touch, Event* event){
		auto target = static_cast<Layer*>(event->getCurrentTarget());
		//Move the position of current button sprite
		target->setPosition(target->getPosition() + touch->getDelta());
	};

	auto listener2 = EventListenerMouse::create();
	listener2->onMouseScroll = [](Event* event){
		auto target = static_cast<Layer*>(event->getCurrentTarget());
		//Move the position of current button sprite
		EventMouse* e = (EventMouse*)event;

		//target->setScale(e->getScrollY());
		log("%f", e->getScrollY());
		
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener2, this);
	return true;
}


void EditorLayer::update(float dt)
{

}



void EditorLayer::testAdd()
{

	auto label = Label::createWithSystemFont("aaa", "arial", 18);
	Vec2 pos = Vec2(CCRANDOM_0_1() * 200, CCRANDOM_0_1() * 200);
	label->setPosition(pos);
	this->addChild(label);
}

void EditorLayer::testAction()
{
	auto move = MoveBy::create(1, Vec2(50, 0));
	sprite->runAction(move);
	
}