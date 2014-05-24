//
//  IOSVideoController.h
//  ShareTest
//
//  Created by jintao on 14-5-24.
//
//

#ifndef __ShareTest__IOSVideoController__
#define __ShareTest__IOSVideoController__

#include <iostream>

#import "MediaPlayer/MediaPlayer.h"
#import "cocos2d.h"
#include "SimpleAudioEngine.h"
using namespace cocos2d;
using namespace CocosDenshion;

@interface IOSVideoController :MPMoviePlayerViewController
{
    MPMoviePlayerController *movePlayer;
    UIWindow *window;
    CCLayer *TargetLayer;
}

//播放网络视频
-(void)playUrlVideo;

//在当前场景上播放视频，播完或者点击跳过视频 到指定的场景
-(void)playVideo:(NSString *)filename :(CCLayer *)targetLayer;
@end



#endif /* defined(__ShareTest__IOSVideoController__) */
