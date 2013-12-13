#ifndef CONST_ENTITYMANAGER_H
#define CONST_ENTITYMANAGER_H

#include "cocos2d.h"

#include "Entity.h"

using namespace cocos2d;

class EntityManager : public CCArray
{
	protected:
		int mLastElementNumber;
		int mCapacity;
    int mZOrder;
    
    EntityManager(int pCreateCount, Entity* pEntity);
    EntityManager(int pCreateCount, Entity* pEntity, CCNode* pScreen);
    EntityManager(int pCreateCount, int pMaxCount, Entity* pEntity, CCNode* pScreen);
    EntityManager(int pCreateCount, Entity* pEntity, CCNode* pScreen, int pZOrder);
    EntityManager();

    public:
        CCNode* mParent;

		void init(int pCreateCount, int pMaxCount, Entity* pEntity, CCNode* pScreen, int pZOrder);
		
        ~EntityManager();
    
        static EntityManager* create(int pCreateCount, Entity* pEntity);
        static EntityManager* create(int pCreateCount, Entity* pEntity, CCNode* pScreen);
        static EntityManager* create(int pCreateCount, int pMaxCount, Entity* pEntity, CCNode* pScreen);
        static EntityManager* create(int pCreateCount, Entity* pEntity, CCNode* pScreen, int pZOrder);
        static EntityManager* create(int a);

		Entity* create();
		void destroy(int pIndex);

		void setParent(CCNode* pScreen);
		void setParent(CCNode* pScreen, int pZOrder);

		void changeTexture(Texture* pTexture);
		
		int getCount();
		int getCapacity();

		void clear();

		void update(float pDeltaTime);
    
        void release();
    
        void setOpacity(GLubyte opacity);
    
        CCNode* getParent();
    
        void resumeSchedulerAndActions();
        void pauseSchedulerAndActions();
};

#endif