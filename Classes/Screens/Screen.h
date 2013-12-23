#ifndef CONST_SCREEN_H
#define CONST_SCREEN_H

#include "cocos2d.h"

#include "Touchable.h"

#include "Entity.h"
#include "Button.h"

#include "Spine.h"

#include "EntityManager.h"
#include "BatchEntityManager.h"

#include "Utils.h"
#include "Options.h"

#include "SpriteBatch.h"

#include "AppDelegate.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS || CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "CCStoreInventory.h"
#include "CCStoreController.h"
#include "CCSoomlaError.h"
#include "CCStoreUtils.h"
#endif

using namespace cocos2d;

class Screen : public CCScene, public Touchable, public ButtonReceiver, public CCKeypadDelegate
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

        Screen();

        // ===========================================================
        // Methods
        // ===========================================================

        // ===========================================================
        // Override Methods
        // ===========================================================
        
        bool containsTouchLocation(CCTouch* touch);

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
    
        static const int SCREEN_MENU = 0;
        static const int SCREEN_GARAGE = 1;
        static const int SCREEN_LANGUAGES = 2;
        static const int SCREEN_CREDITS = 3;
        static const int SCREEN_LOADER = 4;
        static const int SCREEN_GAME = 5;

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        ~Screen();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        virtual void onGooglePlusSignInSucceeded();
    
        // ===========================================================
        // Override Methods
        // ===========================================================

        void onEnter();
        void onExit();
    
        void onEnterTransitionDidFinish();
    
        void visit();

        virtual void keyBackClicked();
        virtual void keyBackClicked(bool pSound);
};

#endif