#ifndef CONST_GAMEBACKGROUNDMATRIX_H
#define CONST_GAMEBACKGROUNDMATRIX_H

#include "Screen.h"

#include "Element.h"
#include "EntityManager.h"

class GameBackgroundMatrix : public CCNode
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
    
    GameBackgroundMatrix(CCNode* pParent, EntityManager* mManager);

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
    
    CCArray* mElementsList;

    EntityManager* mManager;
    
    Element* mElements0[12];
    Element* mElements1[12];
    Element* mElements2[12];
    Element* mElements3[12];
    Element* mElements4[12];
    Element* mElements5[12];
    
    Element* swap1;
    Element* swap2;

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
    
    int countX;
    int countY;
    
    int countInnderY;
    
    bool mAnimation;
    
    float mAnimationTime;
    float mAnimationTimeElapsed;

    // ===========================================================
    // Constructors
    // ===========================================================
    
    static GameBackgroundMatrix* create(CCNode* pParent, EntityManager* mManager);
    
    ~GameBackgroundMatrix();

    // ===========================================================
    // Methods
    // ===========================================================
    
    Element* get(int x, int y);
    void set(int x, int y, Element* element);
    void destroy(int x, int y);

    void swap(int x, int y, int a, int b);
    void swapBack();
    
    void setRegisterAsTouchable(bool pTouchable);
    void stopActions();
    
    void onSwapEnd();
    void onSwapAnimationEnd();
    
    void swapElements(Element* element1, Element* element2);
    
    bool findMatches(Element* element, bool pIsRecursive, int pPastPosX, int pPastPosY, int pLook);
    
    void burnElements();
    
    void create(int x);
    
    // ===========================================================
    // Override Methods
    // ===========================================================
    
    void update(float pDeltaTime);
};

#endif