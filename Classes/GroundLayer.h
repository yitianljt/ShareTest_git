//
//  GroundLayer.h
//  ShareTest
//
//  Created by jintao on 14-5-28.
//
//

#ifndef __ShareTest__GroundLayer__
#define __ShareTest__GroundLayer__

#include <iostream>
#include "Common.h"
#include "cocos2d.h"

class GroundLayer:public cocos2d::CCLayer
{
    COM_CREATE_FUNC(GroundLayer);
    
    
    virtual void onEnter();
    
    
    
};

#endif /* defined(__ShareTest__GroundLayer__) */
