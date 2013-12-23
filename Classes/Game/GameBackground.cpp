#ifndef CONST_GAMEBACKGROUND
#define CONST_GAMEBACKGROUND

#include "GameBackground.h"

// ===========================================================
// Inner Classes
// ===========================================================

// ===========================================================
// Constants
// ===========================================================

ccColor3B GameBackground::GRADIENTS[BACKGROUNDS_COUNT][2] =
{
    {
        ccc3(0, 180, 255),
        ccc3(255, 255, 255)
    },
    {
        ccc3(0, 180, 255),
        ccc3(255, 255, 255)
    },
    {
        ccc3(0, 0, 0),
        ccc3(255, 0, 255)
    }
};

CCPoint GameBackground::BACKGROUND_POSITION[BACKGROUNDS_COUNT] =
{
    ccp(0, 0),
    ccp(0, 20),
    ccp(0, 0)
};

const char* GameBackground::BACKGROUNDS[BACKGROUNDS_COUNT] =
{
    "game_ground_svalka@2x.png",
    "game_ground_grass@2x.png",
    "game_ground_space@2x.png"
};

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

GameBackground::~GameBackground()
{
    
}

GameBackground::GameBackground(CCNode* pParent) :
GameBackgroundGradientDelegate(pParent)
{
    this->initialization();

    this->mSpriteBatch1 = SpriteBatch::create("TextureAtlas8", this, false);
    
    this->mBackground = Entity::create(BACKGROUNDS[BATTLE_GRAPHICS_ID], this->mSpriteBatch1);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, this->mBackground->getHeight() / 2 - BACKGROUND_POSITION[BATTLE_GRAPHICS_ID].y);
    
    this->setStartColor(GRADIENTS[BATTLE_GRAPHICS_ID][0]);
    this->setEndColor(GRADIENTS[BATTLE_GRAPHICS_ID][1]);
}

GameBackground* GameBackground::create(CCNode* pParent)
{
    GameBackground* properties = new GameBackground(pParent);
    properties->autorelease();

    return properties;
}

// ===========================================================
// Methods
// ===========================================================

void GameBackground::initialization()
{
    GameBackgroundGradientDelegate::initialization();

    this->setContentSize(CCSize(Options::CAMERA_WIDTH, Options::CAMERA_HEIGHT - this->mDesignedSize - (Options::CAMERA_WIDTH - (this->mDesignedSize - this->mDesigneddoublePaddingSize))));
    this->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - this->getHeight() / 2);
}

// ===========================================================
// Override Methods
// ===========================================================

#endif