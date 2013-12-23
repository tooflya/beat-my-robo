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

Menu::Menu() :
mSettingsShowed(false)
{
    this->mSpriteBatch1 = SpriteBatch::create("TextureAtlas1", this, true);
    this->mSpriteBatch5 = SpriteBatch::create("TextureAtlas5", this, false);
    this->mSpriteBatch2 = SpriteBatch::create("TextureAtlas2", this, false);
    this->mSpriteBatch3 = SpriteBatch::create("TextureAtlas3", this, false);

    this->mBackground = Entity::create("start_preloader_bg@2x.png", this->mSpriteBatch1);
    this->mBackgroundDecoration1 = Entity::create("main_menu_bg_deco1@2x.png", this->mSpriteBatch2);
    this->mBackgroundName = Entity::create("start_preloader_name@2x.png", this->mSpriteBatch5);

    this->mPlayButton = Button::create("main_menu_btn_play@2x.png", 2, 1, this->mSpriteBatch2, Options::BUTTONS_ID_MENU_PLAY, this);
    this->mMusicButton = Button::create("main_menu_btn_mfx@2x.png", 2, 2, this->mSpriteBatch3, Options::BUTTONS_ID_MENU_MUSIC, this);
    this->mSoundButton = Button::create("main_menu_btn_sfx@2x.png", 2, 2, this->mSpriteBatch3, Options::BUTTONS_ID_MENU_SOUND, this);
    this->mCreditsButton = Button::create("main_menu_btn_info@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_MENU_CREDITS, this);
    this->mSettingsButton = Button::create("main_menu_btn_settings@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_MENU_SETTINGS, this);
    this->mTwitterButton = Button::create("main_menu_btn_tw@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_MENU_TWITTER, this);
    this->mFacebookButton = Button::create("main_menu_btn_fb@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_MENU_FACEBOOK, this);
    this->mLanguageButton = Button::create("main_menu_btn_language@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_MENU_LANGUAGE, this);
    this->mLanguageIndicator = Entity::create("main_menu_btn_language_flag_sprite@2x.png", 2, 5, this->mLanguageButton);

    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackgroundName->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - this->mBackgroundName->getHeight() / 2 - Utils::coord(50));
    this->mBackgroundDecoration1->create()->setCenterPosition(Options::CAMERA_CENTER_X, Utils::coord(500));

    this->mPlayButton->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mSettingsButton->create()->setCenterPosition(Utils::coord(80), Utils::coord(80));
    this->mCreditsButton->create()->setCenterPosition(Utils::coord(80), Utils::coord(80));
    this->mMusicButton->create()->setCenterPosition(Utils::coord(80), Utils::coord(80));
    this->mSoundButton->create()->setCenterPosition(Utils::coord(80), Utils::coord(80));
    this->mTwitterButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(80), Utils::coord(80));
    this->mFacebookButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(220), Utils::coord(80));
    this->mLanguageButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(360), Utils::coord(80));
    this->mLanguageIndicator->create()->setCenterPosition(this->mLanguageButton->getWidth() / 2, this->mLanguageButton->getHeight() / 2);
    
    this->mPlayButton->setZOrder(1);
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

void Menu::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
            switch(pID)
            {
                case Options::BUTTONS_ID_MENU_PLAY:
                {
                    AppDelegate::screens->set(Screen::SCREEN_GARAGE);
                }
                break;
                case Options::BUTTONS_ID_MENU_SETTINGS:
                {
                    this->settingsAnimation();
                }
                break;
                case Options::BUTTONS_ID_MENU_CREDITS:
                {
                    AppDelegate::screens->set(Screen::SCREEN_CREDITS);
                }
                break;
                case Options::BUTTONS_ID_MENU_SOUND:
                {
                    this->checkSound();
                }
                break;
                case Options::BUTTONS_ID_MENU_MUSIC:
                {
                    this->checkMusic();
                }
                break;
                case Options::BUTTONS_ID_MENU_TWITTER:
                {
                    // TODO: Call JNI
                }
                break;
                case Options::BUTTONS_ID_MENU_FACEBOOK:
                {
                    // TODO: Call JNI
                }
                break;
                case Options::BUTTONS_ID_MENU_LANGUAGE:
                {
                    AppDelegate::screens->set(Screen::SCREEN_LANGUAGES);
                }
                break;
            }
    }
}

void Menu::checkMusic()
{
    Options::MUSIC_ENABLE = !Options::MUSIC_ENABLE;
    
    if(Options::MUSIC_ENABLE)
    {
        this->mMusicButton->setCurrentFrameIndex(0);
    }
    else
    {
        this->mMusicButton->setCurrentFrameIndex(2);
    }
    
    AppDelegate::setMusicEnable(Options::MUSIC_ENABLE);
}

void Menu::checkSound()
{
    Options::SOUND_ENABLE = !Options::SOUND_ENABLE;
    
    if(Options::SOUND_ENABLE)
    {
        this->mSoundButton->setCurrentFrameIndex(0);
    }
    else
    {
        this->mSoundButton->setCurrentFrameIndex(2);
    }
    
    AppDelegate::setSoundEnable(Options::SOUND_ENABLE);
}

void Menu::settingsAnimation()
{
    if(this->mMusicButton->numberOfRunningActions() > 0) return;
    
    if(this->mSettingsShowed)
    {
        this->mMusicButton->runAction(
                                      CCSequence::create(
                                                         CCScaleTo::create(0.2, 1),
                                                         CCMoveTo::create(0.2, ccp(Utils::coord(80), Utils::coord(260))),
                                                         CCMoveTo::create(0.1, ccp(Utils::coord(80), Utils::coord(80))), NULL));
        this->mSoundButton->runAction(
                                      CCSequence::create(
                                                         CCScaleTo::create(0.1, 1),
                                                         CCMoveTo::create(0.2, ccp(Utils::coord(220), Utils::coord(220))),
                                                         CCMoveTo::create(0.1, ccp(Utils::coord(80), Utils::coord(80))), NULL));
        this->mCreditsButton->runAction(
                                        CCSequence::create(
                                                           CCMoveTo::create(0.2, ccp(Utils::coord(260), Utils::coord(80))),
                                                           CCMoveTo::create(0.1, ccp(Utils::coord(80), Utils::coord(80))), NULL));
        
        this->mMusicButton->runAction(CCRotateTo::create(0.5, 720));
        this->mSoundButton->runAction(CCRotateTo::create(0.4, 720));
        this->mCreditsButton->runAction(CCRotateTo::create(0.3, 720));
    }
    else
    {
        this->mMusicButton->runAction(
                                      CCSequence::create(
                                                         CCMoveTo::create(0.2, ccp(Utils::coord(80), Utils::coord(260))),
                                                         CCMoveTo::create(0.1, ccp(Utils::coord(80), Utils::coord(230))), NULL));
        this->mSoundButton->runAction(
                                      CCSequence::create(
                                                         CCScaleTo::create(0.1, 1),
                                                         CCMoveTo::create(0.2, ccp(Utils::coord(220), Utils::coord(220))),
                                                         CCMoveTo::create(0.1, ccp(Utils::coord(190), Utils::coord(190))), NULL));
        this->mCreditsButton->runAction(
                                        CCSequence::create(
                                                           CCScaleTo::create(0.2, 1),
                                                           CCMoveTo::create(0.2, ccp(Utils::coord(260), Utils::coord(80))),
                                                           CCMoveTo::create(0.1, ccp(Utils::coord(230), Utils::coord(80))), NULL));
        
        this->mMusicButton->runAction(CCRotateTo::create(0.3, 720));
        this->mSoundButton->runAction(CCRotateTo::create(0.4, 720));
        this->mCreditsButton->runAction(CCRotateTo::create(0.5, 720));
    }
    
    this->mSettingsShowed = !this->mSettingsShowed;
}

// ===========================================================
// Override Methods
// ===========================================================

void Menu::onEnter()
{
    Screen::onEnter();
    
    this->mCreditsButton->setCenterPosition(Utils::coord(80), Utils::coord(80));
    this->mMusicButton->setCenterPosition(Utils::coord(80), Utils::coord(80));
    this->mSoundButton->setCenterPosition(Utils::coord(80), Utils::coord(80));
    
    this->mLanguageIndicator->setCurrentFrameIndex(Options::CURRENT_LANGUAGE);
    
    this->mSettingsShowed = false;
    
    if(Options::MUSIC_ENABLE)
    {
        this->mMusicButton->setCurrentFrameIndex(0);
    }
    else
    {
        this->mMusicButton->setCurrentFrameIndex(2);
    }
    
    if(Options::SOUND_ENABLE)
    {
        this->mSoundButton->setCurrentFrameIndex(0);
    }
    else
    {
        this->mSoundButton->setCurrentFrameIndex(2);
    }
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