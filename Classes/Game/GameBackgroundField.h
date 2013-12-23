#ifndef CONST_GAMEBACKGROUNDFIELD_H
#define CONST_GAMEBACKGROUNDFIELD_H

#include "GameBackgroundDelegate.h"

#include "GameBackground.h"
#include "GameBackgroundMatrix.h"

#include "Element.h"
#include "ElementParticle.h"

class GameBackgroundField : public GameBackgroundColorDelegate
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

        // ===========================================================
        // Constructors
        // ===========================================================
    
        GameBackgroundField(CCNode* pParent);

        // ===========================================================
        // Methods
        // ===========================================================
    
        void generateMatrix();
        void generateField();
    
        bool approvePosition(int pFrameIndex, int pPositionX, int pPositionY, bool pIsRecursive, int pPastPosX, int pPastPosY);

        // ===========================================================
        // Override Methods
        // ===========================================================
    
        virtual void initialization();

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
    
        GameBackgroundMatrix* Matrix;
    
        EntityManager* mElements;
        EntityManager* mElementParticles;
        EntityManager* mElementPics;

        // ===========================================================
        // Constructors
        // ===========================================================
    
        static GameBackgroundField* create(CCNode* pParent);
    
        ~GameBackgroundField();

        // ===========================================================
        // Methods
        // ===========================================================
    
        // ===========================================================
        // Override Methods
        // ===========================================================
    
        void update(float pDeltaTime);
    
        void visit();
};

#endif