//
//  PlayVideo.h
//  ShareTest
//
//  Created by jintao on 14-5-24.
//
//

#ifndef __ShareTest__PlayVideo__
#define __ShareTest__PlayVideo__

#include <iostream>
#include "cocos2d.h"

class PlayVideo{
    public:
        static void playVideo(const char* filename,cocos2d::CCLayer* layer = NULL);

};

#endif /* defined(__ShareTest__PlayVideo__) */
