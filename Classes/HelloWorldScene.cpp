#include "HelloWorldScene.h"
#include "misc_nodes/CCRenderTexture.h"
USING_NS_CC;



#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "android/log.h"
#include "platform/android/jni/JniHelper.h"

void share()
{
    bool hasMethod;
    
    hasMethod  = JniHelper::getStaticMethodInfo(jni_methodInfo, "com/jni/test/jnitest", "Share", "()V")
    
    if (hasMethod) {
        CCLog("function Share() was found");
        if(jni_methodInfo.methodID){
            jni_methodInfo.env->CallStaticVoidMethod(jni_methodInfo.classID,  jni_methodInfo.methodID);
            CCLog("function Share() was called");
    }
    else
    {
        CCLog("function Share() was not found");
    }
        
    
}


#endif

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
    
    
//    CCSize size = CCDirector::sharedDirector()->getWinSize();
//    CCRenderTexture* in_texture = CCRenderTexture::create((int)size.width, (int)size.height,kCCTexture2DPixelFormat_RGBA8888);
//    //renderTextureWithWidthAndHeight((int)size.width, (int)size.height,kCCTexture2DPixelFormat_RGBA8888);
//    in_texture->getSprite()->setAnchorPoint( ccp(0.5f,0.5f) );
//    in_texture->setPosition( ccp(size.width/2, size.height/2) );
//    in_texture->setAnchorPoint( ccp(0.5f,0.5f) );
//    
//    in_texture->begin();
//    this->visit();
//    in_texture->end();
//    
//    
//    in_texture->saveToFile("test11.png", kCCImageFormatPNG);
//    //CCLog("%d",in_texture->saveBuffer(kCCImageFormatPNG,"share.png",0,0,800,480));
//    
//    
    
    
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
   // Share();
#endif
    
    
    //share test
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
