//
//  SpriteRunner.cpp
//  ShareTest
//
//  Created by jintao on 14-5-28.
//
//

#include "SpriteRunner.h"
#include "CommonTool.h"

#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
USING_NS_CC;

SpriteRunner::SpriteRunner()
{
    m_fVelocity = 0.0f;
    _ptJump = CCPoint(0, 0);
    _runnerState = kRunerWalk;
}
SpriteRunner::~SpriteRunner()
{}

bool SpriteRunner::init() {
    if (initWithFile("player@2x.png")) {
        this->m_fCenterToSides = this->getContentSize().width/2;
        this->m_fCenterToBottom = this->getContentSize().height/2;
        this->m_sColliderBox = createBoundingBoxWith(CCPoint(-this->m_fCenterToSides, -this->m_fCenterToBottom), CCSize(this->m_fCenterToSides*2, this->m_fCenterToBottom*2));
        
        // m_iState=kRunerWalk;
        return true;
    }
    
    return false;
}
/*
void SpriteRunner::findTarget(cocos2d::CCPoint &pos) {
    this->setPosition(pos, CCDirector::getInstance()->getVisibleSize());
}

void SpriteRunner::move() {
    this->stopAllActions();
    this->runAction(Sequence::create(MoveTo::create(m_fDuration, Point(this->getPositionX(), this->m_fCenterToBottom+VisibleRect::leftBottom().y)), CallFunc::create(CC_CALLBACK_0(SpriteArrow::fadeOut, this)), NULL));
}

void SpriteRunner::move(float duration) {
    this->m_fDuration = duration;
    this->move();
}

void SpriteRunner::fadeOut() {
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("end.mp3");
    this->m_bValid = false;
    this->runAction(Sequence::create(FadeOut::create(0.3f), CallFunc::create(CC_CALLBACK_0(SpriteArrow::onFadeOut, this)), NULL));
}

void SpriteRunner::onFadeOut() {
    SceneMain* sceneMain = dynamic_cast<SceneMain*>(getScene());
    
    if(sceneMain) {
        sceneMain->updateArrowsNumShow();
    }
    this->removeFromParent();
}*/



void SpriteRunner::jump()
{
    this->stopAllActions();
    
    bool bDouble = true;
//    if (!((bDouble && _runnerState == kRunerJump) || _runnerState == kRunerWalk )) {
//        return;
//    }
    
    if (_runnerState == kRunerWalk) {
        _ptJump = this->getPosition();
    }
    else if (_runnerState == kRunerJump)
    {
        //this->setRotation(0.0f);
    }
    _runnerState = kRunerJump;
        CCActionInterval* jumpto = CCJumpTo ::create(1, _ptJump, 200, 1 );
    CCActionInterval * rotateBy1 = CCRotateBy::create(0.5, 180);
    
    CCActionInterval * rotateBy2 = CCRotateBy::create(0.5, 180);

    
    

    //std::function<int (int)> func = () => 5 * 3;;
    //[]{std::cout<<"Hello from Lambda!"<<std::endl;}();
	CCCallLambda *flipCall_ = CCCallLambda::create([this]{
        this->setRotation(0);
        _runnerState = kRunerWalk;
    
    });
    
    
    CCFiniteTimeAction * spawn =CCSpawn::create(jumpto ,CCSequence::create(rotateBy1,rotateBy2,NULL),NULL);

    this->runAction(CCSequence::create(spawn,flipCall_,NULL));
    
}