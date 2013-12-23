#ifndef CONST_GAMEBACKGROUNDVIEW
#define CONST_GAMEBACKGROUNDVIEW

#include "GameBackgroundView.h"

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

GameBackgroundView::~GameBackgroundView()
{
    
}

GameBackgroundView::GameBackgroundView(CCNode* pParent) :
GameBackgroundColorDelegate(pParent)
{
    this->initialization();

    this->mSpriteBatch1 = SpriteBatch::create("TextureAtlas8", this, false);
}

GameBackgroundView* GameBackgroundView::create(CCNode* pParent)
{
    GameBackgroundView* properties = new GameBackgroundView(pParent);
    properties->autorelease();

    return properties;
}

// ===========================================================
// Methods
// ===========================================================

void GameBackgroundView::initialization()
{
    GameBackgroundColorDelegate::initialization();

    this->setContentSize(CCSize(Options::CAMERA_WIDTH, Options::CAMERA_HEIGHT - this->mDesignedSize - (Options::CAMERA_WIDTH - (this->mDesignedSize - this->mDesigneddoublePaddingSize))));
    this->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - this->getHeight() / 2);
}

// ===========================================================
// Override Methods
// ===========================================================

#endif