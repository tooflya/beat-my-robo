#ifndef CONST_LOADERSCREEN_H
#define CONST_LOADERSCREEN_H

#include "Screen.h"

class Loader : public Screen
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
        Entity* mBackgroundName;
        Entity* mPreloader;
    
        bool mLoading;
    
        float mLoadingTime;
        float mLoadingTimeElapsed;
    
        // ===========================================================
        // Constructors
        // ===========================================================
    
        Loader();

        // ===========================================================
        // Methods
        // ===========================================================
    
        void onLoadingComplete();

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
    
        static Loader* create();
    
        ~Loader();

        // ===========================================================
        // Methods
        // ===========================================================
        
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void onEnter();
        void onExit();
    
        void onEnterTransitionDidFinish();
        void onExitTransitionDidStart();
    
        void update(float pDeltaTime);
};

#endif