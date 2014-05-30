//
//  LayerGame.h
//  ShareTest
//
//  Created by jintao on 14-5-18.
//
//

#ifndef __ShareTest__LayerGame__
#define __ShareTest__LayerGame__

#include <iostream>
#include "Common.h"
#include "cocos2d.h"
#include "SpriteRunner.h"



class LayerGame:public cocos2d::CCLayer
{
public:
    LayerGame();
    ~LayerGame();
    COM_CREATE_FUNC(LayerGame);
    
    
    
    virtual void onEnter();
    virtual void onExit();
    
    //void retry();

    void start();
    void stop();
    
    void update(float fDelta);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);


    
    void callbackStart(cocos2d::CCObject* obj);
    
private:
    SpriteRunner* spRuner;
    
    
};


#endif /* defined(__ShareTest__LayerGame__) */
