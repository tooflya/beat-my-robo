#ifndef CONST_OPTIONS
#define CONST_OPTIONS

#include "Options.h"

#include "Text.h"

#include "AppDelegate.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

const char* Options::GOOGLE_PLAY_BASE_64_KEY = "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAnxTibzwKbgWhSfNuVJmKOWXmRmCAsxT8Z8+jf5DRTKcsIm6BTJOC27d2wKeuH9Uw/7i39KmRUgg+zwAFxT3X8TLpC/pM/mSLpUSfv85iN3yRE85zCrW4NQsxLbyHqjPNNxoMzC5bLBh3pqSB0qSp/2ZC+woOncQKs/J6i3O/vDFuAmnyuJVUaNDTRYYpmOPmcZiMU/hC0PLiVQAnWcM/WDFmWm6h5lBmhRvTYnRdU2Ha+cax8UpAliceS+URRmeFCM0kV2hBhHRLNCXycGa9L4vCErJnH2mcBwOztHV5x7ZIHxMFxq4Kx7h1EyI6gzorrF28m5gP9TBTihAUXaC0XQIDAQAB";
const char* Options::SOOMLA_BASE_64_KEY = "?";
const char* Options::SOOMLA_CUSTOM_BASE_64_KEY = "?";

CCObject* Options::PAYMENT_PROCEED_HANDLER = NULL;

CCSize Options::designResolutionSize = CCSizeZero;

int Options::CENTER_X = 0;
int Options::CENTER_Y = 0;

int Options::SCREEN_WIDTH = 0;
int Options::SCREEN_HEIGHT = 0;

int Options::SCREEN_CENTER_X = 0;
int Options::SCREEN_CENTER_Y = 0;

int Options::CAMERA_WIDTH = 0;
int Options::CAMERA_HEIGHT = 0;

int Options::CAMERA_CENTER_X = 0;
int Options::CAMERA_CENTER_Y = 0;

int Options::DEVICE_TYPE = -1;

#if CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_WINRT

const char* Options::TEXTURES_EXTENSION = ".png";

#else

const char* Options::TEXTURES_EXTENSION = ".pvr.ccz";

#endif

bool Options::MUSIC_ENABLE = true;
bool Options::SOUND_ENABLE = true;

const char* Options::VERSION = "0.0.0";
string Options::STRING_VERSION = "0.0.0";

int Options::BUILD = 0;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)

const char* Options::FONT = "Comic Sans MS";

#else

const char* Options::FONT = "Fonts/Comic Sans MS.ttf";

#endif

int Options::CURRENT_LANGUAGE = 0;

const char* Options::SAVE_DATA_LANGUAGE_ID = "p_language_id";

Textes Options::TEXTES_HOLDER[600] =
{
    /*NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL*/
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Options::Options()
{
}

// ===========================================================
// Methods
// ===========================================================

void Options::init()
{
    Options::CURRENT_LANGUAGE = AppDelegate::getSelectedLanguage();
    
    if(CURRENT_LANGUAGE <= 0)
    {
        switch(CCApplication::sharedApplication()->getCurrentLanguage())
        {
            default:
                CURRENT_LANGUAGE = 0;
            break;
            case kLanguageRussian:
                CURRENT_LANGUAGE = 1;
            break;
        }
    }

    Options::MUSIC_ENABLE = AppDelegate::isMusicEnable();
    Options::SOUND_ENABLE = AppDelegate::isSoundEnable();

    #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC

    CCDictionary* pConfInfo = CCDictionary::createWithContentsOfFile("Info.plist");
    Options::BUILD = pConfInfo->valueForKey("CFBundleVersion")->intValue();

    #endif

    Options::changeLanguage();
}

void Options::changeLanguage()
{
    AppDelegate::changeLanguage(CURRENT_LANGUAGE);

    switch(Options::CURRENT_LANGUAGE)
    {
        case 0:
        break;
        case 1:
        break;
    }
    
    for(int i = 0; i <= 0; i++)
    {
        if(Text::TEXTES[i] != NULL)
        {
            Text::TEXTES[i]->changeLanguage();
        }
    }
}

// ===========================================================
// Override Methods
// ===========================================================

#endif