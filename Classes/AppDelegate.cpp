#ifndef CONST_APPDELEGATE
#define CONST_APPDELEGATE

#include "AppDelegate.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "CCStoreController.h"
#include "CCStoreInventory.h"
#include "CCStoreInfo.h"
#include "CCSoomla.h"
#include "InAppPurchasesList.h"
#endif

#include "SplashScreen.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ScreenManager* AppDelegate::screens = NULL;

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
GameCenter* AppDelegate::mGameCenter = new GameCenter();
#endif

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

AppDelegate::AppDelegate()
{
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    handler = new InAppPurchaseEventHandler();
    #endif
}

AppDelegate::~AppDelegate()
{
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    soomla::CCSoomla::sharedSoomla()->removeEventHandler(handler);
    #endif
}

// ===========================================================
// Methods
// ===========================================================

void AppDelegate::changeLanguage(int pId)
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey(Options::SAVE_DATA_LANGUAGE_ID, pId);
    
    CCUserDefault::sharedUserDefault()->flush();
}

int AppDelegate::getSelectedLanguage()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey(Options::SAVE_DATA_LANGUAGE_ID);
}

bool AppDelegate::isInstalled()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("installed") == 1;
}

void AppDelegate::install(bool soft)
{
    AppDelegate::changeLanguage(AppDelegate::getSelectedLanguage());
    
    CCUserDefault::sharedUserDefault()->setStringForKey("last_version", Options::STRING_VERSION);

    CCUserDefault::sharedUserDefault()->flush();
}

void AppDelegate::setMusicEnable(bool pValue)
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey("music_enable", pValue ? 1 : 0);
    
    CCUserDefault::sharedUserDefault()->flush();
}

void AppDelegate::setSoundEnable(bool pValue)
{
    CCUserDefault::sharedUserDefault()->setIntegerForKey("sound_enable", pValue ? 1 : 0);
    
    CCUserDefault::sharedUserDefault()->flush();
}

bool AppDelegate::isMusicEnable()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("music_enable") == 1;
}

bool AppDelegate::isSoundEnable()
{
    return CCUserDefault::sharedUserDefault()->getIntegerForKey("sound_enable") == 1;
}

string AppDelegate::lastVersion()
{
    return CCUserDefault::sharedUserDefault()->getStringForKey("last_version");
}

// ===========================================================
// Override Methods
// ===========================================================

bool AppDelegate::applicationDidFinishLaunching()
{
    CCDirector* director = CCDirector::sharedDirector();
    CCEGLView*  EGLView = CCEGLView::sharedOpenGLView();
    CCSize  screenSize = EGLView->getFrameSize();
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    soomla::CCSoomla::sharedSoomla()->addEventHandler(handler);
    
    InAppPurchasesList *assets = InAppPurchasesList::create();
    CCDictionary *storeParams = CCDictionary::create();
    
    storeParams->setObject(CCString::create(Options::SOOMLA_BASE_64_KEY), "soomSec");
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    storeParams->setObject(CCString::create(Options::GOOGLE_PLAY_BASE_64_KEY), "androidPublicKey");
    #endif
    storeParams->setObject(CCString::create(Options::SOOMLA_CUSTOM_BASE_64_KEY), "customSecret");
    
    #if COCOS2D_DEBUG >= 1 && CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    storeParams->setObject(CCBool::create(true), "androidTestMode");
    #endif
    
    soomla::CCStoreController::createShared(assets, storeParams);
    #endif
    
    Options::designResolutionSize = CCSizeMake(720, 1280);

	director->setOpenGLView(EGLView);
	director->setContentScaleFactor(Options::designResolutionSize.height / screenSize.height);
    
	Options::SCREEN_WIDTH = Options::designResolutionSize.width;
	Options::SCREEN_HEIGHT = Options::designResolutionSize.height;
    
	Options::SCREEN_CENTER_X = Options::designResolutionSize.width / 2;
	Options::SCREEN_CENTER_Y = Options::designResolutionSize.height / 2;
    
    Options::CAMERA_WIDTH  = screenSize.width;
    Options::CAMERA_HEIGHT = screenSize.height;
    
    Options::CAMERA_CENTER_X  = screenSize.width / 2;
    Options::CAMERA_CENTER_Y = screenSize.height / 2;

    vector <string> searchPath;
    
    searchPath.push_back(resources1280x720.directory);
    
    Options::DEVICE_TYPE = Options::DEVICE_TYPE_IPHONE5;

    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

    director->setDisplayStats(false);
    
    director->setProjection(kCCDirectorProjection2D);

    director->setAnimationInterval(1.0f / 60.0f);
    
    if(!AppDelegate::isInstalled() || AppDelegate::lastVersion() != Options::VERSION)
    {
        AppDelegate::install(false); // NOT SOFT INSTALLATION
    }

    Options::init();

    Screen* pScene = SplashScreen::create();

    director->runWithScene(pScene);

    return true;
}

void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();

    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();

    if(Options::MUSIC_ENABLE)
    {
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    }
    
    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    AppDelegate::mGameCenter->login();
    #endif
}

#endif