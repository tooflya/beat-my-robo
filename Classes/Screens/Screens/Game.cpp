#ifndef CONST_GAMESSCREEN
#define CONST_GAMESSCREEN

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

Game::~Game()
{
}

Game::Game()
{
    GameBackgroundDelegate::BATTLE_GRAPHICS_ID = Utils::random(0, 3);

    this->mBackgroundArea = GameBackgroundArea::create(this);
    this->mBackgroundField = GameBackgroundField::create(this);
    this->mBackground = GameBackground::create(this);
    this->mBackgroundView = GameBackgroundView::create(this);
}

Game* Game::create()
{
    Game* screen = new Game();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Game::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
        }
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Game::onEnter()
{
    Screen::onEnter();
}

void Game::onExit()
{
    Screen::onExit();
}

void Game::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
}

void Game::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

void Game::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);}

void Game::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
}

#endif