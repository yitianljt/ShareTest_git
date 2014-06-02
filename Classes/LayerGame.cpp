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
#include "SpriteBlock.h"
#include "CommonTool.h"
#include <vector>

USING_NS_CC;



COM_CREATE_FUNC_IMPL(LayerGame);


LayerGame::LayerGame()
{
    m_pSpriteBatchNode = NULL;
}
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
    
    _spRuner = SpriteRunner::create();
    
    _spRuner->setPosition(ccp(200,400));
    _spRuner->setRotation(45);
    addChild(_spRuner);
    
    this->setTouchEnabled(true);
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    //this->m_pSpriteBatchNode=CCSpriteBatchNode::create("main.png", 100);

    this->m_pSpriteBatchNode = CCSpriteBatchNode::create("player@2x.png", 100);
    addChild(m_pSpriteBatchNode);
    start();
    
    glLineWidth( 5.0f );
    ccDrawColor4F(255,0,0,40);
    ccDrawLine(ccp(0, 0), ccp(200, 400));
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
    this->schedule(schedule_selector(LayerGame::addBlock), 3.0f );
}

void LayerGame::stop()
{
    this->unschedule(schedule_selector(LayerGame::update));
}


void LayerGame::update(float fDelta)
{
    
    CCArray* blockNodes = m_pSpriteBatchNode->getChildren();
    CCObject* child;
    CCARRAY_FOREACH(blockNodes,child )
    {
        SpriteBlock* spBlock = dynamic_cast<SpriteBlock*>(child);
        if (spBlock && isCollison(spBlock, _spRuner)) {
            _spRuner->dead();

        }
    }
    
    
    
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
    _spRuner->jump();
}

void LayerGame::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    
}


void LayerGame::addBlock(float fDelta)
{
    SpriteBlock* spBlock = SpriteBlock::create();
    //spBlock->setRotation(45);
    
    m_pSpriteBatchNode->addChild(spBlock);
    spBlock->setPosition(ccp(BSWinSize().width, 400));
    spBlock->move(-3.0f);
}


bool LayerGame::isCollison(CCSprite* spRuner,CCSprite* spBlock)
{
//    if ((sp1->getPositionX()-sp2->getPositionX()) * (sp1->getPositionX()-sp2->getPositionX()) < (sp1->getPositionY()- sp2->getPositionY())* (sp1->getPositionY()-sp2->getPositionY()) < (sp1->getCollderBox().actual.size.width)*(sp1->getCollderBox().actual.size.width)) {
//        CCLOG("Test");
//        return true;
//    }
    
    
    CCLOG("pt.x=%f,pt.y=%f, w=%f ,h=%f",spRuner->boundingBox().origin.x,spRuner->boundingBox().origin.y,spRuner->boundingBox().size.width,spRuner->boundingBox().size.height);
    
    CCLOG("pt.x=%f,pt.y=%f, w=%f ,h=%f",spBlock->boundingBox().origin.x,spBlock->boundingBox().origin.y,spBlock->boundingBox().size.width,spBlock->boundingBox().size.height);
    
    if (spRuner->boundingBox().intersectsRect(spBlock->boundingBox()) )
    {
        _spRuner->dead();
        gameover();
    }
    
    
    
    return false;
}


void LayerGame::gameover()
{
    
}

