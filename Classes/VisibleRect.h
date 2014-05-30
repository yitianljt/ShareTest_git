//
//  VisibleRect.h
//  ShareTest
//
//  Created by jintao on 14-5-28.
//
//

#ifndef __ShareTest__VisibleRect__
#define __ShareTest__VisibleRect__

#include <iostream>
#include "cocos2d.h"


class VisibleRect {
public:
    static cocos2d::CCRect getVisibleRect();
    
    static cocos2d::CCPoint left();
    static cocos2d::CCPoint right();
    static cocos2d::CCPoint top();
    static cocos2d::CCPoint bottom();
    static cocos2d::CCPoint center();
    static cocos2d::CCPoint leftTop();
    static cocos2d::CCPoint rightTop();
    static cocos2d::CCPoint leftBottom();
    static cocos2d::CCPoint rightBottom();
    
private:
    static void lazyInit();
    static cocos2d::CCRect s_visibleRect;
};


#endif /* defined(__ShareTest__VisibleRect__) */
