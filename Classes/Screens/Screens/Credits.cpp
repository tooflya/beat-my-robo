#ifndef CONST_CREDITSSCREEN
#define CONST_CREDITSSCREEN

#include "Credits.h"

// ===========================================================
// Inner Classes
// ===========================================================

class ScrollLayer : public CCLayer
{
    public:
    float mHeight;
    float mMaxHeight;
    float mListInitialCenter;
    float mStartCoordinate;
    float mStartPositionCoordinate;
    float mLastDistance;
    float mSpeed;
    float ml;
    
    long mLastMoveTime;

    bool mPostUpdate;
    
    ScrollLayer()
    {
        this->init();
        
        this->mHeight = Utils::coord(1000);
        this->mMaxHeight = Utils::coord(1000);
    }
    
    static ScrollLayer* create(CCNode* pParent)
    {
        ScrollLayer* layer = new ScrollLayer();
        layer->autorelease();
        
        pParent->addChild(layer);
        
        return layer;
    }
    
    void update(float pDeltaTime)
    {
        CCLayer::update(pDeltaTime);
        
        if(this->mPostUpdate)
        {
            float x = this->getPosition().x;
            float y = this->getPosition().y;
            
            this->setPosition(ccp(x, y - this->mSpeed));
            
            this->mSpeed -= this->mLastDistance > 0 ? 0.5 : -0.5;
            
            if(y < 0)
            {
                this->runAction(CCMoveTo::create(0.3, ccp(x, 0)));
                
                this->mPostUpdate = false;
            }
            else if(y > this->mMaxHeight)
            {
                this->runAction(CCMoveTo::create(0.3, ccp(x, this->mMaxHeight)));
                
                this->mPostUpdate = false;
            }
            
            if(this->mLastDistance > 0 ? this->mSpeed <= 0.0 : this->mSpeed >= 0.0)
            {
                this->mPostUpdate = false;
            }
        }
    }
    
    bool ccTouchBegan(CCTouch* touch, CCEvent* event)
    {
        this->stopAllActions();
        
        this->mPostUpdate = false;
        this->mStartCoordinate = touch->getLocation().y;
        this->mStartPositionCoordinate = this->getPosition().y;
        
        this->ml = touch->getLocation().x;
        
        return this->containsTouchLocation(touch);
    }
    
    void ccTouchMoved(CCTouch* touch, CCEvent* event)
    {
        if(this->containsTouchLocation(touch))
        {
            float x, y;
            
            x = this->getPosition().x;
            y = this->mStartPositionCoordinate + touch->getLocation().y - this->mStartCoordinate;
            
            this->setPosition(ccp(x, y));
            
            if(abs(this->ml - touch->getLocation().x) >= Utils::coord(10))
            {
                this->ml = touch->getLocation().x;
                
                this->mLastMoveTime = Utils::millisecondNow();
            }
        }
    }
    
    void ccTouchEnded(CCTouch* touch, CCEvent* event)
    {
        float x = this->getPosition().x;
        float y = this->getPosition().y;
        
        bool kWillPostUpdate = true;
        
        if(y < 0)
        {
            this->runAction(CCMoveTo::create(0.3, ccp(x, 0)));
            
            kWillPostUpdate = false;
        }
        else if(y > this->mMaxHeight)
        {
            this->runAction(CCMoveTo::create(0.3, ccp(x, this->mMaxHeight)));
            
            kWillPostUpdate = false;
        }
        
        this->mLastDistance = this->mStartPositionCoordinate - y;
        
        this->mPostUpdate = kWillPostUpdate;

        if(Utils::millisecondNow() - this->mLastMoveTime >= 100)
        {
            this->mPostUpdate = false;
        }
        
        this->mSpeed = this->mLastDistance / 10.0;
    }
    
    bool containsTouchLocation(CCTouch* touch)
    {
        float x = touch->getLocation().x;
        float y = touch->getLocation().y;
        
        return x > Options::CAMERA_CENTER_X - Options::CAMERA_CENTER_X &&
        x < Options::CAMERA_CENTER_X + Options::CAMERA_CENTER_X && y < Options::CAMERA_CENTER_Y + this->mHeight / 2 && y > Options::CAMERA_CENTER_Y - this->mHeight / 2;
        
        
        return true;
    }
    
    void onEnter()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
        
        CCLayer::onEnter();
        
        this->scheduleUpdate();
        
        this->setPosition(ccp(this->getPosition().x, 0)); // TODO: Check it for horizontal list.
    }
    
    void onExit()
    {
        CCDirector* pDirector = CCDirector::sharedDirector();
        pDirector->getTouchDispatcher()->removeDelegate(this);
        
        CCLayer::onExit();
        
        this->unscheduleAllSelectors();
        
        this->mPostUpdate = false;
        this->stopAllActions();
    }
};

// ===========================================================
// Constants
// ===========================================================

// ===========================================================
// Fields
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

Credits::~Credits()
{
}

Credits::Credits()
{
    this->mList = ScrollLayer::create(this);
    
    this->mSpriteBatch1 = SpriteBatch::create("TextureAtlas1", this, true);
    this->mSpriteBatch2 = SpriteBatch::create("TextureAtlas2", this, false);
    this->mSpriteBatch3 = SpriteBatch::create("TextureAtlas3", this, false);
    this->mSpriteBatch4 = SpriteBatch::create("TextureAtlas5", this->mList, false);

    this->mSpriteBatch1->setZOrder(0);
    this->mSpriteBatch2->setZOrder(2);
    this->mSpriteBatch3->setZOrder(3);
    
    this->mList->setZOrder(1);
    
    this->mBackground = Entity::create("start_preloader_bg@2x.png", this->mSpriteBatch1);
    this->mBackgroundDecoration1 = Entity::create("info_menu_bg_deco3@2x.png", this->mSpriteBatch2);
    this->mBackgroundDecoration2 = Entity::create("info_menu_bg_deco3@2x.png", this->mSpriteBatch2);
    this->mGameName = Entity::create("start_preloader_name@2x.png", this->mSpriteBatch4);
    this->mCompanyName = Entity::create("info_menu_bg_logo@2x.png", this->mSpriteBatch4);
    
    this->mBackButton = Button::create("info_menu_btn_back@2x.png", 2, 1, this->mSpriteBatch3, Options::BUTTONS_ID_BACK, this);
    this->mPrivacyPolicyButton = Button::create("robo_menu_machine_platform_btn_select@2x.png", 1, 2, this->mSpriteBatch3, Options::BUTTONS_ID_CREDITS_PRIVACY_POLICY, this);
    
    this->mPrivacyPolicyButton->setText(Options::TEXT_CREDITS_PRIVACY_POLICY);
    this->mPrivacyPolicyButton->mText->setZOrder(10);
    
    this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
    this->mBackgroundDecoration1->create()->setCenterPosition(Options::CAMERA_CENTER_X, this->mBackgroundDecoration1->getHeight() / 2);
    this->mBackgroundDecoration2->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT - this->mBackgroundDecoration2->getHeight() / 2);
    this->mGameName->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200));
    this->mCompanyName->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(1200));
    
    this->mBackgroundDecoration2->setScale(-1);
    
    this->mBackButton->create()->setCenterPosition(Utils::coord(80), Utils::coord(80));
    this->mPrivacyPolicyButton->create()->setCenterPosition(Options::CAMERA_WIDTH - Utils::coord(220), Utils::coord(80));
    this->mPrivacyPolicyButton->setScale(1.3);
    
    this->mText[0] = Text::create(Options::TEXT_CREDITS_STRING_1, this->mList);
    this->mText[1] = Text::create(Options::TEXT_CREDITS_STRING_2, this->mList);
    this->mText[2] = Text::create(Options::TEXT_CREDITS_STRING_3, this->mList);
    this->mText[3] = Text::create(Options::TEXT_CREDITS_STRING_4, this->mList);
    this->mText[4] = Text::create(Options::TEXT_CREDITS_STRING_5, this->mList);
    this->mText[5] = Text::create(Options::TEXT_CREDITS_STRING_6, this->mList);
    this->mText[6] = Text::create(Options::TEXT_CREDITS_STRING_7, this->mList);
    this->mText[7] = Text::create(Options::TEXT_CREDITS_STRING_8, this->mList);
    this->mText[8] = Text::create(Options::TEXT_CREDITS_STRING_9, this->mList);
    this->mText[9] = Text::create(Options::TEXT_CREDITS_STRING_10, this->mList);
    this->mText[10] = Text::create(Options::TEXT_CREDITS_STRING_11, this->mList);
    this->mText[11] = Text::create(Options::TEXT_CREDITS_STRING_12, this->mList);
    this->mText[12] = Text::create(Options::TEXT_CREDITS_STRING_13, this->mList);
    
    this->mText[0]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(450) - Utils::coord(500));
    this->mText[1]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(350) - Utils::coord(500));
    this->mText[2]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(300) - Utils::coord(500));
    this->mText[3]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200) - Utils::coord(500));
    this->mText[4]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(100) - Utils::coord(500));
    this->mText[5]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(50) - Utils::coord(500));
    this->mText[6]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(50) - Utils::coord(500));
    this->mText[7]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(100) - Utils::coord(500));
    this->mText[8]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(200) - Utils::coord(500));
    this->mText[9]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(250) - Utils::coord(500));
    this->mText[10]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(300) - Utils::coord(500));
    this->mText[11]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(400) - Utils::coord(500));
    this->mText[12]->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y - Utils::coord(450) - Utils::coord(500));
    
    this->mText[0]->setColor(ccc3(255.0, 200.0, 0.0));
    this->mText[3]->setColor(ccc3(255.0, 200.0, 0.0));
    this->mText[4]->setColor(ccc3(255.0, 200.0, 0.0));
    this->mText[6]->setColor(ccc3(255.0, 200.0, 0.0));
    this->mText[8]->setColor(ccc3(255.0, 200.0, 0.0));
    this->mText[11]->setColor(ccc3(255.0, 200.0, 0.0));
}

Credits* Credits::create()
{
    Credits* screen = new Credits();
    screen->autorelease();
    screen->retain();
    
    return screen;
}

// ===========================================================
// Methods
// ===========================================================

void Credits::onTouchButtonsCallback(const int pAction, const int pID)
{
    switch(pAction)
    {
        case Options::BUTTONS_ACTION_ONTOUCH:
        switch(pID)
        {
            case Options::BUTTONS_ID_BACK:
            {
                this->keyBackClicked(false);
            }
            break;
        }
    }
}

// ===========================================================
// Override Methods
// ===========================================================

void Credits::onEnter()
{
    Screen::onEnter();
    
    this->mList->setPosition(ccp(0, 0));
    this->mList->runAction(CCMoveTo::create(10.0, ccp(this->mList->getPosition().x, this->mList->getPosition().y + Utils::coord(1000))));
    
    this->mText[1]->setString(ccsf(Options::TEXT_CREDITS_STRING_2.string, Options::VERSION));
    this->mText[2]->setString(ccsf(Options::TEXT_CREDITS_STRING_3.string, Options::BUILD));
}

void Credits::onExit()
{
    Screen::onExit();
}

void Credits::onEnterTransitionDidFinish()
{
    Screen::onEnterTransitionDidFinish();
}

void Credits::onExitTransitionDidStart()
{
    Screen::onExitTransitionDidStart();
}

void Credits::update(float pDeltaTime)
{
    Screen::update(pDeltaTime);
}

void Credits::keyBackClicked(bool pSound)
{
    Screen::keyBackClicked(pSound);
    
    AppDelegate::screens->set(Screen::SCREEN_MENU);
}

#endif