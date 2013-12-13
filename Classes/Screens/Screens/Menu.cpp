#ifndef CONST_MENUSCREEN
#define CONST_MENUSCREEN

#include "Menu.h"

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

Menu::~Menu()
{
}

Menu::Menu()
{
}

Menu* Menu::create()
{
    Menu* screen = new Menu();
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

void Menu::onEnter()
{
    Screen::onEnter();
}

void Menu::onExit()
{
    Screen::onExit();
}

void Menu::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
}

void Menu::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

void Menu::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
}

#endif