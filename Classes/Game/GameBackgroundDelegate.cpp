#ifndef CONST_GAMEBACKGROUNDDELEGATE
#define CONST_GAMEBACKGROUNDDELEGATE

#include "GameBackgroundDelegate.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

int GameBackgroundDelegate::BATTLE_GRAPHICS_ID = -1;

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

GameBackgroundDelegate::GameBackgroundDelegate()
{
    this->mDesignedSize = Utils::coord(720);
    this->mDesignedPaddingSize = Utils::coord(9);
    this->mDesigneddoublePaddingSize = Utils::coord(18);
}

GameBackgroundColorDelegate::GameBackgroundColorDelegate(CCNode* pParent) :
GameBackgroundDelegate()
{
    if(pParent)
    {
        pParent->addChild(this);
    }
}

GameBackgroundGradientDelegate::GameBackgroundGradientDelegate(CCNode* pParent) :
GameBackgroundDelegate()
{
    if(pParent)
    {
        pParent->addChild(this);
    }
}

// ===========================================================
// Methods
// ===========================================================

void GameBackgroundColorDelegate::initialization()
{
    this->initWithColor(ccc4(255, 255, 255, 255));

    this->ignoreAnchorPointForPosition(false);
    
    this->setAnchorPoint(ccp(0.5, 0.5));
}

void GameBackgroundGradientDelegate::initialization()
{
    this->initWithColor(ccc4(255, 255, 255, 255), ccc4(255, 255, 255, 255));
    
    this->ignoreAnchorPointForPosition(false);
    
    this->setAnchorPoint(ccp(0.5, 0.5));
}

void GameBackgroundColorDelegate::setCenterPosition(float pCenterX, float pCenterY)
{
    this->setPosition(ccp(pCenterX, pCenterY));
}

void GameBackgroundGradientDelegate::setCenterPosition(float pCenterX, float pCenterY)
{
    this->setPosition(ccp(pCenterX, pCenterY));
}

float GameBackgroundColorDelegate::getWidth()
{
    return this->getContentSize().width;
}

float GameBackgroundColorDelegate::getHeight()
{
    return this->getContentSize().height;
}

float GameBackgroundGradientDelegate::getWidth()
{
    return this->getContentSize().width;
}

float GameBackgroundGradientDelegate::getHeight()
{
    return this->getContentSize().height;
}

CCPoint GameBackgroundColorDelegate::getCenterPosition()
{
    return this->getPosition();
}

// ===========================================================
// Override Methods
// ===========================================================

#endif