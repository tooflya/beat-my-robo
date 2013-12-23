#ifndef CONST_GAMEBACKGROUNDDELEGATE_H
#define CONST_GAMEBACKGROUNDDELEGATE_H

#include "Screen.h"

class GameBackgroundDelegate
{
    protected:
    GameBackgroundDelegate();

    float mDesignedSize;
    float mDesignedPaddingSize;
    float mDesigneddoublePaddingSize;
    
    public:
    static int BATTLE_GRAPHICS_ID;
};

class GameBackgroundColorDelegate : public CCLayerColor, public GameBackgroundDelegate
{
    protected:
    GameBackgroundColorDelegate(CCNode* pParent);

    virtual void initialization();
    
    virtual void setCenterPosition(float pCenterX, float pCenterY);
    
    virtual CCPoint getCenterPosition();
    
    virtual float getWidth();
    virtual float getHeight();
};

class GameBackgroundGradientDelegate : public CCLayerGradient, public GameBackgroundDelegate
{
    protected:
    GameBackgroundGradientDelegate(CCNode* pParent);

    virtual void initialization();
    
    virtual void setCenterPosition(float pCenterX, float pCenterY);
    
    virtual float getWidth();
    virtual float getHeight();
};

#endif