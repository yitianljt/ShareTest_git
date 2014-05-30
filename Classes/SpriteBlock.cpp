//
//  SpriteBlock.cpp
//  ShareTest
//
//  Created by jintao on 14-5-29.
//
//

#include "SpriteBlock.h"
USING_NS_CC;


SpriteBlock::SpriteBlock()
{}


SpriteBlock::~SpriteBlock()
{
    
}
bool SpriteBlock::init()
{
    if (initWithFile("player@2x.png")) {
        this->m_fCenterToSides = this->getContentSize().width/2;
        this->m_fCenterToBottom = this->getContentSize().height/2;
        this->m_sColliderBox = createBoundingBoxWith(CCPoint(-this->m_fCenterToSides, -this->m_fCenterToBottom), CCSize(this->m_fCenterToSides*2, this->m_fCenterToBottom*2));
        
        return true;
    }
    return false;
}
