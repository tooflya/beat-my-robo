#ifndef CONST_POPUP
#define CONST_POPUP

#include "Popup.h"

// ===========================================================
// Inner Classes
// ===========================================================

class Background : public CCNodeRGBA
{
    public:
        Background()
        {
            this->setOpacity(0);
        }

        static Background* create()
        {
            Background* background = new Background();
            background->autorelease();

            return background;
        }

        void draw()
        {
            if(this->getOpacity() <= 0) return;

			#if CC_TARGET_PLATFORM != CC_PLATFORM_WINRT
            glLineWidth(1);
			#endif

            CCPoint filledVertices[] = { ccp(0,0), ccp(0,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH,Options::CAMERA_HEIGHT), ccp(Options::CAMERA_WIDTH, 0)};
            ccDrawSolidPoly(filledVertices, 4, ccc4f(0.0f, 0.0f, 0, this->getOpacity() / 255.0) );
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

Popup::~Popup()
{
    this->removeAllChildrenWithCleanup(true);
}

Popup::Popup(CCNode* pParent) :
	mParent(0),
	mSquare(0),
	mBackground(0),
	mCloseButton(0),
	mShowed(0)
	{
        this->mSpriteBatch = SpriteBatch::create("TextureAtlas6", this, false);

		this->init();
    
		this->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y));
    
		this->mParent = pParent;
    
		this->mBackground = Entity::create("robo_menu_popup@2x.png", this->mSpriteBatch);
		this->mSquare = Background::create();
        
        this->mCloseButton = Button::create("robo_menu_popup_btn_close@2x.png", 2, 1, this->mSpriteBatch, 0, this);
    
		this->mBackground->create()->setCenterPosition(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y);
        this->mCloseButton->create()->setCenterPosition(Options::CAMERA_CENTER_X + this->mBackground->getWidth() / 2 - Utils::coord(100), Options::CAMERA_CENTER_Y + this->mBackground->getHeight() / 2 + this->mCloseButton->getHeight() / 2);
    
		this->mShowed = false;
    
		this->ignoreAnchorPointForPosition(false);
		this->setAnchorPoint(ccp(0.5, 0.5));

		this->mParent->addChild(this->mSquare, 500);
        
        this->setPosition(ccp(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT * 2));
	}

// ===========================================================
// Methods
// ===========================================================

void Popup::show()
{
    if(this->mShowed) return;
    
    this->mParent->addChild(this, 1000);
    
    this->mShowed = true;
    
    this->mSquare->runAction(CCFadeTo::create(0.2, 200));
    this->runAction(
                    CCSequence::create(
                                       CCMoveTo::create(0.3, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200))),
                                       CCMoveTo::create(0.1, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y)),
                                       CCCallFunc::create(this, callfunc_selector(Popup::onShow)), NULL));
}

void Popup::hide()
{
    if(!this->mShowed) return;
    
    this->mSquare->runAction(CCFadeTo::create(0.2, 0));
    this->runAction(
                    CCSequence::create(
                                       CCMoveTo::create(0.1, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_CENTER_Y + Utils::coord(200))),
                                       CCMoveTo::create(0.1, ccp(Options::CAMERA_CENTER_X, Options::CAMERA_HEIGHT * 2)),
                                       CCCallFunc::create(this, callfunc_selector(Popup::onHide)), NULL));
}

bool Popup::isShowed()
{
    return this->mShowed;
}

void Popup::onShow()
{
}

void Popup::onHide()
{
    this->removeFromParentAndCleanup(false);

    this->mShowed = false;
}

void Popup::onTouchButtonsCallback(const int pAction, const int pID)
{
}

// ===========================================================
// Override Methods
// ===========================================================

void Popup::update(float pDeltaTime)
{
    CCLayer::update(pDeltaTime);
}

void Popup::onEnter()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addTargetedDelegate(this, 0, true);
    
    this->scheduleUpdate();
    
    CCLayer::onEnter();
}

void Popup::onExit()
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->removeDelegate(this);
    
    this->stopAllActions();
    this->unscheduleUpdate();
    this->unscheduleAllSelectors();
    
    CCLayer::onExit();
}

bool Popup::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
    return this->mShowed;
}

#endif