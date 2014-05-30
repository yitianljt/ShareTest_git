//
//  CommonTool.cpp
//  ShareTest
//
//  Created by jintao on 14-5-29.
//
//

#include "CommonTool.h"
#include <vector>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
USING_NS_CC;




CCCallLambda::CCCallLambda(const std::function<void (void)> &callback)
: _callback(callback)
{
}

CCCallLambda * CCCallLambda::create(const std::function<void(void)>& callback) {
    auto pRet = new CCCallLambda(callback);
    pRet->autorelease();
    return pRet;
}

//static CCCallLambda* create(const std::function<void(void)>& func);

CCActionInstant *CCCallLambda::reverse() {
    return CCCallLambda::create(_callback);
}

CCObject * CCCallLambda::copyWithZone(CCZone * pZone) {
    CCZone * pNewZone = NULL;
    CCCallLambda * pRet = NULL;
    
    if (pZone && pZone->m_pCopyObject) {
        pRet = (CCCallLambda*) (pZone->m_pCopyObject);
        pRet->_callback = _callback;
    } else {
        pRet = new CCCallLambda(_callback);
        pZone = pNewZone = new CCZone(pRet);
    }
    
    CCActionInstant::copyWithZone(pZone);
    CC_SAFE_DELETE(pNewZone);
    return pRet;
}

void CCCallLambda::update(float time) {
    CC_UNUSED_PARAM(time);
    _callback();
}
