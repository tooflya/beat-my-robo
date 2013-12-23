#ifndef CONST_OPTIONS_H
#define CONST_OPTIONS_H

#include "cocos2d.h"

USING_NS_CC;

using namespace cocos2d;

#define ccsf(...) CCString::createWithFormat(__VA_ARGS__)->getCString()

typedef struct tagTextes {
    const char* string;
    const char* font;
    int size;
    int identifier;
} Textes;

typedef struct tagTextureStructure {
    const char* texture;
    const char* frames;
} TextureStructure;

class Options
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

		static CCSize designResolutionSize;
    
        static const char* GOOGLE_PLAY_BASE_64_KEY;
        static const char* SOOMLA_BASE_64_KEY;
        static const char* SOOMLA_CUSTOM_BASE_64_KEY;
    
        static CCObject* PAYMENT_PROCEED_HANDLER;

        static int CENTER_X;
        static int CENTER_Y;

        static int SCREEN_WIDTH;
        static int SCREEN_HEIGHT;

        static int SCREEN_CENTER_X;
        static int SCREEN_CENTER_Y;

        static int CAMERA_WIDTH;
        static int CAMERA_HEIGHT;

        static int CAMERA_CENTER_X;
        static int CAMERA_CENTER_Y;

        static bool MUSIC_ENABLE;
        static bool SOUND_ENABLE;
    
        static const char* TEXTURES_EXTENSION;

        static const char* VERSION;
        static std::string STRING_VERSION;
        static int BUILD;
    
        static const char* SAVE_DATA_LANGUAGE_ID;
    
        static int DEVICE_TYPE;
    
        static const int DEVICE_TYPE_IOS = 0;
        static const int DEVICE_TYPE_ANDROID = 1;
        static const int DEVICE_TYPE_WP = 2;
        static const int DEVICE_TYPE_MAC = 3;
        static const int DEVICE_TYPE_LINUX = 4;
        static const int DEVICE_TYPE_WINDOWS = 5;
    
        static const int DEVICE_TYPE_IPHONE5 = 10;
        static const int DEVICE_TYPE_IPHONE4 = 11;
        static const int DEVICE_TYPE_IPOD4 = 12;
        static const int DEVICE_TYPE_IPAD_RETINA = 13;
    
        static const int DEVICE_TYPE_NEXUS3 = 20;

        static const char* FONT;
    
        static int CURRENT_LANGUAGE;
    
        static Textes TEXTES_HOLDER[600];

        static const int BUTTONS_ACTION_ONTOUCH = 0;
        static const int BUTTONS_ACTION_ONBEGIN = 1;
        static const int BUTTONS_ACTION_ONEND = 2;

        static const int BUTTONS_ID_BACK = 1001;
        static const int BUTTONS_ID_MENU_PLAY = 2001;
        static const int BUTTONS_ID_MENU_SETTINGS = 2002;
        static const int BUTTONS_ID_MENU_CREDITS = 2003;
        static const int BUTTONS_ID_MENU_SOUND = 2004;
        static const int BUTTONS_ID_MENU_MUSIC = 2005;
        static const int BUTTONS_ID_MENU_TWITTER = 2006;
        static const int BUTTONS_ID_MENU_FACEBOOK = 2007;
        static const int BUTTONS_ID_MENU_LANGUAGE = 2008;
        static const int BUTTONS_ID_LANGUAGE_L_EN = 2101;
        static const int BUTTONS_ID_LANGUAGE_L_RU = 2102;
        static const int BUTTONS_ID_LANGUAGE_L_DE = 2103;
        static const int BUTTONS_ID_LANGUAGE_L_ES = 2104;
        static const int BUTTONS_ID_LANGUAGE_L_FR = 2105;
        static const int BUTTONS_ID_LANGUAGE_L_NL = 2106;
        static const int BUTTONS_ID_LANGUAGE_L_IT = 2107;
        static const int BUTTONS_ID_LANGUAGE_L_JP = 2108;
        static const int BUTTONS_ID_LANGUAGE_L_KR = 2109;
        static const int BUTTONS_ID_LANGUAGE_L_CN = 2110;
        static const int BUTTONS_ID_GARAGE_PLAY = 2201;
        static const int BUTTONS_ID_GARAGE_MOVE_LEFT = 2202;
        static const int BUTTONS_ID_GARAGE_MOVE_RIGHT = 2203;
        static const int BUTTONS_ID_GARAGE_GET_GOLD = 2204;
        static const int BUTTONS_ID_GARAGE_GET_SILVER = 2205;
        static const int BUTTONS_ID_GARAGE_SELECT = 2206;
        static const int BUTTONS_ID_GET_GOLD_1 = 2301;
        static const int BUTTONS_ID_GET_GOLD_2 = 2302;
        static const int BUTTONS_ID_GET_GOLD_3 = 2303;
        static const int BUTTONS_ID_GET_GOLD_4 = 2304;
        static const int BUTTONS_ID_GET_SILVER_1 = 2401;
        static const int BUTTONS_ID_GET_SILVER_2 = 2402;
        static const int BUTTONS_ID_GET_SILVER_3 = 2403;
        static const int BUTTONS_ID_GET_SILVER_4 = 2404;
        static const int BUTTONS_ID_CREDITS_PRIVACY_POLICY = 2501;
    
        static Textes TEXT_LANGUAGE_L_EN;
        static Textes TEXT_LANGUAGE_L_RU;
        static Textes TEXT_LANGUAGE_L_DE;
        static Textes TEXT_LANGUAGE_L_ES;
        static Textes TEXT_LANGUAGE_L_FR;
        static Textes TEXT_LANGUAGE_L_NL;
        static Textes TEXT_LANGUAGE_L_IT;
        static Textes TEXT_LANGUAGE_L_JP;
        static Textes TEXT_LANGUAGE_L_KR;
        static Textes TEXT_LANGUAGE_L_CN;
        static Textes TEXT_CREDITS_STRING_1;
        static Textes TEXT_CREDITS_STRING_2;
        static Textes TEXT_CREDITS_STRING_3;
        static Textes TEXT_CREDITS_STRING_4;
        static Textes TEXT_CREDITS_STRING_5;
        static Textes TEXT_CREDITS_STRING_6;
        static Textes TEXT_CREDITS_STRING_7;
        static Textes TEXT_CREDITS_STRING_8;
        static Textes TEXT_CREDITS_STRING_9;
        static Textes TEXT_CREDITS_STRING_10;
        static Textes TEXT_CREDITS_STRING_11;
        static Textes TEXT_CREDITS_STRING_12;
        static Textes TEXT_CREDITS_STRING_13;
        static Textes TEXT_BUY_GOLD;
        static Textes TEXT_BUY_SILVER;
        static Textes TEXT_GARAGE_UNLOCK_CHARACTER;
        static Textes TEXT_GARAGE_SELECT_CHARACTER;
        static Textes TEXT_GARAGE_UNLOCK_CHARACTER_BALOON;
        static Textes TEXT_CREDITS_PRIVACY_POLICY;

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Options();

        // ===========================================================
        // Methods
        // ===========================================================

        static void init();
    
        static void changeLanguage();
        
        // ===========================================================
        // Override Methods
        // ===========================================================
};

#endif