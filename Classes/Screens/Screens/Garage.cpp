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

#endif