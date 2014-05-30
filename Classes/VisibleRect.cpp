//
//  VisibleRect.cpp
//  ShareTest
//
//  Created by jintao on 14-5-28.
//
//
#include "VisibleRect.h"

USING_NS_CC;

CCRect VisibleRect::s_visibleRect;

void VisibleRect::lazyInit() {
    if(s_visibleRect.size.width==0.0f&&s_visibleRect.size.height==0.0f) {
        auto director = CCDirector::sharedDirector();
        auto glView = director->getOpenGLView();
        s_visibleRect.origin = glView->getVisibleOrigin();
        s_visibleRect.size = glView->getVisibleSize();
    }
}

CCRect VisibleRect::getVisibleRect() {
    lazyInit();
    return CCRect(s_visibleRect.origin.x, s_visibleRect.origin.y, s_visibleRect.size.width, s_visibleRect.size.height);
}

CCPoint VisibleRect::left() {
    lazyInit();
    return CCPoint(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

CCPoint VisibleRect::right() {
    lazyInit();
    return CCPoint(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

CCPoint VisibleRect::top() {
    lazyInit();
    return CCPoint(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height);
}

CCPoint VisibleRect::bottom() {
    lazyInit();
    return CCPoint(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y);
}

CCPoint VisibleRect::center() {
    lazyInit();
    return CCPoint(s_visibleRect.origin.x+s_visibleRect.size.width/2, s_visibleRect.origin.y+s_visibleRect.size.height/2);
}

CCPoint VisibleRect::leftTop() {
    lazyInit();
    return CCPoint(s_visibleRect.origin.x, s_visibleRect.origin.y+s_visibleRect.size.height);
}

CCPoint VisibleRect::rightTop() {
    lazyInit();
    return CCPoint(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y+s_visibleRect.size.height);
}

CCPoint VisibleRect::leftBottom() {
    lazyInit();
    return s_visibleRect.origin;
}

CCPoint VisibleRect::rightBottom() {
    lazyInit();
    return CCPoint(s_visibleRect.origin.x+s_visibleRect.size.width, s_visibleRect.origin.y);
}