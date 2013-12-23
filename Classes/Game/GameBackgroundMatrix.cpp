#ifndef CONST_GAMEBACKGROUNDMATRIX
#define CONST_GAMEBACKGROUNDMATRIX

#include "GameBackgroundMatrix.h"

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

GameBackgroundMatrix::~GameBackgroundMatrix()
{
    
}

GameBackgroundMatrix::GameBackgroundMatrix(CCNode* pParent, EntityManager* pManager)
{
    this->countX = 6;
    this->countY = 6;
    
    this->countInnderY = 12;
    
    this->mManager = pManager;
    
    for(int i = 0; i < this->countX; i++)
    {
        for(int j = 0; j < this->countInnderY; j++)
        {
            if(i == 0) this->mElements0[j] = NULL;
            if(i == 1) this->mElements1[j] = NULL;
            if(i == 2) this->mElements2[j] = NULL;
            if(i == 3) this->mElements3[j] = NULL;
            if(i == 4) this->mElements4[j] = NULL;
            if(i == 5) this->mElements5[j] = NULL;
        }
    }
    
    this->mAnimation = false;
    
    this->mAnimationTime = 0.3;
    this->mAnimationTimeElapsed = 0;
    
    this->mElementsList = CCArray::create();
    this->mElementsList->retain();
    
    this->scheduleUpdate();

    if(pParent)
    {
        pParent->addChild(this);
    }
}

GameBackgroundMatrix* GameBackgroundMatrix::create(CCNode* pParent, EntityManager* pManager)
{
    GameBackgroundMatrix* matrix = new GameBackgroundMatrix(pParent, pManager);
    matrix->autorelease();
    matrix->retain();
        
    return matrix;
}
    
Element* GameBackgroundMatrix::get(int x, int y)
{
    if(x == 0) return this->mElements0[y];
    if(x == 1) return this->mElements1[y];
    if(x == 2) return this->mElements2[y];
    if(x == 3) return this->mElements3[y];
    if(x == 4) return this->mElements4[y];
    if(x == 5) return this->mElements5[y];
        
    return NULL;
}

void GameBackgroundMatrix::set(int x, int y, Element* element)
{
    if(element != NULL)
    {
        element->setMatrixPosition(x, y);
    }
    
    if(x == 0) this->mElements0[y] = element;
    if(x == 1) this->mElements1[y] = element;
    if(x == 2) this->mElements2[y] = element;
    if(x == 3) this->mElements3[y] = element;
    if(x == 4) this->mElements4[y] = element;
    if(x == 5) this->mElements5[y] = element;
}

void GameBackgroundMatrix::swapElements(Element* element1, Element* element2)
{
    int x1 = element1->x;
    int y1 = element1->y;
    
    int x2 = element2->x;
    int y2 = element2->y;
    
    this->set(x1, y1, element2);
    this->set(x2, y2, element1);
}

void GameBackgroundMatrix::destroy(int x, int y)
{
    Element* element = this->get(x, y);
    
    element->x = -1;
    element->y = -1;

    element->remove();

    if(x == 0) this->mElements0[y] = NULL;
    if(x == 1) this->mElements1[y] = NULL;
    if(x == 2) this->mElements2[y] = NULL;
    if(x == 3) this->mElements3[y] = NULL;
    if(x == 4) this->mElements4[y] = NULL;
    if(x == 5) this->mElements5[y] = NULL;
}

void GameBackgroundMatrix::burnElements()
{
    for(int i = 0; i < this->mElementsList->count(); i++)
    {
        Element* element = static_cast<Element*>(this->mElementsList->objectAtIndex(i));
        
        this->destroy(element->x, element->y);
    }
    
    for(int i = 0; i < this->countX; i++)
    {
        this->create(i);
    }
    
    this->mElementsList->removeAllObjects();
}

bool GameBackgroundMatrix::findMatches(Element* element, bool pIsRecursive, int pPastPosX, int pPastPosY, int pLook)
{
    this->setRegisterAsTouchable(false);
    
    this->mAnimationTime = 1.0;

    if(element == NULL) return false;

    if(!this->mElementsList->containsObject(element))
    {
       this->mElementsList->addObject(element);
    }

    if(true)
    {
        if(pLook == -1 || pLook == 1)
        if(element->x > 0 && (pPastPosX != element->x - 1)) // влево
        {
            Element* neighbor = this->get(element->x - 1, element->y);
            
            if(neighbor != NULL)
            {
                if(neighbor->getCurrentFrameIndex() == element->getCurrentFrameIndex())
                {
                    this->findMatches(neighbor, false, element->x, element->y, 1);
                }
            }
        }
        
        if(pLook == -1 || pLook == 2)
        if(element->x < this->countX && (pPastPosX != element->x + 1)) // вправо
        {
            Element* neighbor = this->get(element->x + 1, element->y);
            
            if(neighbor != NULL)
            {
                if(neighbor->getCurrentFrameIndex() == element->getCurrentFrameIndex())
                {
                    this->findMatches(neighbor, false, element->x, element->y, 2);
                }
            }
        }
        
        if(pLook == -1 || pLook == 3)
        if(element->y > 0 && (pPastPosY != element->y - 1)) // вниз
        {
            Element* neighbor = this->get(element->x, element->y - 1);
            
            if(neighbor != NULL)
            {
                if(neighbor->getCurrentFrameIndex() == element->getCurrentFrameIndex())
                {
                    this->findMatches(neighbor, false, element->x, element->y, 3);
                }
            }
        }
        
        if(pLook == -1 || pLook == 4)
        if(element->y < this->countY-1 && (pPastPosY != element->y + 1)) // вверх
        {
            Element* neighbor = this->get(element->x, element->y + 1);
            
            if(neighbor != NULL)
            {
                if(neighbor->getCurrentFrameIndex() == element->getCurrentFrameIndex())
                {
                    this->findMatches(neighbor, false, element->x, element->y, 4);
                }
            }
        }

        if(pIsRecursive)
        {
            int x = 0;
            int y = 0;

            for(int i = 0; i < this->mElementsList->count(); i++)
            {
                Element* el = static_cast<Element*>(this->mElementsList->objectAtIndex(i));
                
                if(element->x == el->x) x++;
                if(element->y == el->y) y++;
                
                if(element->x != el->x && element->y != el->y)
                {
                    this->mElementsList->removeObject(el);
                }
            }
            
            if(x < 3)
            {
                for(int i = 0; i < this->mElementsList->count(); i++)
                {
                    Element* el = static_cast<Element*>(this->mElementsList->objectAtIndex(i));
                    
                    if(el->y != element->y) this->mElementsList->removeObject(el);
                }
            }
            
            if(y < 3)
            {
                for(int i = 0; i < this->mElementsList->count(); i++)
                {
                    Element* el = static_cast<Element*>(this->mElementsList->objectAtIndex(i));
                    
                    if(el->x != element->x) this->mElementsList->removeObject(el);
                }
            }
            
            int count = this->mElementsList->count();
            
            if(count >= 3 && (x >= 3 || y >= 3))
            {
               this->burnElements();
            }
            else
            {
                this->mElementsList->removeAllObjects();
            }
            
            this->mAnimation = true;
            
            return count >= 3 && (x >= 3 || y >= 3);
        }
        
        int count = this->mElementsList->count();

        return count >= 3;
    }
    
    return false;
}

void GameBackgroundMatrix::stopActions()
{
    for(int i = 0; i < this->mManager->getCapacity(); i++)
    {
        static_cast<Element*>(this->mManager->objectAtIndex(i))->stopAllActions();
    }
}

void GameBackgroundMatrix::setRegisterAsTouchable(bool pTouchable)
{
    for(int i = 0; i < this->mManager->getCapacity(); i++)
    {
        static_cast<Element*>(this->mManager->objectAtIndex(i))->setRegisterAsTouchable(pTouchable);
    }
}

void GameBackgroundMatrix::onSwapEnd()
{
    this->stopActions();

    this->swapElements(this->swap1, this->swap2);

    if((this->swap1->getCurrentFrameIndex() != this->swap2->getCurrentFrameIndex()))
    {
        this->mAnimation = true;

        if((this->findMatches(this->swap1, true, -1, -1, -1) || this->findMatches(this->swap2, true, -1, -1, -1)))
        {
            this->onSwapAnimationEnd();
        }
        else
        {
            this->swapBack();
        }
    }
    else
    {
        this->swapBack();
    }
}

void GameBackgroundMatrix::onSwapAnimationEnd()
{
}

void GameBackgroundMatrix::create(int x)
{
    int y = this->countY;

    while(y < this->countInnderY)
    {
        if(this->get(x, y) == NULL)
        {
            float size = Utils::coord(110);
            float padding = Utils::coord(6);
            
            float px = size / 2 + (size * x + padding * (x + 1));
            float py = size / 2 + (size * y + padding * (y + 1));
            
            Element* element = static_cast<Element*>(this->mManager->create());
            
            element->setCenterPosition(px, py);
            element->setCurrentFrameIndex(Utils::random(0, 4));
            
            this->set(x, y, element);
        }
        
        y++;
    }
}

void GameBackgroundMatrix::swap(int x, int y, int a, int b)
{
        this->setRegisterAsTouchable(false);

        this->swap1 = this->get(x, y);
        this->swap2 = this->get(x + a, y + b);
    
        if(this->swap1 == NULL || this->swap2 == NULL)
        {
            this->setRegisterAsTouchable(true);
            
            return;
        }
    
        float x1 = this->swap1->getCenterX();
        float y1 = this->swap1->getCenterY();
    
        float x2 = this->swap2->getCenterX();
        float y2 = this->swap2->getCenterY();
    
        static_cast<CCSpriteBatchNode*>(this->swap1->getParent())->reorderChild(this->swap1, 30);
        static_cast<CCSpriteBatchNode*>(this->swap1->getParent())->reorderChild(this->swap2, 10);
        
        this->swap1->runAction(CCSequence::create(
                                                  CCScaleTo::create(0.1, 1.1),
                                                  CCScaleTo::create(0.1, 1.0),
                                                  NULL));
        
        this->swap2->runAction(CCSequence::create(
                                                  CCScaleTo::create(0.1, 0.9),
                                                  CCScaleTo::create(0.1, 1.0),
                                                  NULL));
        
        this->swap1->runAction(
                               CCSequence::create(
                                                  CCMoveTo::create(0.2, ccp(x2, y2)),
                                                  CCFadeTo::create(0.02, 255),
                                                  CCCallFunc::create(this, callfunc_selector(GameBackgroundMatrix::onSwapEnd)),
                                                  NULL));
        
        this->swap2->runAction(
                               CCSequence::create(
                                                  CCMoveTo::create(0.2, ccp(x1, y1)),
                                                  CCFadeTo::create(0.02, 255),
                                                  CCCallFunc::create(this, callfunc_selector(GameBackgroundMatrix::onSwapEnd)),
                                                  NULL));
}

void GameBackgroundMatrix::swapBack()
{
    this->swapElements(this->swap1, this->swap2);

    float x1 = this->swap1->getCenterX();
    float y1 = this->swap1->getCenterY();
    
    float x2 = this->swap2->getCenterX();
    float y2 = this->swap2->getCenterY();
    
    static_cast<CCSpriteBatchNode*>(this->swap1->getParent())->reorderChild(this->swap1, 10);
    static_cast<CCSpriteBatchNode*>(this->swap1->getParent())->reorderChild(this->swap2, 30);
    
    this->swap1->runAction(CCSequence::create(
                                              CCScaleTo::create(0.1, 0.9),
                                              CCScaleTo::create(0.1, 1.0),
                                              NULL));

    this->swap2->runAction(CCSequence::create(
                                              CCScaleTo::create(0.1, 1.1),
                                              CCScaleTo::create(0.1, 1.0),
                                              NULL));
    
    this->swap1->runAction(
                           CCSequence::create(
                                              CCMoveTo::create(0.2, ccp(x2, y2)),
                                              CCFadeTo::create(0.02, 255),
                                              CCCallFunc::create(this, callfunc_selector(GameBackgroundMatrix::onSwapAnimationEnd)),
                                              NULL));
    
    this->swap2->runAction(
                           CCSequence::create(
                                              CCMoveTo::create(0.2, ccp(x1, y1)),
                                              CCFadeTo::create(0.02, 255),
                                              CCCallFunc::create(this, callfunc_selector(GameBackgroundMatrix::onSwapAnimationEnd)),
                                              NULL));
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void GameBackgroundMatrix::update(float pDeltaTime)
{
    if(this->mAnimation)
    {
        this->mAnimationTimeElapsed += pDeltaTime;
        
        if(this->mAnimationTimeElapsed >= this->mAnimationTime)
        {
            this->mAnimation = false;
            this->mAnimationTimeElapsed = 0;
            
            bool find = true;

            for(int i = 0; i < this->countX && find; i++)
            {
                for(int j = 0; j < this->countY && find; j++)
                {
                    if(this->findMatches(this->get(i, j), true, -1, -1, -1))
                    {
                        find = false;
                    }
                }
            }
            
            if(find)
            {
                this->setRegisterAsTouchable(true);
            }
        }
    }
}

#endif