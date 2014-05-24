//
//  Common.h
//  ShareTest
//
//  Created by jintao on 14-5-24.
//
//

#ifndef ShareTest_Common_h
#define ShareTest_Common_h




#define COM_CREATE_FUNC(className)\
public:\
virtual bool init();\
static className* create();\


#define COM_CREATE_FUNC_IMPL(className)\
className* className::create() {\
className* node = new className();\
node->init();\
node->autorelease();\
return node;\
}\


#endif
