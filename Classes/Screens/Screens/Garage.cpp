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
    CC_SAFE_RELEASE(this->mGetGoldPopup);
    CC_SAFE_RELEASE(this->mGetSilverPopup);
}

Garage::Garage()
{
    this->mSpriteBatch1 = SpriteBatch::create("TextureAtlas1", this, true);
    this->mSpriteBatch2 = SpriteBatch::create("TextureAtlas2", this, false);
    this->mSpriteBatch3 = SpriteBatch::create("TextureAtlas3", this, false);
    this->mSpriteBatch4 = SpriteBatch::create("TextureAtlas2", this, false);
    this->mSpriteBatch5 = SpriteBatch::create("TextureAtlas3", this, false);
    
    this->mBackground = Entity::create("start_preloader_bg@2x.png", this->mSpriteBatch1);
    this->mBackgroundDecoration = Entity::create("robo_menu_machine@2x.png", this->mSpriteBatch2);
    
    this->mBaloon = Entity::create("robo_menu_unlock_dialog_cloud@2x.png", this);
    this->mBaloonResourcesIcons[0] = Entity::create("robo_menu_coin_ico_iron@2x.png", this->mBaloon);
    this->mBaloonResourcesIcons[1] = Entity::create("robo_menu_coin_ico_gold@2x.png", this->mBaloon);
    
    this->mPlayButton = Button::create("robo_menu_btn_play@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_GARAGE_PLAY, this);
    this->mBackButton = Button::create("info_menu_btn_back@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_BACK, this);
    
    this->mResourcesBackgrounds[0] = Entity::create("robo_menu_coin_bar@2x.png", this->mSpriteBatch3);
    this->mResourcesBackgrounds[1] = Entity::create("robo_menu_coin_bar@2x.png", this->mSpriteBatch3);
    
    this->mResourcesIcons[0] = Entity::create("robo_menu_coin_ico_iron@2x.png", this->mSpriteBatch3);
    this->mResourcesIcons[1] = Entity::create("robo_menu_coin_ico_gold@2x.png", this->mSpriteBatch3);
    
    this->mResourcesPluses[0] = Button::create("robo_menu_coin_btn_plus@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_GARAGE_GET_GOLD, this);
    this->mResourcesPluses[1] = Button::create("robo_menu_coin_btn_plus@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_GARAGE_GET_SILVER, this);
    
    this->mMoveButtons[0] = Button::create("robo_menu_machine_btn_list_sprite@2x.png", 3, 1, this->mSpriteBatch3, Options::BUTTONS_ID_GARAGE_MOVE_LEFT, this);
    this->mMoveButtons[1] = Button::create("robo_menu_machine_btn_list_sprite@2x.png", 3, 1, this->mSpriteBatch3, Options::BUTTONS_ID_GARAGE_MOVE_RIGHT, this);
    
    this->mSelectCharacter = Button::create("robo_menu_machine_platform_btn_select@2x.png", 1, 2, this->mSpriteBatch5, Options::BUTTONS_ID_GARAGE_SELECT, this);
    this->mSelectCharacter->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Options::CAMERA_HEIGHT);

    for(int i = -2; i < 5 + 3; i++) // TODO: Robots count here!
    {
        Entity* platform = Entity::create("robo_menu_machine_platform@2x.png", this->mSpriteBatch4);
        Entity* shadow = Entity::create("robo_menu_machine_platform_char_shadow@2x.png", this->mSpriteBatch4);
        
        platform->create()->setCenterPosition(Options::CAMERA_CENTER_X + platform->getWidth() * i, Utils::coord(250));
        platform->setZOrder(1);
        
        shadow->create()->setCenterPosition(platform->getCenterX(), platform->getCenterY() + Utils::coord(15));
        shadow->setZOrder(2);

        Entity* test = Entity::create("robo_test@2x.png", this->mSpriteBatch4);
            
        test->create()->setCenterPosition(Options::CAMERA_CENTER_X + platform->getWidth() * i, Utils::coord(200) + test->getHeight() / 2);
        test->setZOrder(3);
    }

    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackgroundDecoration->create()->setCenterPosition(Options::CAMERA_CENTER_X, this->mBackgroundDecoration->getHeight() / 2);

    this->mResourcesBackgrounds[0]->create()->setCenterPosition(Options::CAMERA_CENTER_X - Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(60));
    this->mResourcesBackgrounds[1]->create()->setCenterPosition(Options::CAMERA_CENTER_X + Utils::coord(170), Options::CAMERA_HEIGHT - Utils::coord(60));

    this->mResourcesIcons[0]->create()->setCenterPosition(this->mResourcesBackgrounds[0]->getCenterX() - this->mResourcesBackgrounds[0]->getWidth() / 2, this->mResourcesBackgrounds[0]->getCenterY());
    this->mResourcesIcons[1]->create()->setCenterPosition(this->mResourcesBackgrounds[1]->getCenterX() - this->mResourcesBackgrounds[1]->getWidth() / 2, this->mResourcesBackgrounds[1]->getCenterY());
    
    this->mResourcesPluses[0]->create()->setCenterPosition(this->mResourcesBackgrounds[0]->getCenterX() + this->mResourcesBackgrounds[0]->getWidth() / 2, this->mResourcesBackgrounds[0]->getCenterY());
    this->mResourcesPluses[1]->create()->setCenterPosition(this->mResourcesBackgrounds[1]->getCenterX() + this->mResourcesBackgrounds[1]->getWidth() / 2, this->mResourcesBackgrounds[1]->getCenterY());
    
    this->mMoveButtons[0]->create()->setCenterPosition(this->mMoveButtons[0]->getWidth() / 2, Utils::coord(390));
    this->mMoveButtons[1]->create()->setCenterPosition(Options::CAMERA_WIDTH - this->mMoveButtons[1]->getWidth() / 2, Utils::coord(390));
    
    this->mMoveButtons[1]->setScaleX(-1);

    this->mPlayButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(80), Utils::coord(80));
    this->mBackButton->create()->setCenterPosition(Utils::coord(80), Utils::coord(80));
    
    this->mBaloon->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(100));
    this->mBaloon->setCascadeOpacityEnabled(true);
    
    this->mBaloonResourcesIcons[0]->create()->setCenterPosition(this->mBaloon->getWidth() / 2 - Utils::coord(150), this->mBaloon->getHeight() / 2 - Utils::coord(30));
    this->mBaloonResourcesIcons[1]->create()->setCenterPosition(this->mBaloon->getWidth() / 2 + Utils::coord(100), this->mBaloon->getHeight() / 2 - Utils::coord(30));
    this->mBaloonResourcesIcons[0]->setScale(0.5);
    this->mBaloonResourcesIcons[1]->setScale(0.5);
    
    this->mBaloonText = Text::create(Options::TEXT_GARAGE_UNLOCK_CHARACTER_BALOON, CCSize(this->mBaloon->getWidth() - Utils::coord(50), 0), this->mBaloon);
    this->mBaloonTextGold = Text::create((Textes) {"x500 +", Options::FONT, 42, -1}, this->mBaloon);
    this->mBaloonTextSilver = Text::create((Textes) {"x25", Options::FONT, 42, -1}, this->mBaloon);
    
    this->mBaloonText->setCenterPosition(this->mBaloon->getWidth() / 2, this->mBaloon->getHeight() / 2 + Utils::coord(100));
    this->mBaloonTextGold->setCenterPosition(this->mBaloon->getWidth() / 2 - Utils::coord(25), this->mBaloon->getHeight() / 2 - Utils::coord(25));
    this->mBaloonTextSilver->setCenterPosition(this->mBaloon->getWidth() / 2 + Utils::coord(180), this->mBaloon->getHeight() / 2 - Utils::coord(25));
    
    this->mBaloonText->setColor(ccc3(50.0, 32.0, 2.0));
    this->mBaloonTextGold->setColor(ccc3(50.0, 32.0, 2.0));
    this->mBaloonTextSilver->setColor(ccc3(50.0, 32.0, 2.0));
    
    this->mBaloonText->disableShadow();
    this->mBaloonTextGold->disableShadow();
    this->mBaloonTextSilver->disableShadow();

    this->mGetGoldPopup = GetGold::create(this);
    this->mGetSilverPopup = GetSilver::create(this);
    this->mProperties = Properties::create(this);
    
    this->mProperties->setZOrder(1);
    this->mBaloon->setZOrder(2);
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

void Garage::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_GARAGE_PLAY:
            {
                AppDelegate::screens->set(SCREEN_LOADER);
            }
            break;
            case Options::BUTTONS_ID_BACK:
            {
                this->keyBackClicked(false);
            }
            break;
            case Options::BUTTONS_ID_GARAGE_MOVE_LEFT:
            {
                if(this->mSpriteBatch4->numberOfRunningActions() > 0) return;

                this->mSpriteBatch4->runAction(
                                               CCSequence::create(
                                                                  CCMoveTo::create(0.5, ccp(this->mSpriteBatch4->getPosition().x + Utils::coord(678), this->mSpriteBatch4->getPosition().y)),
                                                                  CCCallFunc::create(this, callfunc_selector(Garage::updateMoveButtons)),
                                                                  NULL));
                
                this->mCurrentFrame--;
                
                this->onCharacterListStartView();
            }
            break;
            case Options::BUTTONS_ID_GARAGE_MOVE_RIGHT:
            {
                if(this->mSpriteBatch4->numberOfRunningActions() > 0) return;

                this->mSpriteBatch4->runAction(
                                               CCSequence::create(
                                                                  CCMoveTo::create(0.5, ccp(this->mSpriteBatch4->getPosition().x - Utils::coord(678), this->mSpriteBatch4->getPosition().y)),
                                                                  CCCallFunc::create(this, callfunc_selector(Garage::updateMoveButtons)),
                                                                  NULL));
                
                this->mCurrentFrame++;
                
                this->onCharacterListStartView();
            }
            break;
            case Options::BUTTONS_ID_GARAGE_GET_GOLD:
            {
                this->mGetSilverPopup->show();
            }
            break;
            case Options::BUTTONS_ID_GARAGE_GET_SILVER:
            {
                this->mGetGoldPopup->show();
            }
            break;
            case Options::BUTTONS_ID_GARAGE_SELECT:
            {
                
            }
            break;
        }
    }
}

void Garage::updateMoveButtons()
{
    this->onCharacterListEndView();

    if(this->mCurrentFrame <= 0)
    {
        this->mMoveButtons[0]->setRegisterAsTouchable(false);
        this->mMoveButtons[1]->setRegisterAsTouchable(true);

        this->mMoveButtons[0]->setCurrentFrameIndex(0);
        this->mMoveButtons[1]->setCurrentFrameIndex(1);
    }
    else if(this->mCurrentFrame > 0 && this->mCurrentFrame < 5) // TODO: Robots count here!
    {
        this->mMoveButtons[0]->setRegisterAsTouchable(true);
        this->mMoveButtons[1]->setRegisterAsTouchable(true);
        
        this->mMoveButtons[0]->setCurrentFrameIndex(1);
        this->mMoveButtons[1]->setCurrentFrameIndex(1);
    }
    else
    {
        this->mMoveButtons[0]->setRegisterAsTouchable(true);
        this->mMoveButtons[1]->setRegisterAsTouchable(false);
        
        this->mMoveButtons[0]->setCurrentFrameIndex(1);
        this->mMoveButtons[1]->setCurrentFrameIndex(0);
    }
}

void Garage::onCharacterListStartView()
{
    this->hideBaloon();

    switch(this->mCurrentFrame)
    {
        default:
        this->mSelectCharacter->runAction(CCMoveTo::create(0.25, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Options::CAMERA_HEIGHT)));
        break;
    }
}

void Garage::onCharacterListEndView()
{
    //if(this->mSpriteBatch4->numberOfRunningActions() > 0) return;

    switch(this->mCurrentFrame)
    {
        case 0:
        this->mSelectCharacter->runAction(CCMoveTo::create(0.25, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Options::CAMERA_HEIGHT)));
        break;
        case 1:
        this->mSelectCharacter->setText(Options::TEXT_GARAGE_SELECT_CHARACTER);
        break;
        case 2:
        this->mSelectCharacter->setText(Options::TEXT_GARAGE_UNLOCK_CHARACTER);
        this->showBaloon();
        break;
        case 3:
        this->mSelectCharacter->setText(Options::TEXT_GARAGE_UNLOCK_CHARACTER);
        this->showBaloon();
        break;
        case 4:
        this->mSelectCharacter->setText(Options::TEXT_GARAGE_UNLOCK_CHARACTER);
        this->showBaloon();
        break;
        case 5:
        this->mSelectCharacter->setText(Options::TEXT_GARAGE_UNLOCK_CHARACTER);
        this->showBaloon();
        break;
    }
    
    switch(this->mCurrentFrame)
    {
        case 0:
        break;
        case 1:
        default:
        this->mSelectCharacter->runAction(CCMoveTo::create(0.25, ccp(Options::CAMERA_CENTER_X, Utils::coord(150))));
        break;
    }
}

void Garage::showBaloon()
{
    this->mBaloon->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200));
    this->mBaloon->runAction(CCMoveTo::create(0.3, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(100))));
    this->mBaloon->runAction(CCFadeIn::create(0.3));
}

void Garage::hideBaloon()
{
    if(this->mBaloon->getOpacity() <= 0) return;

    this->mBaloon->runAction(CCMoveTo::create(0.3, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200))));
    this->mBaloon->runAction(CCFadeOut::create(0.3));
}

// ===========================================================
// Override Methods
// ===========================================================

void Garage::onEnter()
{
    Screen::onEnter();
    
    this->mCurrentFrame = 0;
    
    this->mSpriteBatch4->setPosition(ccp(0, 0));
    
    this->updateMoveButtons();
    
    this->mBaloon->setOpacity(0);
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

void Garage::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
    
    AppDelegate::screens->set(Screen::SCREEN_MENU);
}

#endif