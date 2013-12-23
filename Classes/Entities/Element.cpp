#ifndef CONST_ELEMENT
#define CONST_ELEMENT

#include "Element.h"

#include "GameBackgroundField.h"

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

Element::Element(GameBackgroundField* pField) :
    Button("game_action_sprite@2x.png", 5, 2, NULL, 0, NULL)
    {
        this->mField = pField;
        this->mPic = NULL;

        this->mFixedCenterX = 0;
        this->mFixedCenterY = 0;
        
        this->mPicAnimationTime = 0.1;
        this->mPicAnimationTimeElapsed = 0;
    }

Element* Element::create(GameBackgroundField* pField)
{
    Element* element = new Element(pField);
    element->autorelease();
    
    return element;
}

// ===========================================================
// Methods
// ===========================================================

void Element::move(int pDirection)
{
    Entity::ccTouchEnded(NULL, NULL);
    
    if(this->x >= this->mField->Matrix->countX || this->y >= this->mField->Matrix->countY) return;

    int a = 0;
    int b = 0;
    
    switch(pDirection)
    {
        case MOVE_DIRECTION_LEFT:
        {
            if(x <= 0)
            {
                return;
            }

            a = -1;
        }
        break;
        case MOVE_DIRECTION_RIGHT:
        {
            if(x >= this->mField->Matrix->countX)
            {
                return;
            }

            a = +1;
        }
        break;
        case MOVE_DIRECTION_UP:
        {
            if(y >= this->mField->Matrix->countY - 1)
            {
                return;
            }

            b = +1;
        }
        break;
        case MOVE_DIRECTION_DOWN:
        {
            if(y <= 0)
            {
                return;
            }

            b = -1;
        }
        break;
    }

    this->mField->Matrix->swap(this->x, this->y, a, b);
}

void Element::createParticles()
{
    for(int i = 0; i < 10; i++)
    {
        float x = this->getCenterX() + Utils::coord(Utils::randomf(-20, 20));
        float y = this->getCenterY() + Utils::coord(Utils::randomf(-20, 20));
    
        Entity* particle = this->mField->mElementParticles->create();
        
        particle->setCurrentFrameIndex(this->getCurrentFrameIndex() + (Utils::random(0, 1) * 5));
        particle->setCenterPosition(x, y);
    }
}

void Element::remove()
{
    this->mPic = this->mField->mElementPics->create();
    this->mPic->setCurrentFrameIndex(this->getCurrentFrameIndex() * 2);
    this->mPic->setCenterPosition(this->getCenterX(), this->getCenterY());

    this->runAction(CCSequence::create(
                                       CCFadeTo::create(0.00, 0),
                                       CCFadeTo::create(0.8, 0),
                                       CCCallFunc::create(this, callfunc_selector(Element::destroy)),
                                       NULL
                                       ));
    
    this->createParticles();

    this->mPicAnimationReverse = false;
    this->mPicAnimationTimeElapsed = 0;
}

void Element::destroy()
{
    Entity::destroy();
    
    this->setOpacity(255);

    if(this->mPic)
    {
        this->mPic->destroy();
        this->mPic = NULL;
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Element::update(float pDeltaTime)
{
    if(this->y > 0 && this->numberOfRunningActions() == 0)
    {
        if(this->mField->Matrix->get(this->x, this->y - 1) == NULL)
        {
            this->mField->Matrix->set(this->x, this->y, NULL);
            this->mField->Matrix->set(this->x, this->y - 1, this);
            
            int count = 1;
            
            while(this->mField->Matrix->get(this->x, this->y - 1) == NULL && this->y > 0)
            {
                this->mField->Matrix->set(this->x, this->y, NULL);
                this->mField->Matrix->set(this->x, this->y - 1, this);

                count++;
            }
            
            this->mField->Matrix->mAnimationTime = MAX(0.3 * count + 1, this->mField->Matrix->mAnimationTime);

            this->runAction(CCSequence::create(
                                               CCFadeTo::create(0.8, 255),
                                               CCCallFunc::create(this, callfunc_selector(Element::onMatrixPosition)),
                                               CCMoveTo::create(0.1 * count, ccp(this->getCenterX(), this->getCenterY() - (this->getWidth() + Utils::coord(6)) * count)),
                                               CCMoveTo::create(0.05, ccp(this->getCenterX(), this->getCenterY() - (this->getWidth() + Utils::coord(6)) * count + Utils::coord(10))),
                                               CCMoveTo::create(0.05, ccp(this->getCenterX(), this->getCenterY() - (this->getWidth() + Utils::coord(6)) * count)),
                                               NULL
                                               ));
        }
    }
    
    if(this->mPic)
    {
        this->mPicAnimationTimeElapsed += pDeltaTime;
        
        if(this->mPicAnimationTimeElapsed >= this->mPicAnimationTime)
        {
            this->mPicAnimationTimeElapsed = 0;

            this->mPicAnimationReverse ? this->mPic->previousFrameIndex() : this->mPic->nextFrameIndex();
            
            this->mPic->runAction(CCScaleTo::create(this->mPicAnimationTime, this->mPicAnimationReverse ? 1.1 : 1.0));
        
            this->mPicAnimationReverse = !this->mPicAnimationReverse;
        }
    }
}

void Element::setCenterPosition(float pCenterX, float pCenterY)
{
    if(this->mFixedCenterX == 0 && this->mFixedCenterY == 0)
    {
        this->mFixedCenterX = pCenterX;
        this->mFixedCenterY = pCenterY;
    }
    
    Entity::setCenterPosition(pCenterX, pCenterY);
}

void Element::nextFrameIndex()
{
    if(this->getCurrentFrameIndex() > 4) return;

    this->setCurrentFrameIndex(this->getCurrentFrameIndex() + 5);
}

void Element::previousFrameIndex()
{
    if(this->getCurrentFrameIndex() < 5) return;
    
    this->setCurrentFrameIndex(this->getCurrentFrameIndex() - 5);
}

void Element::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
    if(this->numberOfRunningActions() > 0 || !this->mWasTouched) return;

    if(!containsTouchLocation(touch) && abs(ccpDistance(touch->getLocation(), this->mStartTouchPoint)) >= Utils::coord(15))
    {
        if(touch->getLocation().x < this->mStartTouchPoint.x)
        {
            if(abs(touch->getLocation().x - this->mStartTouchPoint.x) > abs(touch->getLocation().y - this->mStartTouchPoint.y))
            {
                this->move(MOVE_DIRECTION_LEFT);
            }
            else
            {
                if(touch->getLocation().y < this->mStartTouchPoint.y)
                {
                    this->move(MOVE_DIRECTION_DOWN);
                    
                }
                else
                {
                    this->move(MOVE_DIRECTION_UP);
                }
            }
        }
        else
        {
            if(abs(touch->getLocation().x - this->mStartTouchPoint.x) > abs(touch->getLocation().y - this->mStartTouchPoint.y))
            {
                this->move(MOVE_DIRECTION_RIGHT);
            }
            else
            {
                if(touch->getLocation().y < this->mStartTouchPoint.y)
                {
                    this->move(MOVE_DIRECTION_DOWN);
                }
                else
                {
                    this->move(MOVE_DIRECTION_UP);
                }
            }
        }
    }
}

void Element::onTouch(CCTouch* touch, CCEvent* event)
{
    int x = this->mField->Matrix->get(this->x, this->y)->x;
    int y = this->mField->Matrix->get(this->x, this->y)->y;

    CCLog("%d, %d", x, y);
}

void Element::setMatrixPosition(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Element::onMatrixPosition()
{
    this->setVisible(this->y < this->mField->Matrix->countY);
}

void Element::onCreate()
{
    Button::onCreate();
}

void Element::onDestroy()
{
    Button::onDestroy();
}

Element* Element::deepCopy()
{
    return Element::create(this->mField);
}

#endif