//
//  CommonTool.h
//  ShareTest
//
//  Created by jintao on 14-5-29.
//
//

#ifndef __ShareTest__CommonTool__
#define __ShareTest__CommonTool__

#include <iostream>
#include "cocos2d.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

class CCCallLambda : public cocos2d::CCActionInstant
{
public:
    static CCCallLambda * create(const std::function<void(void)> & callback);
    virtual CCActionInstant * reverse(void);
    virtual CCObject * copyWithZone(cocos2d::CCZone *pZone);
    virtual void update(float time);
    
protected:
    CCCallLambda(const std::function<void(void)> &callback);
    
protected:
    std::function<void(void)> _callback;
};



#endif /* defined(__ShareTest__CommonTool__) */
