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
#include "cocos2d.h"


class LayerGame:public cocos2d::CCLayer
{
    public:
    LayerGame();
    ~LayerGame();
    
    virtual bool init();
    
    virtual void onEnter();
    virtual void onExit();
    
    void callbackStart(cocos2d::CCObject* obj);
    
};


#endif /* defined(__ShareTest__LayerGame__) */
