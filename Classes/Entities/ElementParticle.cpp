#ifndef CONST_ELEMENTPARTICLE
#define CONST_ELEMENTPARTICLE

#include "ElementPArticle.h"

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

ElementParticle::ElementParticle() :
ImpulseEntity("game_action_fall_parts_sprite@2x.png", 5, 2)
{
}

ElementParticle* ElementParticle::create()
{
    ElementParticle* element = new ElementParticle();
    element->autorelease();
    
    return element;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void ElementParticle::onCreate()
{
    ImpulseEntity::onCreate();
    
    this->setScale(0);
    
    this->runAction(CCScaleTo::create(Utils::randomf(0.1, 0.3), Utils::randomf(0.1, 1.0)));

    this->mRotateImpulse = Utils::randomf(-100.0, 100.0);
    this->mImpulsePower = Utils::coord(Utils::randomf(200.0, 300.0));
    this->mSideImpulse = Utils::coord(Utils::randomf(-150.0, 150.0));
    this->mWeight = Utils::coord(Utils::randomf(2000.0, 2500.0));
    
    this->mBottomAnimation[0] = false;
    this->mBottomAnimation[1] = false;
}

void ElementParticle::onDestroy()
{
    ImpulseEntity::onDestroy();
}

void ElementParticle::destroy()
{
    ImpulseEntity::destroy();
}

void ElementParticle::update(float pDeltaTime)
{
    ImpulseEntity::update(pDeltaTime);
    
    if(this->mBottomAnimation[1])
    {
        if(this->getCenterY() <= Utils::coord(0) && this->numberOfRunningActions() == 0)
        {
            this->mSideImpulse = 0;
            this->mImpulsePower = 0;
            this->mWeight = 0;
            
            this->runAction(CCSequence::create(CCScaleTo::create(Utils::randomf(0.1, 1.0), 0), CCCallFunc::create(this, callfunc_selector(ElementParticle::destroy)), NULL));
        }
    }
    else
    {
        if(this->mBottomAnimation[0])
        {
            this->mRotateImpulse = Utils::randomf(-100.0, 100.0);
            this->mImpulsePower = Utils::coord(Utils::randomf(100.0, 500.0));
            this->mSideImpulse = Utils::coord(Utils::randomf(-100.0, 100.0));

            this->mBottomAnimation[1] = true;
        }
        else
        {
            if(this->getCenterY() <= Utils::coord(30))
            {
                this->mBottomAnimation[0] = true;
            }
        }
    }
}

ElementParticle* ElementParticle::deepCopy()
{
    return ElementParticle::create();
}

#endif