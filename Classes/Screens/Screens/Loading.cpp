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
    this->mBackgroundName = Entity::create("start_preloader_name@2x.png", this->mSpriteBatch3);

    this->mPreloader = Spine::create("skeleton", this);

    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackgroundName->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200));
    
    this->mPreloader->setCenterPosition(Options::CAMERA_CENTER_X, Utils::coord(100));
    
	this->mPreloader->setMix("wait", "walk", 0.2f);
	this->mPreloader->setMix("walk", "wait", 0.2f);

    this->mPreloader->setAnimation(0, "walk", true);
    this->mPreloader->addAnimation(0, "wait", true, 10);
    this->mPreloader->addAnimation(0, "walk", true, 10);
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