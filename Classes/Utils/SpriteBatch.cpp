#ifndef CONST_SPRITEBATCH
#define CONST_SPRITEBATCH

#include "SpriteBatch.h"

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

SpriteBatch::~SpriteBatch()
{
    this->removeAllChildrenWithCleanup(true);
}

SpriteBatch::SpriteBatch()
{
}

SpriteBatch* SpriteBatch::create(const char* pTextureAtlas, CCNode* pParent, bool pFastRendering)
{
	#if CC_PRELOAD_LEVEL <= CC_PRELOAD_NOTHING
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(ccsf("%s%s", pTextureAtlas, ".plist"));
	#endif

    SpriteBatch* spriteBatch = new SpriteBatch();
    spriteBatch->initWithFile(ccsf("%s%s", pTextureAtlas, Options::TEXTURES_EXTENSION), 10);
    spriteBatch->autorelease();
    
    if(pFastRendering)
    {
		ccBlendFunc bf = {GL_ONE, GL_ZERO};
		spriteBatch->setBlendFunc(bf);
    }
    
    pParent->addChild(spriteBatch);
    
    return spriteBatch;
}

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

// ===========================================================
// Constructors
// ===========================================================

// ===========================================================
// Getters
// ===========================================================

// ===========================================================
// Setters
// ===========================================================

// ===========================================================
// Methods
// ===========================================================

// ===========================================================
// Override Methods
// ===========================================================

void SpriteBatch::draw()
{
    CCSpriteBatchNode::draw();
}

void SpriteBatch::visit()
{
    CCSpriteBatchNode::visit();
}

#endif