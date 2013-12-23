#ifndef CONST_LOADERSCREEN
#define CONST_LOADERSCREEN

#include "Loader.h"

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

Loader::~Loader()
{
}

Loader::Loader() :
mLoading(false),
mLoadingTime(3.0),
mLoadingTimeElapsed(0)
{
    this->mSpriteBatch1 = SpriteBatch::create("TextureAtlas1", this, true);
    this->mSpriteBatch2 = SpriteBatch::create("TextureAtlas1", this, false);
    this->mSpriteBatch3 = SpriteBatch::create("TextureAtlas5", this, false);
    
    this->mBackground = Entity::create("start_preloader_bg@2x.png", this->mSpriteBatch1);
    this->mBackgroundName = Entity::create("lvl_preloader_portal@2x.png", this->mSpriteBatch3);
    this->mPreloader = Entity::create("preloader_big.png", this->mSpriteBatch2);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackgroundName->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200));
    this->mPreloader->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64), Utils::coord(64));
    
    this->mPreloader->runAction(CCRepeatForever::create(CCRotateTo::create(0.5, 720)));
}

Loader* Loader::create()
{
    Loader* screen = new Loader();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Loader::onLoadingComplete()
{
    AppDelegate::screens->set(Screen::SCREEN_GAME);
}

// ===========================================================
// Override Methods
// ===========================================================

void Loader::onEnter()
{
    Screen::onEnter();
}

void Loader::onExit()
{
    Screen::onExit();
}

void Loader::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
    
    this->mLoading = true;
}

void Loader::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

void Loader::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    if(this->mLoading)
    {
        this->mLoadingTimeElapsed += pDeltaTime;
        
        if(this->mLoadingTimeElapsed >= this->mLoadingTime)
        {
            this->mLoading = false;
            
            this->onLoadingComplete();
        }
    }
}

#endif