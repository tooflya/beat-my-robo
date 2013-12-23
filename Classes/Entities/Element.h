#ifndef CONST_ELEMENT_H
#define CONST_ELEMENT_H

#include "Button.h"

class GameBackgroundField;

class Element : public Button
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
    
        GameBackgroundField* mField;
    
        Entity* mPic;
    
        bool mPicAnimationReverse;
    
        float mPicAnimationTime;
        float mPicAnimationTimeElapsed;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        Element(GameBackgroundField* pField);

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

        static const int MOVE_DIRECTION_LEFT = 1;
        static const int MOVE_DIRECTION_RIGHT = 2;
        static const int MOVE_DIRECTION_UP = 3;
        static const int MOVE_DIRECTION_DOWN = 4;

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
    
        static Element* create(GameBackgroundField* pField);

        // ===========================================================
        // Fields
        // ===========================================================
    
        int mId;
    
        int x;
        int y;
    
        float mFixedCenterX;
        float mFixedCenterY;
    
        // ===========================================================
        // Constructors
        // ===========================================================

        // ===========================================================
        // Methods
        // ===========================================================
    
        void createParticles();
    
        void move(int pDirection);
    
        void remove();
    
        void setMatrixPosition(int x, int y);
    
        void onMatrixPosition();
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void onCreate();
        void onDestroy();

        void update(float pDeltaTime);
    
        void destroy();
    
        void nextFrameIndex();
        void previousFrameIndex();
    
        void setCenterPosition(float pCenterX, float pCenterY);
    
        void onTouch(CCTouch* touch, CCEvent* event);
        void ccTouchMoved(CCTouch* touch, CCEvent* event);
    
        Element* deepCopy();
};

#endif