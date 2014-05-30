//
//  SpriteBlock.h
//  ShareTest
//
//  Created by jintao on 14-5-29.
//
//

#ifndef __ShareTest__SpriteBlock__
#define __ShareTest__SpriteBlock__

#include <iostream>
#include "SpriteRole.h"
#include "cocos2d.h"

class SpriteBlock : public SpriteRole
{
public:
    SpriteBlock();
    ~SpriteBlock();
    virtual bool init();
    
    CREATE_FUNC(SpriteBlock);

    
    
private:
    
    
};
#endif /* defined(__ShareTest__SpriteBlock__) */
