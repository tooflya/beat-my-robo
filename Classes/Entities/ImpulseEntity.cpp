#ifndef CONST_IMPULSEENTITY
#define CONST_IMPULSEENTITY

#include "ImpulseEntity.h"

#include "Game.h"

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

ImpulseEntity::ImpulseEntity(const char* pTextureFileName) :
    Entity(pTextureFileName),
	mImpulsePower(0),
	mSideImpulse(0),
	mRotateImpulse(0),
	mWeight(0)
    {
        this->mWeight = 0;
        this->mSideImpulse = 0;
        this->mImpulsePower = 0;
        this->mRotateImpulse = 0;
    }

ImpulseEntity::ImpulseEntity(const char* pTextureFileName, CCNode* pParent) :
    Entity(pTextureFileName, pParent),
	mImpulsePower(0),
	mSideImpulse(0),
	mRotateImpulse(0),
	mWeight(0)
    {
        this->mWeight = 0;
        this->mSideImpulse = 0;
        this->mImpulsePower = 0;
        this->mRotateImpulse = 0;
    }

ImpulseEntity::ImpulseEntity(const char* pTextureFileName, int pHorizontalFramesCount, int pVerticalFramesCount) :
    Entity(pTextureFileName, pHorizontalFramesCount, pVerticalFramesCount),
	mImpulsePower(0),
	mSideImpulse(0),
	mRotateImpulse(0),
	mWeight(0)
    {
        this->mWeight = 0;
        this->mSideImpulse = 0;
        this->mImpulsePower = 0;
        this->mRotateImpulse = 0;
    }

ImpulseEntity* ImpulseEntity::create(const char *pTextureFileName)
{
    ImpulseEntity* entity = new ImpulseEntity(pTextureFileName);
    entity->autorelease();

    return entity;
}

// ===========================================================
// Methods
// ===========================================================

void ImpulseEntity::update(float pDeltaTime)
{
    Entity::update(pDeltaTime);
    
    if(this->mImpulsePower >= 0.0f)
    {
        this->setCenterPosition(this->getCenterX(), this->getCenterY() + this->mImpulsePower * pDeltaTime);
        
        this->mImpulsePower -= this->mWeight * pDeltaTime;
    }
    else
    {
        this->setCenterPosition(this->getCenterX(), this->getCenterY() - abs(this->mImpulsePower) * pDeltaTime);
        
        this->mImpulsePower -= this->mWeight * pDeltaTime;
    }
    
    this->setCenterPosition(this->getCenterX() - this->mSideImpulse * pDeltaTime, this->getCenterY());
    this->setRotation(this->getRotation() - this->mRotateImpulse * pDeltaTime);

    if(this->getCenterY() < -this->getHeight() / 2 || this->getCenterX() < -Options::CAMERA_WIDTH || this->getCenterX() > Options::CAMERA_WIDTH * 2)
    {
        this->destroy();
    }
}

// ===========================================================
// Override Methods
// ===========================================================

ImpulseEntity* ImpulseEntity::deepCopy()
{
    return ImpulseEntity::create(this->mTextureFileName);
}

#endif