#ifndef CONST_POPUP_H
#define CONST_POPUP_H

#include "cocos2d.h"

#include "Screen.h"

#include "Entity.h"
#include "Button.h"

#include "Utils.h"
#include "Options.h"

#include "BatchEntityManager.h"

using namespace cocos2d;

class Popup : public CCLayer, public ButtonReceiver
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
    
        CCSpriteBatchNode* mSpriteBatch;
        CCSpriteBatchNode* mSpriteBatch2;

        CCNode* mParent;
        CCNodeRGBA* mSquare;

        Entity* mBackground;
        Entity* mDarkness;
        Entity* mIllustration;
    
        Button* mCloseButton;
    
        int mShowAnimationCount;
        int mHideAnimationCount;
    
        float mShowAnimationTime;
        float mShowAnimationTimeElapsed;
        
        float mHideAnimationTime;
        float mHideAnimationTimeElapsed;
    
        bool mShowAnimationRunning;
        bool mHideAnimationRunning;
    
        bool mShowed;

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

        // ===========================================================
        // Fields
        // ===========================================================

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Popup(CCNode* pParent, bool pFirst = true);
        ~Popup();

        // ===========================================================
        // Methods
        // ===========================================================
    
        virtual void show();
        virtual void hide();

        bool isShowed();
    
        virtual void onShow();
        virtual void onHide();
    
        void onTouchButtonsCallback(const int pAction, const int pID);
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);

        void draw();
    
        void onEnter();
        void onExit();
    
        bool ccTouchBegan(CCTouch* touch, CCEvent* event);
};

#endif