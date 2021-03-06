#ifndef CONST_IMPULSEENTITY_H
#define CONST_IMPULSEENTITY_H

#include "Entity.h"

class ImpulseEntity : public Entity
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
    // Virtual Methods
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
    // Virtual Methods
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
    
    float mImpulsePower;
    float mSideImpulse;
    float mRotateImpulse;
    float mWeight;

    // ===========================================================
    // Constructors
    // ===========================================================
    
    ImpulseEntity(const char* pTextureFileName);
    ImpulseEntity(const char* pTextureFileName, CCNode* pParent);
    ImpulseEntity(const char* pTextureFileName, int pHorizontalFramesCount, int pVerticalFramesCount);
    
    static ImpulseEntity* create(const char* pTextureFileName);

    // ===========================================================
    // Methods
    // ===========================================================
        
    // ===========================================================
    // Override Methods
    // ===========================================================
    
    void update(float pDelta);
    
    ImpulseEntity* deepCopy();
};

#endif