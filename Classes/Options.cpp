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

const char* Options::VERSION = "0.1.0";
string Options::STRING_VERSION = "0.1.0";

int Options::BUILD = 0;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_MAC || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)

const char* Options::FONT = "GrilledCheese BTN";

#else

const char* Options::FONT = "Fonts/Grilled Cheese.ttf";

#endif

int Options::CURRENT_LANGUAGE = 0;

const char* Options::SAVE_DATA_LANGUAGE_ID = "p_language_id";

Textes Options::TEXTES_HOLDER[600] = {};

Textes Options::TEXT_LANGUAGE_L_EN = { "", FONT, 23, 0 };
Textes Options::TEXT_LANGUAGE_L_RU = { "", FONT, 23, 1 };
Textes Options::TEXT_LANGUAGE_L_DE = { "", FONT, 23, 2 };
Textes Options::TEXT_LANGUAGE_L_ES = { "", FONT, 23, 3 };
Textes Options::TEXT_LANGUAGE_L_FR = { "", FONT, 23, 4 };
Textes Options::TEXT_LANGUAGE_L_NL = { "", FONT, 23, 5 };
Textes Options::TEXT_LANGUAGE_L_IT = { "", FONT, 23, 6 };
Textes Options::TEXT_LANGUAGE_L_JP = { "", FONT, 23, 7 };
Textes Options::TEXT_LANGUAGE_L_KR = { "", FONT, 23, 8 };
Textes Options::TEXT_LANGUAGE_L_CN = { "", FONT, 23, 9 };
Textes Options::TEXT_CREDITS_STRING_1 = { "", FONT, 0, 10 };
Textes Options::TEXT_CREDITS_STRING_2 = { "", FONT, 0, 11 };
Textes Options::TEXT_CREDITS_STRING_3 = { "", FONT, 0, 12 };
Textes Options::TEXT_CREDITS_STRING_4 = { "", FONT, 0, 13 };
Textes Options::TEXT_CREDITS_STRING_5 = { "", FONT, 0, 14 };
Textes Options::TEXT_CREDITS_STRING_6 = { "", FONT, 0, 15 };
Textes Options::TEXT_CREDITS_STRING_7 = { "", FONT, 0, 16 };
Textes Options::TEXT_CREDITS_STRING_8 = { "", FONT, 0, 17 };
Textes Options::TEXT_CREDITS_STRING_9 = { "", FONT, 0, 18 };
Textes Options::TEXT_CREDITS_STRING_10 = { "", FONT, 0, 19 };
Textes Options::TEXT_CREDITS_STRING_11 = { "", FONT, 0, 20 };
Textes Options::TEXT_CREDITS_STRING_12 = { "", FONT, 0, 21 };
Textes Options::TEXT_CREDITS_STRING_13 = { "", FONT, 0, 22 };
Textes Options::TEXT_BUY_GOLD = { "", FONT, 32, 23 };
Textes Options::TEXT_BUY_SILVER = { "", FONT, 32, 24 };
Textes Options::TEXT_GARAGE_UNLOCK_CHARACTER = { "", FONT, 48, 25 };
Textes Options::TEXT_GARAGE_SELECT_CHARACTER = { "", FONT, 48, 26 };
Textes Options::TEXT_GARAGE_UNLOCK_CHARACTER_BALOON = { "", FONT, 46, 27 };
Textes Options::TEXT_CREDITS_PRIVACY_POLICY = { "", FONT, 46, 28 };

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
        Options::TEXT_LANGUAGE_L_EN.string = "english";
        Options::TEXT_LANGUAGE_L_RU.string = "russian";
        Options::TEXT_LANGUAGE_L_DE.string = "deutsch";
        Options::TEXT_LANGUAGE_L_ES.string = "spanish";
        Options::TEXT_LANGUAGE_L_FR.string = "french";
        Options::TEXT_LANGUAGE_L_NL.string = "dutch";
        Options::TEXT_LANGUAGE_L_IT.string = "italian";
        Options::TEXT_LANGUAGE_L_JP.string = "japanese";
        Options::TEXT_LANGUAGE_L_KR.string = "korean";
        Options::TEXT_LANGUAGE_L_CN.string = "chinese";
            
        TEXT_CREDITS_STRING_1.string = "About";
        TEXT_CREDITS_STRING_1.size = 58;
            
        TEXT_CREDITS_STRING_2.string = "Version: %s";
        TEXT_CREDITS_STRING_2.size = 46;
            
        TEXT_CREDITS_STRING_3.string = "Build: %d";
        TEXT_CREDITS_STRING_3.size = 46;
            
        TEXT_CREDITS_STRING_4.string = "Created by:";
        TEXT_CREDITS_STRING_4.size = 52;
            
        TEXT_CREDITS_STRING_5.string = "Programming";
        TEXT_CREDITS_STRING_5.size = 46;
            
        TEXT_CREDITS_STRING_6.string = "Igor Mats";
        TEXT_CREDITS_STRING_6.size = 42;
            
        TEXT_CREDITS_STRING_7.string = "Designers";
        TEXT_CREDITS_STRING_7.size = 46;
            
        TEXT_CREDITS_STRING_8.string = "Dmitry Shane";
        TEXT_CREDITS_STRING_8.size = 42;
            
        TEXT_CREDITS_STRING_9.string = "Artists";
        TEXT_CREDITS_STRING_9.size = 46;
            
        TEXT_CREDITS_STRING_10.string = "Maksim Petrov";
        TEXT_CREDITS_STRING_10.size = 42;
            
        TEXT_CREDITS_STRING_11.string = "Vyacheslav Shevchenko";
        TEXT_CREDITS_STRING_11.size = 42;
            
        TEXT_CREDITS_STRING_12.string = "PR & Marketing";
        TEXT_CREDITS_STRING_12.size = 46;
            
        TEXT_CREDITS_STRING_13.string = "Aleksandr Lysenko";
        TEXT_CREDITS_STRING_13.size = 42;
            
        TEXT_BUY_GOLD.string = "Any purchase will remove ADS!";
        TEXT_BUY_SILVER.string = "You can convert your gold to iron!";
            
        TEXT_GARAGE_UNLOCK_CHARACTER.string = "unlock";
        TEXT_GARAGE_SELECT_CHARACTER.string = "select";
            
        TEXT_GARAGE_UNLOCK_CHARACTER_BALOON.string = "You can unlock me just for";
        TEXT_CREDITS_PRIVACY_POLICY.string = "Privacy Policy";
        break;
        case 1:
        Options::TEXT_LANGUAGE_L_EN.string = "английский";
        Options::TEXT_LANGUAGE_L_RU.string = "русский";
        Options::TEXT_LANGUAGE_L_DE.string = "немецкий";
        Options::TEXT_LANGUAGE_L_ES.string = "испанский";
        Options::TEXT_LANGUAGE_L_FR.string = "французкий";
        Options::TEXT_LANGUAGE_L_NL.string = "голландский";
        Options::TEXT_LANGUAGE_L_IT.string = "итальянский";
        Options::TEXT_LANGUAGE_L_JP.string = "японский";
        Options::TEXT_LANGUAGE_L_KR.string = "корейский";
        Options::TEXT_LANGUAGE_L_CN.string = "китайский";
            
        TEXT_CREDITS_STRING_1.string = "Об игре";
        TEXT_CREDITS_STRING_1.size = 58;
            
        TEXT_CREDITS_STRING_2.string = "Версия: %s";
        TEXT_CREDITS_STRING_2.size = 46;
            
        TEXT_CREDITS_STRING_3.string = "Сборка: %d";
        TEXT_CREDITS_STRING_3.size = 46;
            
        TEXT_CREDITS_STRING_4.string = "Над игрой работали:";
        TEXT_CREDITS_STRING_4.size = 46;
            
        TEXT_CREDITS_STRING_5.string = "Программисты";
        TEXT_CREDITS_STRING_5.size = 46;
            
        TEXT_CREDITS_STRING_6.string = "Игорь Мац";
        TEXT_CREDITS_STRING_6.size = 42;
            
        TEXT_CREDITS_STRING_7.string = "Дизайнеры";
        TEXT_CREDITS_STRING_7.size = 46;
            
        TEXT_CREDITS_STRING_8.string = "Дмитрий Шейн";
        TEXT_CREDITS_STRING_8.size = 42;
            
        TEXT_CREDITS_STRING_9.string = "Художники";
        TEXT_CREDITS_STRING_9.size = 46;
            
        TEXT_CREDITS_STRING_10.string = "Максим Петров";
        TEXT_CREDITS_STRING_10.size = 42;
            
        TEXT_CREDITS_STRING_11.string = "Вячеслав Шевченко";
        TEXT_CREDITS_STRING_11.size = 42;
            
        TEXT_CREDITS_STRING_12.string = "Маркетологи";
        TEXT_CREDITS_STRING_12.size = 46;
            
        TEXT_CREDITS_STRING_13.string = "Александр Лысенко";
        TEXT_CREDITS_STRING_13.size = 42;
            
        TEXT_BUY_GOLD.string = "Any purchase will remove ADS!";
        TEXT_BUY_SILVER.string = "You can convert your gold to iron!";
            
        TEXT_GARAGE_UNLOCK_CHARACTER.string = "открыть";
        TEXT_GARAGE_SELECT_CHARACTER.string = "выбрать";
            
        TEXT_GARAGE_UNLOCK_CHARACTER_BALOON.string = "";
        TEXT_CREDITS_PRIVACY_POLICY.string = "1";
        break;
    }
    
    TEXTES_HOLDER[0] = TEXT_LANGUAGE_L_EN;
    TEXTES_HOLDER[1] = TEXT_LANGUAGE_L_RU;
    TEXTES_HOLDER[2] = TEXT_LANGUAGE_L_DE;
    TEXTES_HOLDER[3] = TEXT_LANGUAGE_L_ES;
    TEXTES_HOLDER[4] = TEXT_LANGUAGE_L_FR;
    TEXTES_HOLDER[5] = TEXT_LANGUAGE_L_NL;
    TEXTES_HOLDER[6] = TEXT_LANGUAGE_L_IT;
    TEXTES_HOLDER[7] = TEXT_LANGUAGE_L_JP;
    TEXTES_HOLDER[8] = TEXT_LANGUAGE_L_KR;
    TEXTES_HOLDER[9] = TEXT_LANGUAGE_L_CN;
    
    TEXTES_HOLDER[10] = TEXT_CREDITS_STRING_1;
    TEXTES_HOLDER[11] = TEXT_CREDITS_STRING_2;
    TEXTES_HOLDER[12] = TEXT_CREDITS_STRING_3;
    TEXTES_HOLDER[13] = TEXT_CREDITS_STRING_4;
    TEXTES_HOLDER[14] = TEXT_CREDITS_STRING_5;
    TEXTES_HOLDER[15] = TEXT_CREDITS_STRING_6;
    TEXTES_HOLDER[16] = TEXT_CREDITS_STRING_7;
    TEXTES_HOLDER[17] = TEXT_CREDITS_STRING_8;
    TEXTES_HOLDER[18] = TEXT_CREDITS_STRING_9;
    TEXTES_HOLDER[19] = TEXT_CREDITS_STRING_10;
    TEXTES_HOLDER[20] = TEXT_CREDITS_STRING_11;
    TEXTES_HOLDER[21] = TEXT_CREDITS_STRING_12;
    TEXTES_HOLDER[22] = TEXT_CREDITS_STRING_13;
    TEXTES_HOLDER[23] = TEXT_BUY_GOLD;
    TEXTES_HOLDER[24] = TEXT_BUY_SILVER;
    TEXTES_HOLDER[25] = TEXT_GARAGE_UNLOCK_CHARACTER;
    TEXTES_HOLDER[26] = TEXT_GARAGE_SELECT_CHARACTER;
    TEXTES_HOLDER[27] = TEXT_GARAGE_UNLOCK_CHARACTER_BALOON;
    TEXTES_HOLDER[28] = TEXT_CREDITS_PRIVACY_POLICY;
    
    for(int i = 0; i <= 28; i++)
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