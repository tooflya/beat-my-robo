#ifndef CONST_LOADINGSCREEN
#define CONST_LOADINGSCREEN

#include "Loading.h"

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

Loading::~Loading()
{
}

Loading::Loading() :
mLoading(false),
mLoadingTime(3.0),
mLoadingTimeElapsed(0)
{
    this->mSpriteBatch1 = SpriteBatch::create("TextureAtlas1", this, true);
    this->mSpriteBatch2 = SpriteBatch::create("TextureAtlas1", this, false);
    this->mSpriteBatch3 = SpriteBatch::create("TextureAtlas5", this, false);
    
    this->mBackground = Entity::create("start_preloader_bg@2x.png", this->mSpriteBatch1);
    this->mPreloader = Entity::create("preloader_big.png", this->mSpriteBatch2);
    this->mLogo = Entity::create("start_preloader_name@2x.png", this->mSpriteBatch3);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mPreloader->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(64), Utils::coord(64));
    this->mLogo->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200));
    
    this->mPreloader->runAction(CCRepeatForever::create(CCRotateTo::create(0.5, 720)));
}

Loading* Loading::create()
{
    Loading* screen = new Loading();
    screen->autorelease();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Loading::onLoadingComplete()
{
    Options::changeLanguage();
    
    AppDelegate::screens = ScreenManager::create();
}

// ===========================================================
// Override Methods
// ===========================================================

void Loading::onEnter()
{
    Screen::onEnter();
}

void Loading::onExit()
{
    Screen::onExit();
}

void Loading::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
    
    this->mLoading = true;
}

void Loading::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

void Loading::update(float pDeltaTime)
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