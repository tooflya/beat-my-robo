#ifndef CONST_SPINE
#define CONST_SPINE

#include "Spine.h"

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

Spine::~Spine()
{
    
}

Spine::Spine(const char* pFileName, CCNode* pParent) :
CCSkeletonAnimation(ccsf("%s.json", pFileName), ccsf("%s.atlas", pFileName))
{
	this->setAnimationListener(this, animationStateEvent_selector(Spine::animationStateEvent));

    this->debugBones = false;

    if(pParent)
    {
        pParent->addChild(this);
    }
}

Spine* Spine::create(const char* pFileName, CCNode* pParent)
{
    Spine* spine = new Spine(pFileName, pParent);
    spine->autorelease();
    
    return spine;
}

// ===========================================================
// Methods
// ===========================================================

void Spine::animationStateEvent(CCSkeletonAnimation* node, int trackIndex, spEventType type, spEvent* event, int loopCount)
{
	spTrackEntry* entry = spAnimationState_getCurrent(node->state, trackIndex);

	const char* animationName = (entry && entry->animation) ? entry->animation->name : 0;

	switch(type)
    {
        case ANIMATION_START:
            CCLog("%d start: %s", trackIndex, animationName);
        break;
        case ANIMATION_END:
            CCLog("%d end: %s", trackIndex, animationName);
        break;
        case ANIMATION_COMPLETE:
            CCLog("%d complete: %s, %d", trackIndex, animationName, loopCount);
        break;
        case ANIMATION_EVENT:
            CCLog("%d event: %s, %s: %d, %f, %s", trackIndex, animationName, event->data->name, event->intValue, event->floatValue, event->stringValue);
        break;
	}

	fflush(stdout);
}

void Spine::setCenterPosition(float pCenterX, float pCenterY)
{
    this->setPosition(ccp(pCenterX, pCenterY));
}

float Spine::getCenterX()
{
    return this->getPosition().x;
}

float Spine::getCenterY()
{
    return this->getPosition().y;
}

// ===========================================================
// Override Methods
// ===========================================================

#endif