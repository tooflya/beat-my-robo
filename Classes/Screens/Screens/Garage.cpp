#ifndef CONST_GARAGESCREEN
#define CONST_GARAGESCREEN

#include "Garage.h"

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

Garage::~Garage()
{
}

Garage::Garage()
{
    this->mSpriteBatch1 = SpriteBatch::create("TextureAtlas1", this, true);
    this->mSpriteBatch2 = SpriteBatch::create("TextureAtlas2", this, false);
    this->mSpriteBatch3 = SpriteBatch::create("TextureAtlas3", this, false);
    
    this->mBackground = Entity::create("start_preloader_bg@2x.png", this->mSpriteBatch1);
    
    this->mPlayButton = Button::create("robo_menu_btn_play@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_GARAGE_PLAY, this);
    this->mBackButton = Button::create("info_menu_btn_back@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_BACK, this);

    this->mResourcesIcons[0] = Entity::create("robo_menu_coin_ico_iron@2x.png", this->mSpriteBatch3);
    this->mResourcesIcons[1] = Entity::create("robo_menu_coin_ico_gold@2x.png", this->mSpriteBatch3);
    
    this->mResourcesBackgrounds[0] = Entity::create("robo_menu_coin_bar@2x.png", this->mSpriteBatch3);
    this->mResourcesBackgrounds[1] = Entity::create("robo_menu_coin_bar@2x.png", this->mSpriteBatch3);
    
    this->mResourcesPluses[0] = Button::create("robo_menu_coin_btn_plus@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_GARAGE_PLAY, this);
    this->mResourcesPluses[1] = Button::create("robo_menu_coin_btn_plus@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_GARAGE_PLAY, this);

    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);

    this->mResourcesBackgrounds[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(150), Options::CAMERA_HEIGHT - Utils::coord(100));
    this->mResourcesBackgrounds[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(150), Options::CAMERA_HEIGHT - Utils::coord(100));

    this->mResourcesIcons[0]->create()->setCenterPosition(this->mResourcesBackgrounds[0]->getCenterX() - this->mResourcesBackgrounds[0]->getWidth() / 2, this->mResourcesBackgrounds[0]->getCenterY());
    this->mResourcesIcons[1]->create()->setCenterPosition(this->mResourcesBackgrounds[1]->getCenterX() - this->mResourcesBackgrounds[1]->getWidth() / 2, this->mResourcesBackgrounds[1]->getCenterY());
    
    this->mResourcesPluses[0]->create()->setCenterPosition(this->mResourcesBackgrounds[0]->getCenterX() + this->mResourcesBackgrounds[0]->getWidth() / 2, this->mResourcesBackgrounds[0]->getCenterY());
    this->mResourcesPluses[1]->create()->setCenterPosition(this->mResourcesBackgrounds[1]->getCenterX() + this->mResourcesBackgrounds[1]->getWidth() / 2, this->mResourcesBackgrounds[1]->getCenterY());

    this->mPlayButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(80), Utils::coord(80));
    this->mBackButton->create()->setCenterPosition(Utils::coord(80), Utils::coord(80));
}

Garage* Garage::create()
{
    Garage* screen = new Garage();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Garage::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_GARAGE_PLAY:
            {
                //AppDelegate::screens->set(0);
            }
            break;
            case Options::BUTTONS_ID_BACK:
            {
                this->keyBackClicked(false);
            }
            break;
        }
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Garage::onEnter()
{
    Screen::onEnter();
}

void Garage::onExit()
{
    Screen::onExit();
}

void Garage::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
}

void Garage::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

void Garage::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
}

void Garage::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
    
    AppDelegate::screens->set(Screen::SCREEN_MENU);
}

#endif