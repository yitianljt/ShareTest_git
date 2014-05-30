//
//  GroundLayer.cpp
//  ShareTest
//
//  Created by jintao on 14-5-28.
//
//

#include "GroundLayer.h"
#include "BaseComScene.h"

USING_NS_CC;

COM_CREATE_FUNC_IMPL(GroundLayer);




bool GroundLayer::init()
{
    if (CCLayer::init()) {
        return true;
    }
    
    return false;
}

void GroundLayer::onEnter()
{
    CCLayer::onEnter();
    
    this->setContentSize(CCDirector::sharedDirector()->getWinSize());
    //Bottom
    CCSprite* sp = CCSprite::create("blockBottom.png");
    CCLog("size = %f, %f",sp->getContentSize().width,sp->getContentSize().height);
    
    
    //sp->setContentSize(CCSize(sp->getContentSize().width-40,sp->getContentSize().height));
    //sp->setAnchorPoint(ccp(0.5, 0.5));
    //sp->setPosition(ccp(0, 0));
    
    CCPoint ptStart = CCPoint(sp->getContentSize().width/2-10,sp->getContentSize().height/2);
    sp->setPosition(ptStart);
    addChild(sp);
    
    CCSprite* sp2 = CCSprite::create("blockBottom.png");
    
    sp2->setPosition(sp->getPosition()+ccp(sp->getContentSize().width-20, 0));
    
    addChild(sp2);
    
    
}