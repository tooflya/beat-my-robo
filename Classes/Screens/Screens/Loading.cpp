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

Loading::Loading()
{
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
}

void Loading::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

void Loading::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
}

#endif