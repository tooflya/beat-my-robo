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

static Resource resources480x320 = { CCSizeMake(320, 480),  "Graphics/480x320" };
static Resource resources1280x720 = { CCSizeMake(720, 1280),  "Graphics/1280x720" };
static Resource resources1280x720xPVRTC2 = { CCSizeMake(720, 1280),  "Graphics/1280x720-PVRTC2" };
static Resource resources2048x1536 = { CCSizeMake(720, 1280), "Graphics/2048x1536" };
static Resource resources1920x1080 = { CCSizeMake(720, 1280), "Graphics/1920x1080" };

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

        static bool IS_ALREADY_PLAYED;
    
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

        static void addCoins(int pCount, int pType);
        static void removeCoins(int pCount, int pType);

        static int getCoins(int pType);

        static void changeLanguage(int pId);
        static int getSelectedLanguage();

        static bool isInstalled();
        static void install(bool soft);

        static bool isItemBought(int pItem);
        static void buyItem(int pItem);

        static bool isItemSelected(int pItem);
        static void selectItem(int pItem);
    
        static bool isModeUnlocked(int pId);
        static void setModeUnlocked(int pId);

        static int getLevelStars(int pLevel);
        static int getLevelStarsTotalCount();
        static void setLevelStars(int pLevel, int pStars);

        static void setMusicEnable(bool pValue);
        static void setSoundEnable(bool pValue);

        static bool isMusicEnable();
        static bool isSoundEnable();

        static void setRate();

        static bool isRate();

        static void setBestResult(int pResult, int pType);

        static int getBestResult(int pType);
    
        static int getSelectedWeaponId();
    
        static bool IS_IPOD;
    
        static CCArray* getArrayOfBoughtBirds();
    
        static int getRandomBonusBird();
    
        static bool isSomeBonusBirdBought();
    
        static int getLastVisitDaysCount();
        static void setLastVisitDaysCount(int pCount);
    
        static string lastVersion();
    
        static bool tempPublisherInAppInformationShowed();
    
        static void setLivesMustRestore(int pIndex, bool pMust);
        static int getLivesRestoreTime(int pIndex);
        static bool isLiveRestoring(int pIndex);
        static int getLiveNearestReleaseTime(int pIndex);
    
		static bool isGetWindeScreen();

        static void clearCache();
    
        static void nativeOnGooglePlusSignInSucceeded();
    
        static bool isAdvertisiment();
    
        static int getTotalBirdsKilled();
        static int getTotalLevelsUnlocked();
    
        static void setTotalBirdsKilled();
        static void setTotalLevelsUnlocked();
    
        static void addTotalBirdsKilled(int add);
        static void addTotalLevelsUnlocked(int add);
    
        static bool isVideoShowed();
    
        // ===========================================================
        // Override Methods
        // ===========================================================

        bool applicationDidFinishLaunching();

        void applicationDidEnterBackground();
        void applicationWillEnterForeground();
};

#endif