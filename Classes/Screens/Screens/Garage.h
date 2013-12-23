#ifndef CONST_GARAGESCREEN_H
#define CONST_GARAGESCREEN_H

#include "Screen.h"

#include "GetGold.h"
#include "GetSilver.h"
#include "Properties.h"

class Garage : public Screen
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
    
        SpriteBatch* mSpriteBatch1;
        SpriteBatch* mSpriteBatch2;
        SpriteBatch* mSpriteBatch3;
        SpriteBatch* mSpriteBatch4;
        SpriteBatch* mSpriteBatch5;
    
        Entity* mBackground;
        Entity* mBackgroundDecoration;
        Entity* mResourcesIcons[2];
        Entity* mResourcesBackgrounds[2];
        Entity* mBaloon;
        Entity* mBaloonResourcesIcons[2];
    
        Button* mBackButton;
        Button* mPlayButton;
        Button* mResourcesPluses[2];
        Button* mMoveButtons[2];
        Button* mSelectCharacter;
    
        Popup* mGetGoldPopup;
        Popup* mGetSilverPopup;
    
        int mCurrentFrame;
    
        Text* mBaloonText;
        Text* mBaloonTextGold;
        Text* mBaloonTextSilver;
    
        Properties* mProperties;
    
        // ===========================================================
        // Constructors
        // ===========================================================
    
        Garage();

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
    
        void updateMoveButtons();
    
        void onCharacterListStartView();
        void onCharacterListEndView();
    
        void showBaloon();
        void hideBaloon();
    
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

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static Garage* create();
    
        ~Garage();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void onEnter();
        void onExit();
    
        void onEnterTransitionDidFinish();
        void onExitTransitionDidStart();
    
        void update(float pDeltaTime);
    
        void keyBackClicked(bool pSound);
};

#endif