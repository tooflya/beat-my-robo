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

        static const int BUTTONS_ID__BACK = 1001;

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