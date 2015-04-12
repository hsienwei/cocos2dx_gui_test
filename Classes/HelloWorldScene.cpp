#include "HelloWorldScene.h"

USING_NS_CC;
using namespace std;

struct Unit{
	Vec2 pos;
	Vec2 velocity;
	float speed;
};

class Flocking
{
public:
	vector<Unit> unitList;
	DrawNode *drawNode;

	Flocking()
	{
		unitList.clear();
	}

	void AddUnit()
	{
		if (unitList.size() == 0)
		{
			Unit u;
			u.pos = Vec2(300, 300);
			u.velocity = Vec2(1, 0);
			u.speed = 3;// CCRANDOM_0_1() * 3;
			unitList.push_back(u);
		}
		else
		{
			Unit u;
			u.pos = Vec2(CCRANDOM_0_1() * 200 - 100, CCRANDOM_0_1() * 200 - 100) + Vec2(300, 300);
			u.velocity = Vec2(CCRANDOM_0_1(), CCRANDOM_0_1() * 2 -1);
			u.velocity.normalize();
			u.speed = 4;// CCRANDOM_0_1() * 3 + 1;
			unitList.push_back(u);
		}
	}

	void update()
	{
		
		vector<Unit>::iterator itor;
		for (int i = 0; i < unitList.size(); ++i)
		{
			Vec2 separation = computeSeparation(i) * .4;
			Vec2 alignment = computeAlignment(i) * 0.7;
			Vec2 cohesion = computeCohesion(i)* 0.5;
			Unit &u = unitList.at(i);
			u.velocity += alignment;
			u.velocity += separation;
			u.velocity += cohesion;
			
			u.velocity.normalize();
		}

		

		for (int i = 1; i < unitList.size(); ++i)
		{
			Unit &u = unitList.at(i);
			u.pos.y += (u.velocity * u.speed).y;
		}
	}

	Vec2 computeSeparation(int idx)
	{
		int unitCount = 0;
		Vec2 separation = Vec2::ZERO;
		Unit &u = unitList.at(idx);

		for (int i = 0; i < unitList.size(); ++i)
		{
			if (idx == i)    continue;
			Unit &other = unitList.at(i);
			//if (u.pos.distance(other.pos) < 50)
			{
				
				separation.x += (other.pos.x - u.pos.x);
				separation.y += (other.pos.y - u.pos.y);
				unitCount++;
			}
		}
		
		if (unitCount > 0)
		{
			separation = separation / unitCount;
			separation.x *= -1;
			separation.y *= -1;
			separation.normalize();
		}
		return separation;
	}

	Vec2 computeAlignment(int idx)
	{
		int unitCount = 0;
		Vec2 alignment = Vec2::ZERO;
		Unit &u = unitList.at(idx);

		for (int i = 0; i < unitList.size(); ++i)
		{
			if (idx == i)    continue;
			Unit &other = unitList.at(i);
			//if (u.pos.distance(other.pos) < 500)
			{

				alignment.x += other.velocity.x;
				alignment.y += other.velocity.y;
				unitCount++;
			}
		}
		
		alignment = alignment / unitCount;
		alignment.normalize();
		return alignment;
	}


	Vec2 computeCohesion(int idx)
	{
		int unitCount = 0;
		Vec2 cohesion = Vec2::ZERO;
		Unit &u = unitList.at(idx);

		for (int i = 0; i < unitList.size(); ++i)
		{
			if (idx == i)    continue;
			Unit &other = unitList.at(i);
			
			//if (u.pos.distance(other.pos) > 150)
			{
				cohesion.x += other.pos.x;
				cohesion.y += other.pos.y;
				unitCount++;
			}
		}

		if (unitCount > 0)
		{
			cohesion = cohesion / unitCount;

			cohesion = Vec2(cohesion.x - u.pos.x, cohesion.y - u.pos.y);
			cohesion.normalize();
		}
		return cohesion;
	}

	void redraw()
	{
		drawNode->clear();
		vector<Unit>::iterator itor;
		for (itor = unitList.begin(); itor != unitList.end(); ++itor)
		{
			drawNode->drawCircle(itor->pos, 10, 360, 10, false, Color4F::BLUE);
			drawNode->drawLine(itor->pos, itor->pos + itor->velocity * 30, Color4F::GREEN);
		}
	}
};

static HelloWorld *instance = nullptr;

static Flocking flocking;
HelloWorld* HelloWorld::getInstance()
{
	return instance;
}

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();
	
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    /*auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);*/

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
	/*instance = this;

	flocking.drawNode = DrawNode::create();
	this->addChild(flocking.drawNode);

	for (int i = 0; i < 10; ++i)
	{
		flocking.AddUnit();
	}
	this->scheduleUpdate();*/
    return true;
}


void HelloWorld::update(float dt)
{
	flocking.update();
	flocking.redraw();
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void HelloWorld::testAdd()
{
	
	auto label = Label::createWithTTF("test", "fonts/Marker Felt.ttf", 24);
	Vec2 pos = Vec2(CCRANDOM_0_1() * 200, CCRANDOM_0_1() * 200);
	label->setPosition(pos);
	this->addChild(label);
}