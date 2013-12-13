#ifndef CONST_SPLASHSCREEN
#define CONST_SPLASHSCREEN

#include "SplashScreen.h"

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

// ===========================================================
// Override Methods
// ===========================================================

void SplashScreen::onEnter()
{
    Screen::onEnter();
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