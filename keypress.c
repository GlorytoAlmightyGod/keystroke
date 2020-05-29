/* 
 * Compile using gcc -o key keypress.c -lX11 -lXtst
 * run ./key 1(or whatever)
 * then see the key pressed happily.
*/
#include <stdio.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>

#define up 0xff52
#define down 0xff54
#define left 0xff51
#define right 0xff53
#define enter 0xff0d
#define backspace 0xff08

int main(int argc, char *argv[])
{
	if(argc<2)	// quite clear!
	{printf("Missing arguements");}
	else
	{
		unsigned int key,keycode;
		// Comparing the given argument with our defined commands & assigning respective keycodes.
		if(!strcmp(argv[1],"up"))
		{key = up;}
		else if(!strcmp(argv[1],"down"))
		{key = down;}
		else if(!strcmp(argv[1],"left"))
		{key = left;}
		else if(!strcmp(argv[1],"right"))
		{key = right;}
		else if(!strcmp(argv[1],"enter"))
		{key = enter;}
		else if(!strcmp(argv[1],"backspace"))
		{key = backspace;}
		
		Display *display;
		display = XOpenDisplay(NULL);				// startup
		
		keycode = XKeysymToKeycode(display, key);
		XTestFakeKeyEvent(display, keycode, 1, 0);	// hit the key
		XTestFakeKeyEvent(display, keycode, 0, 0);	// release the key	
		
		XFlush(display);							// cleanup
		XCloseDisplay(display);
	}
	return 1;
}
