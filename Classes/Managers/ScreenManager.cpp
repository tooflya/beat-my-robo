#ifndef CONST_SCREENMANAGER
#define CONST_SCREENMANAGER

#include "ScreenManager.h"

#include "Screen.h"

#include "Menu.h"
#include "Garage.h"
#include "Languages.h"
#include "Credits.h"
#include "Loader.h"
#include "Game.h"

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

ScreenManager::ScreenManager() :
	mScreens(),
	mCurrentScreenIndex(0)
	{
		this->generate();
        
        //this->set(Screen::SCREEN_MENU);
        this->set(Screen::SCREEN_GAME);
	}

ScreenManager* ScreenManager::create()
{
    ScreenManager* manager = new ScreenManager();
    manager->autorelease();
    manager->retain();
    
    return manager;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Getters
// ===========================================================

// ===========================================================
// Setters
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

void ScreenManager::generate()
{
    this->mScreens[Screen::SCREEN_MENU] = Menu::create();
    this->mScreens[Screen::SCREEN_GARAGE] = Garage::create();
    this->mScreens[Screen::SCREEN_CREDITS] = Credits::create();
    this->mScreens[Screen::SCREEN_LANGUAGES] = Languages::create();
    this->mScreens[Screen::SCREEN_LOADER] = Loader::create();
    this->mScreens[Screen::SCREEN_GAME] = Game::create();
}

void ScreenManager::set(int pIndex)
{
    this->mCurrentScreenIndex = pIndex;
    
    CCTransitionScene* transition = CCTransitionFade::create(0.3, this->mScreens[pIndex]);

    CCDirector::sharedDirector()->replaceScene(transition);
}

// ===========================================================
// Override Methods
// ===========================================================

#endif