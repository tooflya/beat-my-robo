#ifndef CONST_GAMEBACKGROUNDAREA
#define CONST_GAMEBACKGROUNDAREA

#include "GameBackgroundArea.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ccColor3B GameBackgroundArea::GRADIENTS[3][2] =
{
    {
        ccc3(120, 99, 87),
        ccc3(87, 56, 41)
    },
    {
        ccc3(120, 99, 87),
        ccc3(87, 56, 41)
    },
    {
        ccc3(69, 100, 110),
        ccc3(36, 43, 82)
    }
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

GameBackgroundArea::~GameBackgroundArea()
{
}

GameBackgroundArea::GameBackgroundArea(CCNode* pParent) :
GameBackgroundGradientDelegate(pParent)
{
    this->initialization();
    
    /** Temp Solutions */
    
    this->setStartColor(GameBackgroundArea::GRADIENTS[BATTLE_GRAPHICS_ID][0]);
    this->setEndColor(GameBackgroundArea::GRADIENTS[BATTLE_GRAPHICS_ID][1]);
}

GameBackgroundArea* GameBackgroundArea::create(CCNode* pParent)
{
    GameBackgroundArea* properties = new GameBackgroundArea(pParent);
    properties->autorelease();

    return properties;
}

// ===========================================================
// Methods
// ===========================================================

void GameBackgroundArea::initialization()
{
    GameBackgroundGradientDelegate::initialization();
    
    this->setContentSize(CCSize(Options::CAMERA_WIDTH, this->mDesignedSize + (Options::CAMERA_WIDTH - (this->mDesignedSize - this->mDesigneddoublePaddingSize))));
    this->setCenterPosition(Options::CAMERA_CENTER_X, this->getHeight() / 2);
}

// ===========================================================
// Override Methods
// ===========================================================

void GameBackgroundArea::update(float pDeltaTime)
{
    CCLayerColor::update(pDeltaTime);
}

#endif