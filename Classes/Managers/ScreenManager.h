#ifndef CONST_SCREENMANAGER_H
#define CONST_SCREENMANAGER_H

#include "Options.h"

class Screen;

class ScreenManager : CCObject
{
	protected:
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
    
        ScreenManager();

		// ===========================================================
		// Methods
		// ===========================================================

		// ===========================================================
		// Override Methods
		// ===========================================================

	private:
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

		// ===========================================================
		// Methods
		// ===========================================================
		
		// ===========================================================
		// Override Methods
		// ===========================================================

	public:
		// ===========================================================
		// Inner Classes
		// ===========================================================

		// ===========================================================
		// Constants
		// ===========================================================

		// ===========================================================
		// Fields
		// ===========================================================

		Screen* mScreens[4];

		int mCurrentScreenIndex;

		// ===========================================================
		// Constructors
		// ===========================================================
    
        static ScreenManager* create();

		// ===========================================================
		// Methods
		// ===========================================================

		void generate();
		
		void set(int pIndex);
		
		// ===========================================================
		// Override Methods
		// ===========================================================
};

#endif