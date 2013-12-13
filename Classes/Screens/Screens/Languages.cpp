#ifndef CONST_LANGUAGESSCREEN
#define CONST_LANGUAGESSCREEN

#include "Languages.h"

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

Languages::~Languages()
{
}

Languages::Languages()
{
}

Languages* Languages::create()
{
    Languages* screen = new Languages();
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

void Languages::onEnter()
{
    Screen::onEnter();
}

void Languages::onExit()
{
    Screen::onExit();
}

void Languages::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
}

void Languages::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

void Languages::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
}

#endif