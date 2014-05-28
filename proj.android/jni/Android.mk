LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/HelloWorldScene.cpp \
					../../Classes/BaseComScene.cpp \
					../../Classes/GameControl.cpp \
					../../Classes/GuideLayer.cpp \
					../../Classes/LayerGame.cpp \
					../../Classes/LayerLaunch.cpp \
					../../Classes/PlayVideo.cpp \
					../../Classes/SceneGame.cpp \
					../../Classes/SceneLaunch.cpp \
					../../Classes/VideoPlatform.cpp  \
					../../Classes/PlayVideo_android.cpp
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_CFLAGS += -std=c++11

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)

APP_STL := gnustl_static
APP_CPPFLAGS := -frtti -DCC_ENABLE_CHIPMUNK_INTEGRATION=1 -DCOCOS2D_DEBUG=1 -std=c++0x
