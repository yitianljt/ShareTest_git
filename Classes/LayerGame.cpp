//
//  LayerGame.cpp
//  ShareTest
//
//  Created by jintao on 14-5-18.
//
//

#include "LayerGame.h"
#include "Common.h"
#include "PlayVideo.h"
#include "GameControl.h"
#include "BaseComScene.h"
#include "GroundLayer.h"
#include "CommonTool.h"
#include "SpriteRunner.h"

USING_NS_CC;



COM_CREATE_FUNC_IMPL(LayerGame);


LayerGame::LayerGame()
{}
LayerGame::~LayerGame(){}

bool LayerGame::init()
{
    CCSize sizeWin = CCDirector::sharedDirector()->getWinSize();
    if (!CCLayer::init()) {
        return false;
    }
    //背景
    CCLayerGradient* layer1 = CCLayerGradient::create(ccc4(160,210,210,255), ccc4(110,210,190,255), ccp(.0f, .0f));
    addChild(layer1, 0);
    
    GroundLayer* layerGround = GroundLayer::create();
    addChild(layerGround);
    
    spRuner = SpriteRunner::create();
    
    spRuner->setPosition(ccp(200,400));
    addChild(spRuner);
    
    this->setTouchEnabled(true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);

    /*
    
    CCLayerColor* layerBg = CCLayerColor::create(ccc4(0, 255, 255, 255), sizeWin.width, sizeWin.height);
    addChild(layerBg,0);
    CCSprite* spNormal = CCSprite::create();
    CCMenuItemSprite* btnStart = CCMenuItemSprite::create(spNormal,spNormal,this,menu_selector(LayerGame::callbackStart));
    btnStart->setPosition(ccp(sizeWin.width/2,sizeWin.height/2));
    
    CCMenuItemLabel* menuItem = CCMenuItemLabel::create(CCLabelTTF::create("播放视频", "黑体", 40), this, menu_selector(LayerGame::callbackStart));
    
    CCMenu* menu = CCMenu::create(menuItem,NULL);
    
    menu->setPosition(ccp(sizeWin.width/2, sizeWin.height/2));
    this->addChild(menu);
    */
    
    start();
    
    
    return true;
    
    
}

void LayerGame::onEnter()
{
    CCLayer::onEnter();
}
void LayerGame::onExit()
{
    CCLayer::onExit();
}

void LayerGame::callbackStart(CCObject* obj)
{
    PlayVideo::playVideo("opening_video.mp4",(CCLayer*)this);
}

void LayerGame::start()
{
    this->schedule(schedule_selector(LayerGame::update), 0.1f);
    //this->schedule(schedule_selector(LayerGame::addArrows), 0.2f);
}

void LayerGame::stop()
{
    this->unschedule(schedule_selector(LayerGame::update));
}


void LayerGame::update(float fDelta)
{
    /*
    CCLog("%f  =%f",spRuner->getPositionY(),spRuner->getVelocity());
    
    if (spRuner->getPositionY()> 100 && spRuner->getVelocity()<=0) {
        float g = -10.0f;
        //g*fDelta = dv;dv*fDlta = ds;
        
        spRuner->setVelocity(spRuner->getVelocity()+g*fDelta);
        CCLog("%f v=%f",g*fDelta,spRuner->getVelocity());

        spRuner->setPositionY(spRuner->getPositionY()+spRuner->getVelocity()*fDelta);
    }
    else
    {
         //spRuner->setVelocity(0.0f);
    }
    
    */
    
}

bool LayerGame::ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent)
{
    return true;
}


void LayerGame::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    spRuner->jump();
}

void LayerGame::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
}


