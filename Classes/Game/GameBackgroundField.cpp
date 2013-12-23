#ifndef CONST_GAMEBACKGROUNDFIELD
#define CONST_GAMEBACKGROUNDFIELD

#include "GameBackgroundField.h"

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

GameBackgroundField::~GameBackgroundField()
{
    CC_SAFE_RELEASE(this->mElements);
    CC_SAFE_RELEASE(this->mElementPics);
    CC_SAFE_RELEASE(this->mElementParticles);
}

GameBackgroundField::GameBackgroundField(CCNode* pParent) :
GameBackgroundColorDelegate(pParent)
{
    this->initialization();

    this->mSpriteBatch1 = SpriteBatch::create("TextureAtlas7", this, false);
    
    this->mElements = EntityManager::create(100, Element::create(this), this->mSpriteBatch1);
    this->mElementPics = EntityManager::create(10, Entity::create("game_action_ico_wh@2x.png", 2, 5), this->mSpriteBatch1);
    this->mElementParticles = EntityManager::create(200, ElementParticle::create(), this->mSpriteBatch1, 100);
    
    Matrix = GameBackgroundMatrix::create(this, this->mElements);
    
    /** Temp Solutions */
    
    this->generateMatrix();
    this->generateField();
    
    this->setColor(ccBLACK);
    this->setOpacity(128);
}

GameBackgroundField* GameBackgroundField::create(CCNode* pParent)
{
    GameBackgroundField* properties = new GameBackgroundField(pParent);
    properties->autorelease();
    properties->retain();

    return properties;
}

// ===========================================================
// Methods
// ===========================================================

void GameBackgroundField::initialization()
{
    GameBackgroundColorDelegate::initialization();

    this->setContentSize(CCSize(this->mDesignedSize - this->mDesigneddoublePaddingSize, this->mDesignedSize - this->mDesigneddoublePaddingSize));
    this->setCenterPosition(Options::CAMERA_CENTER_X, this->getHeight() / 2 + (Options::CAMERA_WIDTH - this->getWidth()) / 2 + this->mDesignedPaddingSize);
    
    this->setScale(Options::CAMERA_WIDTH / (this->getWidth() + this->mDesigneddoublePaddingSize));
}

// ===========================================================
// Matrix support functions
// ===========================================================

// ===========================================================
// Matrix and fields generator
// ===========================================================

void GameBackgroundField::generateMatrix()
{
}

void GameBackgroundField::generateField()
{
    float size = Utils::coord(110);
    float padding = Utils::coord(6);

    for(int i = 0; i < Matrix->countInnderY; i++)
    {
        float y = size / 2 + (size * i + padding * (i + 1));

        for(int j = 0; j < Matrix->countX; j++)
        {
            float x = size / 2 + (size * j + padding * (j + 1));

            Element* element = static_cast<Element*>(this->mElements->create());
            
            element->setCenterPosition(x, y);

            element->setCurrentFrameIndex(Utils::random(0, 4));
            
            try
            {
                while(!this->approvePosition(element->getCurrentFrameIndex(), j, i, true, 0, 0))
                {
                    element->setCurrentFrameIndex(Utils::random(0, 4));
                }
            }
            catch(int e)
            {
                
            }
            
            Matrix->set(j, i, element);
            
            element->onMatrixPosition(); // TODO: Only at first create!
        }
    }
}

// ===========================================================
// Here we need to find safety position of new elements
// ===========================================================

bool GameBackgroundField::approvePosition(int pFrameIndex, int pPositionX, int pPositionY, bool pIsRecursive, int pPastPosX, int pPastPosY) // TODO: REFACTORING!!!
{
    if(pIsRecursive)
    {
        if(pPositionX > 0) // влево
        {
            Element* neighbor = Matrix->get(pPositionX - 1, pPositionY);
            
            if(neighbor != NULL)
            {
                if(neighbor->getCurrentFrameIndex() == pFrameIndex)
                {
                    if(!this->approvePosition(pFrameIndex, pPositionX - 1, pPositionY, false, pPositionX, pPositionY)) return false;
                }
            }
        }
        
        if(pPositionX < Matrix->countX) // вправо
        {
            Element* neighbor = Matrix->get(pPositionX + 1, pPositionY);
            
            if(neighbor != NULL)
            {
                if(neighbor->getCurrentFrameIndex() == pFrameIndex)
                {
                    if(!this->approvePosition(pFrameIndex, pPositionX + 1, pPositionY, false, pPositionX, pPositionY)) return false;
                }
            }
        }
        
        if(pPositionY > 0) // вниз
        {
            Element* neighbor = Matrix->get(pPositionX, pPositionY - 1);
            
            if(neighbor != NULL)
            {
                if(neighbor->getCurrentFrameIndex() == pFrameIndex)
                {
                    if(!this->approvePosition(pFrameIndex, pPositionX, pPositionY - 1, false, pPositionX, pPositionY)) return false;
                }
            }
        }
        
        if(pPositionY < Matrix->countY-1) // вверх
        {
            Element* neighbor = Matrix->get(pPositionX, pPositionY + 1);

            if(neighbor != NULL)
            {
                if(neighbor->getCurrentFrameIndex() == pFrameIndex)
                {
                    if(!this->approvePosition(pFrameIndex, pPositionX, pPositionY + 1, false, pPositionX, pPositionY)) return false;
                }
            }
        }
        
        return true;
    }
    else
    {
        // просматриваем только соседей и возвращаем результат сразу
        
        Entity* neighbor;
        
        if(pPositionX > 0) // влево
        {
            if(pPositionX - 1 == pPastPosX) return true;
            neighbor = Matrix->get(pPositionX - 1, pPositionY);
            
            if(neighbor)
            if(neighbor->getCurrentFrameIndex() == pFrameIndex)
            {
                return false;
            }
        }
        
        if(pPositionX < Matrix->countX) // вправо
        {
            if(pPositionX + 1 == pPastPosX) return true;
            neighbor = Matrix->get(pPositionX + 1, pPositionY);
            
            if(neighbor)
            {
                if(neighbor->getCurrentFrameIndex() == pFrameIndex)
                {
                    return false;
                }
            }
        }
        
        if(pPositionY > 0) // вниз
        {
            if(pPositionY - 1 == pPastPosY) return true;
            neighbor = Matrix->get(pPositionX, pPositionY - 1);
            
            if(neighbor)
            if(neighbor->getCurrentFrameIndex() == pFrameIndex)
            {
                return false;
            }
        }
        
        if(pPositionY < Matrix->countY) // вверх
        {
            if(pPositionY+1 == pPastPosY) return true;
            neighbor = Matrix->get(pPositionX, pPositionY + 1);
            
            if(neighbor)
            if(neighbor->getCurrentFrameIndex() == pFrameIndex)
            {
                return false;
            }
        }
        
        return true;
    }

    return true;
}

// ===========================================================
// Match-3 finder
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void GameBackgroundField::update(float pDeltaTime)
{
    CCLayerColor::update(pDeltaTime);
}

void GameBackgroundField::visit()
{
    kmGLPushMatrix();
    glEnable(GL_SCISSOR_TEST);
    
    CCEGLView::sharedOpenGLView()->setScissorInPoints(
                                                      0,
                                                      this->getCenterPosition().y - (this->getHeight() / 2) * this->getScaleX(),
                                                      Options::CAMERA_WIDTH,
                                                      this->getCenterPosition().y + (this->getHeight() / 2) * this->getScaleX() + GameBackground::BACKGROUND_POSITION[BATTLE_GRAPHICS_ID].y);
    
    CCLayerColor::visit();
    
    glDisable(GL_SCISSOR_TEST);
    kmGLPopMatrix();
}

#endif