//
//  LayerGame.cpp
//  ShareTest
//
//  Created by jintao on 14-5-18.
//
//

#include "LayerGame.h"


#include "GameControl.h"


USING_NS_CC;


LayerGame::LayerGame()
{}
LayerGame::~LayerGame(){}

bool LayerGame::init()
{
    CCSize sizeWin = CCDirector::sharedDirector()->getWinSize();
    if (!CCLayer::init()) {
        return false;
    }
    
    
    CCLayerColor* layerBg = CCLayerColor::create(ccc4(255, 255, 255, 255), sizeWin.width, sizeWin.height);
    addChild(layerBg,0);
    CCSprite* spNormal = CCSprite::create();
    CCMenuItemSprite* btnStart = CCMenuItemSprite::create(spNormal,spNormal,this,menu_selector(LayerGame::callbackStart));
    
    btnStart->setPosition(ccp(sizeWin.width/2,sizeWin.height/2));
    layerBg->addChild(btnStart);
    
    
    return true;
    
    
}

void LayerGame::onEnter()
{}
void LayerGame::onExit()
{}

void LayerGame::callbackStart(CCObject* obj)
{
    CCDirector::sharedDirector()->replaceScene(GameControl::scene(kSceneGame));
}



