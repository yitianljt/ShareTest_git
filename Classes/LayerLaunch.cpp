//
//  LayerLaunch.cpp
//  ShareTest
//
//  Created by jintao on 14-5-18.
//
//

#include "LayerLaunch.h"
#include "GameControl.h"


USING_NS_CC;


COM_CREATE_FUNC_IMPL(LayerLaunch);


LayerLaunch::LayerLaunch()
{}
LayerLaunch::~LayerLaunch(){}

bool LayerLaunch::init()
{
    CCSize sizeWin = CCDirector::sharedDirector()->getWinSize();
    if (!CCLayer::init()) {
        return false;
    }
    
    
    CCLayerColor* layerBg = CCLayerColor::create(ccc4(255, 255, 255, 255), sizeWin.width/2, sizeWin.height/2);
    addChild(layerBg,0);
    CCSprite* spNormal = CCSprite::create();
    CCMenuItemSprite* btnStart = CCMenuItemSprite::create(spNormal,spNormal,this,menu_selector(LayerLaunch::callbackStart));
    
    btnStart->setPosition(ccp(sizeWin.width/2,sizeWin.height/2));
    layerBg->addChild(btnStart);
    
    
    return true;
    
    
}

void LayerLaunch::onEnter()
{}
void LayerLaunch::onExit()
{}

void LayerLaunch::callbackStart(CCObject* obj)
{
    CCDirector::sharedDirector()->replaceScene(GameControl::scene(kSceneGame));
}

