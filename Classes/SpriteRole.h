//
//  SpriteRole.h
//  ShareTest
//
//  Created by jintao on 14-5-28.
//
//

#ifndef __ShareTest__SpriteRole__
#define __ShareTest__SpriteRole__

#include <iostream>
#include "cocos2d.h"
#include "Common.h"

class SpriteRole : public cocos2d::CCSprite
{
public:
    SpriteRole();
    ~SpriteRole();
    
    virtual void onEnter();
    virtual void setPosition(const cocos2d::CCPoint& pos);
    void setPosition(const cocos2d::CCPoint& pos, const cocos2d::CCSize& boundingSize);

    void transformBoxes();
    //boundingbox
    ColliderBox createBoundingBoxWith(cocos2d::CCPoint posOrigin, cocos2d::CCSize szSize);
    
    
protected:
    cocos2d::CCArray* m_aActions;
    float m_fCenterToSides;
    float m_fCenterToBottom;
    ColliderBox m_sColliderBox;


};

#endif /* defined(__ShareTest__SpriteRole__) */
