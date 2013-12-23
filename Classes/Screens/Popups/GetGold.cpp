#ifndef CONST_GETGOLD
#define CONST_GETGOLD

#include "GetGold.h"

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

GetGold::~GetGold()
{
}

GetGold::GetGold(CCNode* pParent) :
    Popup(pParent)
    {
        this->mTextBackground = Entity::create("robo_menu_convert_textbox@2x.png", this->mSpriteBatch);
        this->mIllustration = Entity::create("robo_menu_gold_picture@2x.png", this->mSpriteBatch);

        this->mGetButtons[0] = Button::create("robo_menu_buy_gold_btn1@2x.png", 1, 2, this->mSpriteBatch, Options::BUTTONS_ID_GET_GOLD_1, this);
        this->mGetButtons[1] = Button::create("robo_menu_buy_gold_btn2@2x.png", 1, 2, this->mSpriteBatch, Options::BUTTONS_ID_GET_GOLD_2, this);
        this->mGetButtons[2] = Button::create("robo_menu_buy_gold_btn3@2x.png", 1, 2, this->mSpriteBatch, Options::BUTTONS_ID_GET_GOLD_3, this);
        this->mGetButtons[3] = Button::create("robo_menu_buy_gold_btn4@2x.png", 1, 2, this->mSpriteBatch, Options::BUTTONS_ID_GET_GOLD_4, this);
        
        this->mText = Text::create(Options::TEXT_BUY_GOLD, this);
        this->mText->setColor(ccc3(50.0, 32.0, 2.0));
        this->mText->disableShadow();
        
        this->mTextBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(80));
        this->mIllustration->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(60), Options::CAMERA_CENTER_Y + Utils::coord(295));

        this->mGetButtons[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - this->mGetButtons[0]->getWidth() * 1.5 - Utils::coord(15), Options::CAMERA_CENTER_Y - Utils::coord(65));
        this->mGetButtons[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X - this->mGetButtons[1]->getWidth() / 2 - Utils::coord(5), Options::CAMERA_CENTER_Y - Utils::coord(65));
        this->mGetButtons[2]->create()->setCenterPosition(Options::CAMERA_CENTER_X + this->mGetButtons[2]->getWidth() / 2 + Utils::coord(5), Options::CAMERA_CENTER_Y - Utils::coord(65));
        this->mGetButtons[3]->create()->setCenterPosition(Options::CAMERA_CENTER_X + this->mGetButtons[3]->getWidth() * 1.5 + Utils::coord(15), Options::CAMERA_CENTER_Y - Utils::coord(65));
        
        this->mText->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(80));
    }

GetGold* GetGold::create(CCNode* pParent)
{
    GetGold* popup = new GetGold(pParent);
    popup->autorelease();
    popup->retain();
    
    return popup;
}

// ===========================================================
// Methods
// ===========================================================

void GetGold::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            default:
            this->hide();
            break;
            case Options::BUTTONS_ID_GET_GOLD_1:
            break;
            case Options::BUTTONS_ID_GET_GOLD_2:
            break;
            case Options::BUTTONS_ID_GET_GOLD_3:
            break;
            case Options::BUTTONS_ID_GET_GOLD_4:
            break;
        }
        break;
            
        case Options::BUTTONS_ACTION_ONBEGIN:
        break;
            
        case Options::BUTTONS_ACTION_ONEND:
        break;
    }
}

// ===========================================================
// Override Methods
// ===========================================================

#endif