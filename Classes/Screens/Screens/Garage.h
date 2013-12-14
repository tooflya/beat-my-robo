#ifndef CONST_GARAGESCREEN_H
#define CONST_GARAGESCREEN_H

#include "Screen.h"

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
    
        Entity* mBackground;
        Entity* mResourcesIcons[2];
        Entity* mResourcesBackgrounds[2];
    
        Button* mBackButton;
        Button* mPlayButton;
        Button* mResourcesPluses[2];
    
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