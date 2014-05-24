//
//  PlayVideo.mm
//  ShareTest
//
//  Created by jintao on 14-5-24.
//
//

#include "PlayVideo.h"
#include "IOSVideoController.h"


USING_NS_CC;

void PlayVideo::playVideo(const char *filename,CCLayer* layer)
{
    CCLog("playVideo");
    
    //char * 转化为 NSString
    NSString *audioname=[NSString stringWithUTF8String:filename];
    IOSVideoController *app = [[IOSVideoController alloc] init];
    [app playVideo:audioname :layer];
}