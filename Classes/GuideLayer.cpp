//
//  GuideLayer.cpp
//  ShareTest
//
//  Created by jintao on 14-5-25.
//
//

#include "GuideLayer.h"
#include "cocos2d.h"
#include "CCScale9Sprite.h"
USING_NS_CC;
USING_NS_CC_EXT;

COM_CREATE_FUNC_IMPL(GuideLayer);

bool GuideLayer::init()
{
    CCSize sizeWin = CCDirector::sharedDirector()->getWinSize();

    if (!CCLayer::init()) {
        return false;
    }
    
//    CCScale9Sprite * spBg = CCScale9Sprite::create("HTP1_4.png");
//
//    
//    CCTableView *tableview = CCTableView::create(this, CCSizeMake(spBg->getContentSize().width*10, spBg->getContentSize().height));
//    tableview->setDirection(kCCScrollViewDirectionHorizontal); //设置tableview的方向是竖直方向，当然也有水平方向
//    tableview->setDelegate(this);
//    
//    tableview->setPosition(ccp(0,0));
//
//    
//    tableview->reloadData();
//    this->addChild(tableview);
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCTableView* tableView = CCTableView::create(this, winSize);//创建一个CCTableView
    tableView->setDirection(kCCScrollViewDirectionHorizontal);//设置方向
    tableView->setPosition(ccp(0,winSize.height/2-50));
    tableView->setDelegate(this);//这句话很重要，把taleView和当前类绑到一起，所以后面的调用主体都是tableView
    this->addChild(tableView);
    tableView->reloadData();

    
    
    return true;
    
}


void GuideLayer::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
    
}


CCSize GuideLayer::tableCellSizeForIndex(CCTableView *table, unsigned int idx)
{
    CCSize sizeWin = CCDirector::sharedDirector()->getWinSize();
   // CCLog("%f ,%f",sizeWin.width,sizeWin.height);
    CCScale9Sprite * spBg = CCScale9Sprite::create("HTP1_4.png");
    
    CCLog("%f, %f",spBg->getContentSize().width,spBg->getContentSize().height);
//return spBg->getContentSize();
    return CCSizeMake(120, 120);//其余为120，120

}

CCTableViewCell* GuideLayer::tableCellAtIndex(CCTableView *table, unsigned int idx)
{
    /*
    CCSize sizeWin = CCDirector::sharedDirector()->getWinSize();

    CCTableViewCell* cell = table->dequeueCell();
    if (!cell) {
        
        cell = new CCTableViewCell();
        cell->autorelease();
        
        
        CCString* strName = CCString::createWithFormat("HTP%d_4.png",(idx%3)+1);
        CCLog("name = %s; idx = %d",strName->getCString(),idx);
        //CCSprite* spBg = CCSprite::create(strName->getCString());
        CCScale9Sprite * spBg = CCScale9Sprite::create(strName->getCString());
        //spBg->setContentSize(CCSizeMake(sizeWin.width,sizeWin.height));
        
        CCLog("cell.width = %f,cell.height = %f",cell->getContentSize().width,cell->getContentSize().height);
        spBg->setPosition(ccp(spBg->getContentSize().width/2,spBg->getContentSize().height/2));
        
        CCString* string = CCString::createWithFormat("%d",idx);
        CCLabelTTF *label = CCLabelTTF::create(string->getCString(), "Helvetica", 70.0);
        label->setColor(ccc3(255, 0, 0));
        label->setPosition(ccp(50,50));
        label->setTag(456);
        
        cell->addChild(spBg);
        cell->addChild(label);
        return cell;
    }
    
    else
    {
        CCString* string = CCString::createWithFormat("%d",idx);

        CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(456);
        label->setString(string->getCString());
    }
    return cell;
     */
    
    
    CCString *string = CCString::createWithFormat("%d", idx);
    CCTableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = new CCTableViewCell();//创建单元，如果要自定义单元效果，需继承CCTableViewCell，并重载draw函数
        cell->autorelease();
        CCSprite *sprite = CCSprite::create("HelloWorld.png");
        sprite->setScale(0.2f);
        sprite->setPosition(ccp(60, 60));
        sprite->setTag(123);
        cell->addChild(sprite);//添加到cell
        CCLabelTTF *label = CCLabelTTF::create(string->getCString(), "Helvetica", 20.0);
        label->setPosition(ccp(60,10));
        label->setTag(456);
        cell->addChild(label);//添加到cell
    }
    else
    {
        CCLabelTTF *label = (CCLabelTTF*)cell->getChildByTag(456);
        label->setString(string->getCString());
    }
    return cell;
}


unsigned int GuideLayer::numberOfCellsInTableView(CCTableView *table)
{
    return 20;//直接返回设定单元数
}






