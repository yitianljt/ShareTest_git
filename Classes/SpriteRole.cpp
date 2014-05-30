//
//  SpriteRole.cpp
//  ShareTest
//
//  Created by jintao on 14-5-28.
//
//

#include "SpriteRole.h"
#include "VisibleRect.h"
USING_NS_CC;

SpriteRole::SpriteRole()
{}

SpriteRole::~SpriteRole()
{
}


void SpriteRole::onEnter(){
    CCSprite::onEnter();
}

void SpriteRole::setPosition(const CCPoint& pos, const CCSize& boundingSize){
    float xPos = pos.x;
    float yPos = pos.y;
    
    //FIX_VALUE(xPos, m_fCenterToSides+VisibleRect::left().x, boundingSize.width-m_fCenterToSides-VisibleRect::left().x);
    //FIX_VALUE(yPos, m_fCenterToBottom+VisibleRect::leftBottom().y, boundingSize.height-m_fCenterToBottom-VisibleRect::leftBottom().y);
    this->setPosition(CCPoint(xPos, yPos));
}


void SpriteRole::setPosition(const CCPoint& pos){
    CCSprite::setPosition(pos);
    this->transformBoxes();
}


void SpriteRole::transformBoxes()
{
    m_sColliderBox.actual.origin = this->getPosition()+CCPoint(m_sColliderBox.original.origin.x, m_sColliderBox.original.origin.y);
}




ColliderBox SpriteRole::createBoundingBoxWith(CCPoint posOrigin, CCSize szSize){
    ColliderBox boundingBox;
    boundingBox.original.origin = posOrigin;
    boundingBox.original.size = szSize;
    boundingBox.actual.origin = this->getPosition()+CCPoint(boundingBox.original.origin.x, boundingBox.original.origin.y);
    boundingBox.actual.size = szSize;
    return boundingBox;
}


