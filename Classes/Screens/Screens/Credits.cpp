#ifndef CONST_CREDITSSCREEN
#define CONST_CREDITSSCREEN

#include "Credits.h"

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

Credits::~Credits()
{
}

Credits::Credits()
{
}

Credits* Credits::create()
{
    Credits* screen = new Credits();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void Credits::onEnter()
{
    Screen::onEnter();
}

void Credits::onExit()
{
    Screen::onExit();
}

void Credits::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
}

void Credits::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

void Credits::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
}

#endif