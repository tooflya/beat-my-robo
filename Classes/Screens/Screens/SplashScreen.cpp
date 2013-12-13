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

SplashScreen::SplashScreen() :
mLogos()
{
    this->mAnimationCounter = 4; //Options::IS_BUILD_FOR_ABSOLUTIST ? 0 : 4;

    this->mAnimation = false;
    
    this->mAnimationTime = 1.0;
    this->mAnimationTimeElapsed = 0;
    
    CCLayerColor* layer = CCLayerColor::create(ccc4(255, 255, 255, 255));
	//this->mLogos[0] = Entity::create("splash_logo_abs.png", 0, 0, 620, 221, layer);
    this->mLogos[1] = Entity::create("splash_logo_tfl.png", 0, 0, 596, 240, layer);
    
    this->addChild(layer);
	
	#if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
    AppDelegate::screens = ScreenManager::create();
	#endif

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
    
    this->mAnimation = true;
}

void SplashScreen::onExit()
{
    Screen::onExit();
}

void SplashScreen::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
    
    if(this->mAnimation)
    {
        this->mAnimationTimeElapsed += pDeltaTime;
        
        if(this->mAnimationTimeElapsed >= this->mAnimationTime)
        {
            this->mAnimationTimeElapsed = 0;
            this->mAnimationCounter++;
            
            switch(this->mAnimationCounter)
            {
                case 1:
                    this->mLogos[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
                    this->mLogos[0]->setOpacity(0);
                    this->mLogos[0]->runAction(CCFadeIn::create(this->mAnimationTime));
                break;
                case 3:
                    this->mLogos[0]->runAction(CCFadeOut::create(this->mAnimationTime));
                    
                    this->mAnimationTime = 0.8;
                break;
                case 5:
                    this->mAnimationTime = 1.0;
                    
                    this->mLogos[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
                    this->mLogos[1]->setOpacity(0);
                    this->mLogos[1]->runAction(CCFadeIn::create(this->mAnimationTime));
                break;
                case 7:
                    this->mLogos[1]->runAction(CCFadeOut::create(this->mAnimationTime));
                break;
                case 8:
                    this->mAnimation = false;
                    
					//CCTransitionScene* transition = CCTransitionFade::create(0.3, Loading::create());
					//CCDirector::sharedDirector()->replaceScene(transition);
                break;
            }
        }
    }
}

#endif