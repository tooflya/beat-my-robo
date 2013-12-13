#import "AppController.h"
#import "AppDelegate.h"

static AppDelegate s_sharedApplication;

@implementation AppController

	@synthesize window, glView;

	-(void) applicationDidFinishLaunching:(NSNotification *)aNotification
	{
		NSRect rect = NSMakeRect(0, 0, 720, 1280);
		window = [[NSWindow alloc] initWithContentRect:rect
			styleMask:( NSClosableWindowMask | NSTitledWindowMask )
			backing:NSBackingStoreBuffered
			defer:YES];
		
		glView = [[EAGLView alloc] initWithFrame:rect];

		[window becomeFirstResponder];
		[window setContentView:glView];
		[window setTitle:@"Beat My Robo by Tooflya Inc."];
		[window makeKeyAndOrderFront:self];
		[window setAcceptsMouseMovedEvents:YES];

		cocos2d::CCApplication::sharedApplication()->run();
	}

	-(BOOL) applicationShouldTerminateAfterLastWindowClosed:(NSApplication*)theApplication
	{
		return YES;
	}

	-(void) dealloc
	{
		cocos2d::CCDirector::sharedDirector()->end();
		[super dealloc];
	}

#pragma mark -
#pragma mark IB Actions

	-(IBAction) toggleFullScreen:(id)sender
	{
		EAGLView* pView = [EAGLView sharedEGLView];
		[pView setFullScreen:!pView.isFullScreen];
	}

	-(IBAction) exitFullScreen:(id)sender
	{
		[[EAGLView sharedEGLView] setFullScreen:NO];
	}

@end
