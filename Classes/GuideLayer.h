//
//  GuideLayer.h
//  ShareTest
//
//  Created by jintao on 14-5-25.
//
//

#ifndef __ShareTest__GuideLayer__
#define __ShareTest__GuideLayer__

#include <iostream>
#include "cocos2d.h"
#include "Common.h"
#include "cocos-ext.h"

class GuideLayer:public cocos2d::CCLayer,public cocos2d::extension::CCTableViewDelegate,public cocos2d::extension::CCTableViewDataSource
{
    COM_CREATE_FUNC(GuideLayer);

    
    
    //触摸到某个cell的事件
    virtual void tableCellTouched(cocos2d::extension::CCTableView* table, cocos2d::extension::CCTableViewCell* cell) ;
    virtual cocos2d::CCSize tableCellSizeForIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    //定制每个cell的内容
    virtual cocos2d::extension::CCTableViewCell* tableCellAtIndex(cocos2d::extension::CCTableView *table, unsigned int idx);
    virtual unsigned int numberOfCellsInTableView(cocos2d::extension::CCTableView *table) ;
    
    
    
    //由于CCTableView是继承CCScrollView，所以要继承这两个方法
    virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view) {}
    virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view) {}

};

#endif /* defined(__ShareTest__GuideLayer__) */
