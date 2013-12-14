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
    this->mSpriteBatch1 = SpriteBatch::create("TextureAtlas1", this, true);
    this->mSpriteBatch2 = SpriteBatch::create("TextureAtlas2", this, false);
    this->mSpriteBatch3 = SpriteBatch::create("TextureAtlas3", this, false);
    this->mSpriteBatch4 = SpriteBatch::create("TextureAtlas4", this, false);
    
    this->mBackground = Entity::create("start_preloader_bg@2x.png", this->mSpriteBatch1);
    this->mBackgroundDecoration = Entity::create("lang_menu_bg_deco4@2x.png", this->mSpriteBatch2);
    
    this->mBackButton = Button::create("info_menu_btn_back@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_BACK, this);

    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackgroundDecoration->create()->setCenterPosition(Options::CAMERA_CENTER_X, this->mBackgroundDecoration->getHeight() / 2);

    this->mBackButton->create()->setCenterPosition(Utils::coord(80), Utils::coord(80));

    this->mLanguages[0] = Button::create("lang_menu_flag_sprite@2x.png", 2, 5, this->mSpriteBatch4, Options::BUTTONS_ID_LANGUAGE_L_EN, this);
    this->mLanguages[1] = Button::create("lang_menu_flag_sprite@2x.png", 2, 5, this->mSpriteBatch4, Options::BUTTONS_ID_LANGUAGE_L_RU, this);
    this->mLanguages[2] = Button::create("lang_menu_flag_sprite@2x.png", 2, 5, this->mSpriteBatch4, Options::BUTTONS_ID_LANGUAGE_L_DE, this);
    this->mLanguages[3] = Button::create("lang_menu_flag_sprite@2x.png", 2, 5, this->mSpriteBatch4, Options::BUTTONS_ID_LANGUAGE_L_ES, this);
    this->mLanguages[4] = Button::create("lang_menu_flag_sprite@2x.png", 2, 5, this->mSpriteBatch4, Options::BUTTONS_ID_LANGUAGE_L_FR, this);
    this->mLanguages[5] = Button::create("lang_menu_flag_sprite@2x.png", 2, 5, this->mSpriteBatch4, Options::BUTTONS_ID_LANGUAGE_L_NL, this);
    this->mLanguages[6] = Button::create("lang_menu_flag_sprite@2x.png", 2, 5, this->mSpriteBatch4, Options::BUTTONS_ID_LANGUAGE_L_IT, this);
    this->mLanguages[7] = Button::create("lang_menu_flag_sprite@2x.png", 2, 5, this->mSpriteBatch4, Options::BUTTONS_ID_LANGUAGE_L_JP, this);
    this->mLanguages[8] = Button::create("lang_menu_flag_sprite@2x.png", 2, 5, this->mSpriteBatch4, Options::BUTTONS_ID_LANGUAGE_L_KR, this);
    this->mLanguages[9] = Button::create("lang_menu_flag_sprite@2x.png", 2, 5, this->mSpriteBatch4, Options::BUTTONS_ID_LANGUAGE_L_CN, this);
    
    this->mLanguages[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(150), Options::CAMERA_CENTER_Y + Utils::coord(460));
    this->mLanguages[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(150), Options::CAMERA_CENTER_Y + Utils::coord(460));
    this->mLanguages[2]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(150), Options::CAMERA_CENTER_Y + Utils::coord(260));
    this->mLanguages[3]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(150), Options::CAMERA_CENTER_Y + Utils::coord(260));
    this->mLanguages[4]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(150), Options::CAMERA_CENTER_Y + Utils::coord(60));
    this->mLanguages[5]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(150), Options::CAMERA_CENTER_Y + Utils::coord(60));
    this->mLanguages[6]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(150), Options::CAMERA_CENTER_Y - Utils::coord(140));
    this->mLanguages[7]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(150), Options::CAMERA_CENTER_Y - Utils::coord(140));
    this->mLanguages[8]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(150), Options::CAMERA_CENTER_Y - Utils::coord(340));
    this->mLanguages[9]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(150), Options::CAMERA_CENTER_Y - Utils::coord(340));
    
    this->mTextes[0] = Text::create(Options::TEXT_LANGUAGE_L_EN, this);
    this->mTextes[1] = Text::create(Options::TEXT_LANGUAGE_L_RU, this);
    this->mTextes[2] = Text::create(Options::TEXT_LANGUAGE_L_DE, this);
    this->mTextes[3] = Text::create(Options::TEXT_LANGUAGE_L_ES, this);
    this->mTextes[4] = Text::create(Options::TEXT_LANGUAGE_L_FR, this);
    this->mTextes[5] = Text::create(Options::TEXT_LANGUAGE_L_NL, this);
    this->mTextes[6] = Text::create(Options::TEXT_LANGUAGE_L_IT, this);
    this->mTextes[7] = Text::create(Options::TEXT_LANGUAGE_L_JP, this);
    this->mTextes[8] = Text::create(Options::TEXT_LANGUAGE_L_KR, this);
    this->mTextes[9] = Text::create(Options::TEXT_LANGUAGE_L_CN, this);

    for(int i = 0; i < 10; i++)
    {
        this->mLanguages[i]->setCurrentFrameIndex(i);
        this->mLanguages[i]->setScaleAnimation();
        
        this->mTextes[i]->setCenterPosition(this->mLanguages[i]->getCenterX(), this->mLanguages[i]->getCenterY() - Utils::coord(68));
        this->mTextes[i]->CCLabelTTF::enableShadow(CCSize(Utils::coord(1), -Utils::coord(1)), 255.0, 0.0, false);
    }
    
    this->mLanguageIndicator = Entity::create("lang_menu_flag_check@2x.png", this->mSpriteBatch4);
    this->mLanguageIndicator->create();
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

void Languages::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_LANGUAGE_L_RU:
            Options::CURRENT_LANGUAGE = 1;
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_EN:
            Options::CURRENT_LANGUAGE = 0;
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_DE:
            // TODO: Change language;
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_ES:
            // TODO: Change language;
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_FR:
            // TODO: Change language;
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_NL:
            // TODO: Change language;
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_IT:
            // TODO: Change language;
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_JP:
            // TODO: Change language;
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_KR:
            // TODO: Change language;
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_CN:
            // TODO: Change language;
            break;
        }

        switch(pID)
        {
            case Options::BUTTONS_ID_BACK:
            {
            this->keyBackClicked(false);
            }
            break;
            case Options::BUTTONS_ID_LANGUAGE_L_RU:
            case Options::BUTTONS_ID_LANGUAGE_L_EN:
            /*case Options::BUTTONS_ID_LANGUAGE_L_DE:
            case Options::BUTTONS_ID_LANGUAGE_L_ES:
            case Options::BUTTONS_ID_LANGUAGE_L_FR:
            case Options::BUTTONS_ID_LANGUAGE_L_NL:
            case Options::BUTTONS_ID_LANGUAGE_L_IT:
            case Options::BUTTONS_ID_LANGUAGE_L_JP:
            case Options::BUTTONS_ID_LANGUAGE_L_KR:
            case Options::BUTTONS_ID_LANGUAGE_L_CN:*/
            Options::changeLanguage();
            break;
        }
    }
}

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
    
    for(int i = 0; i < 10; i++)
    {
        this->mTextes[i]->setScale(this->mLanguages[i]->getScaleX());
        this->mTextes[i]->setCenterPosition(this->mLanguages[i]->getCenterX(), this->mLanguages[i]->getCenterY() - Utils::coord(68) * this->mLanguages[i]->getScaleX());
    }
    
    this->mLanguageIndicator->setScale(this->mLanguages[Options::CURRENT_LANGUAGE]->getScaleX());
    this->mLanguageIndicator->setCenterPosition(this->mLanguages[Options::CURRENT_LANGUAGE]->getCenterX() + this->mLanguages[Options::CURRENT_LANGUAGE]->getWidthScaled() / 2 - Utils::coord(22) * this->mLanguages[Options::CURRENT_LANGUAGE]->getScaleX(), this->mLanguages[Options::CURRENT_LANGUAGE]->getCenterY() - this->mLanguages[Options::CURRENT_LANGUAGE]->getHeightScaled() / 2 + Utils::coord(32) * this->mLanguages[Options::CURRENT_LANGUAGE]->getScaleY());
}

void Languages::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
    
    AppDelegate::screens->set(Screen::SCREEN_MENU);
}

#endif