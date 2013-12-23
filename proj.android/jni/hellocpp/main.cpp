#include "AppDelegate.cpp"
#include "Options.cpp"
#include "Utils.cpp"
#include "Touchable.cpp"
#include "Entity.cpp"
#include "Button.cpp"
#include "Text.cpp"
#include "EntityManager.cpp"
#include "BatchEntityManager.cpp"
#include "Screens/Screen.cpp"
#include "Menu.cpp"
#include "Credits.cpp"
#include "Loader.cpp"
#include "Loading.cpp"
#include "Languages.cpp"
#include "Game.cpp"
#include "Screens/Popup.cpp"
#include "ScreenManager.cpp"
#include "Texture.cpp"
#include "ButtonReceiver.cpp"
#include "Popup.cpp"
#include "GetGold.cpp"
#include "GetSilver.cpp"
#include "GameBackground.cpp"
#include "GameArea.cpp"
#include "SplashScreen.cpp"
#include "Garage.cpp"
#include "Properties.cpp"
#include "Cloud.cpp"
#include "InAppPurchasesList.cpp"
#include "InAppPurchaseEventHandler.cpp"
#include "SpriteBatch.cpp"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <platform/CCPlatformConfig.h>
#include <android/log.h>

#define  LOG_TAG    "main"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)

using namespace cocos2d;

extern "C"
{

jint JNI_OnLoad(JavaVM *vm, void *reserved)
{
    JniHelper::setJavaVM(vm);

    return JNI_VERSION_1_4;
}

void Java_org_cocos2dx_lib_Cocos2dxRenderer_nativeInit(JNIEnv*  env, jobject thiz, jint w, jint h)
{
    if (!CCDirector::sharedDirector()->getOpenGLView())
    {
        CCEGLView *view = CCEGLView::sharedOpenGLView();
        view->setFrameSize(w, h);

        AppDelegate *pAppDelegate = new AppDelegate();
        CCApplication::sharedApplication()->run();
    }
    else
    {
        ccDrawInit();
        ccGLInvalidateStateCache();
        
        CCShaderCache::sharedShaderCache()->reloadDefaultShaders();
        CCTextureCache::reloadAllTextures();
        CCNotificationCenter::sharedNotificationCenter()->postNotification(EVENT_COME_TO_FOREGROUND, NULL);
        CCDirector::sharedDirector()->setGLDefaultValues(); 
    }
}

}
