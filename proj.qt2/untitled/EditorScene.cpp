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

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	

	// add "HelloWorld" splash screen"
	sprite = Sprite::create("CloseNormal.png");

	// position the sprite on the center of the screen
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(sprite, 0);
	
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