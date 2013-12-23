#ifndef CONST_PROPERTIES
#define CONST_PROPERTIES

#include "Properties.h"

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

Properties::~Properties()
{
    
}

Properties::Properties(CCNode* pParent)
{
    this->mSpriteBatch = SpriteBatch::create("TextureAtlas6", this, false);

    this->mPropertiesBackground = Entity::create("robo_menu_popup@2x.png", this->mSpriteBatch);
    this->mPropertiesNameBackground = Entity::create("robo_menu_stat_popup_bg_robo_name@2x.png", this->mSpriteBatch);

    this->mPropertiesBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(280));
    this->mPropertiesNameBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + this->mPropertiesBackground->getHeight() / 2 + Utils::coord(280));
    
    this->mPropertiesIcons[0] = Entity::create("robo_menu_stat_popup_ico_stats@2x.png", 2, 2, this);
    this->mPropertiesIcons[1] = Entity::create("robo_menu_stat_popup_ico_stats@2x.png", 2, 2, this);
    this->mPropertiesIcons[2] = Entity::create("robo_menu_stat_popup_ico_stats@2x.png", 2, 2, this);
    this->mPropertiesIcons[3] = Entity::create("robo_menu_stat_popup_ico_stats@2x.png", 2, 2, this);
    
    this->mPropertiesIcons[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - this->mPropertiesBackground->getWidth() / 2 + Utils::coord(60), this->mPropertiesBackground->getCenterY() + Utils::coord(120));
    this->mPropertiesIcons[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X - this->mPropertiesBackground->getWidth() / 2 + Utils::coord(60), this->mPropertiesBackground->getCenterY() + Utils::coord(40));
    this->mPropertiesIcons[2]->create()->setCenterPosition(Options::CAMERA_CENTER_X - this->mPropertiesBackground->getWidth() / 2 + Utils::coord(60), this->mPropertiesBackground->getCenterY() - Utils::coord(40));
    this->mPropertiesIcons[3]->create()->setCenterPosition(Options::CAMERA_CENTER_X - this->mPropertiesBackground->getWidth() / 2 + Utils::coord(60), this->mPropertiesBackground->getCenterY() - Utils::coord(120));
    
    this->mPropertiesIcons[0]->setCurrentFrameIndex(0);
    this->mPropertiesIcons[1]->setCurrentFrameIndex(1);
    this->mPropertiesIcons[2]->setCurrentFrameIndex(2);
    this->mPropertiesIcons[3]->setCurrentFrameIndex(3);
    
    for(int i = 0; i < 24; i++)
    {
        this->mSquares[i] = Entity::create("robo_menu_stat_popup_ico_count@2x.png", 5, 1, this->mSpriteBatch);
    }

    float x, y;
    int counter = 0;
    
    for(int i = 0; i < 4; i ++)
    {
        y = this->mPropertiesBackground->getCenterY() + Utils::coord(120) - Utils::coord(80) * i;
        x = Options::CAMERA_CENTER_X - this->mPropertiesBackground->getWidth() / 2 + Utils::coord(140);

        for(int j = 0; j < 6; j++)
        {
            int frame = 0;
            
            if(j == 0)
            {
                frame = i;
            }
            else
            {
                frame = 4;
            }
            
            this->mSquares[counter]->create()->setCenterPosition(x, y);
            this->mSquares[counter]->setCurrentFrameIndex(frame);
            
            if(j == 5)
            {
                this->mBuyButtons[i] = Entity::create("robo_menu_stat_popup_btn_upgrade@2x.png", 1, 2, this->mSpriteBatch);
                this->mBuyButtons[i]->create()->setCenterPosition(x + Utils::coord(110), y);
            }

            x += this->mSquares[0]->getWidth() - Utils::coord(10);
            
            counter++;
            
            if(j == 0)
            {
                this->mSquares[counter]->setZOrder(5);
                //x += Utils::coord(3);
            }
            else
            {
                this->mSquares[counter]->setZOrder(4);
            }
        }
    }
    
    pParent->addChild(this);
}

Properties* Properties::create(CCNode* pParent)
{
    Properties* properties = new Properties(pParent);
    properties->autorelease();

    return properties;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

#endif