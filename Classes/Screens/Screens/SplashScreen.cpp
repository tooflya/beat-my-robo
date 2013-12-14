#ifndef CONST_SPLASHSCREEN
#define CONST_SPLASHSCREEN

#include "SplashScreen.h"

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

SplashScreen::~SplashScreen()
{
}

SplashScreen::SplashScreen()
{
    this->mLayer = CCLayerColor::create(ccc4(255, 255, 255, 255));
    this->mLogo = Entity::create("splash_logo_tfl.png", 0, 0, 596, 240, this->mLayer);

    this->mLogo->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mLogo->setOpacity(0);
    
    this->addChild(this->mLayer);
}

SplashScreen* SplashScreen::create()
{
    SplashScreen* screen = new SplashScreen();
    screen->autorelease();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void SplashScreen::onAnimationEnd()
{
    CCTransitionScene* transition = CCTransitionFade::create(0.3, Loading::create());
    CCDirector::sharedDirector()->replaceScene(transition);
}

// ===========================================================
// Override Methods
// ===========================================================

void SplashScreen::onEnter()
{
    Screen::onEnter();
    
    this->mLogo->runAction(
                           CCSequence::create(CCFadeIn::create(1.0),
                           CCFadeOut::create(1.0),
                           CCCallFunc::create(this, callfunc_selector(SplashScreen::onAnimationEnd)),
                           NULL)
                           );
}

void SplashScreen::onExit()
{
    Screen::onExit();
}

void SplashScreen::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
}

void SplashScreen::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

void SplashScreen::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
}

#endif