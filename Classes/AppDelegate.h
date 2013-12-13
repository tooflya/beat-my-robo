#ifndef CONST_APPDELEGATE_H
#define CONST_APPDELEGATE_H

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

#include <vector>

#include "Options.h"
#include "ScreenManager.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "InAppPurchaseEventHandler.h"
#include "GameCenter.h"
#endif

using namespace std;
using namespace cocos2d;
using namespace CocosDenshion;

class ScreenManager;

typedef struct tagResource {
    CCSize size;
    char directory[100];
} Resource;

static Resource resources1280x720 = { CCSizeMake(720, 1280),  "Graphics/1280x720" };

class AppDelegate : private CCApplication
{
        protected:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================

        // ===========================================================
        // Override Methods
        // ===========================================================

        private:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        // ===========================================================
        // Fields
        // ===========================================================
    
        #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        InAppPurchaseEventHandler* handler;
        #endif

        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================

        public:
        // ===========================================================
        // Inner Classes
        // ===========================================================

        // ===========================================================
        // Constants
        // ===========================================================

        static ScreenManager* screens;
    
        #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        static GameCenter* mGameCenter;
        #endif

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        AppDelegate();
        ~AppDelegate();

        // ===========================================================
        // Methods
        // ===========================================================
    
        static void setMusicEnable(bool pValue);
        static void setSoundEnable(bool pValue);
    
        static bool isMusicEnable();
        static bool isSoundEnable();
    
        static void changeLanguage(int pId);
        static int getSelectedLanguage();
    
        static bool isInstalled();
        static void install(bool soft);
    
        static string lastVersion();

        // ===========================================================
        // Override Methods
        // ===========================================================

        bool applicationDidFinishLaunching();

        void applicationDidEnterBackground();
        void applicationWillEnterForeground();
};

#endif