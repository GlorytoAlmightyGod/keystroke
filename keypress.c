/* 
 * Compile using gcc -o key keypress.c -lX11 -lXtst
 * run ./key 1(or whatever)
 * then see the key pressed happily.
*/
#include <stdio.h>

#include <X11/Xlib.h>
#include <X11/extensions/XTest.h>

#define Up 0xff52
#define Down 0xff54
#define Left 0xff51
#define Right 0xff53
#define Return 0xff0d
#define BackSpace 0xff08

int main(int argc, char *argv[])
{
	if(argc<2)	// quite clear!
	{
		printf("Missing arguements");
	}
	else
	{
		unsigned int key,keycode,n = atoi(argv[1]);		// getting the provided arguement and converting it to integer

		switch(n)	// assign keycodes
		{
			case 1:
					key = Up;
					break;
			case 2:
					key = Down;
					break;
			case 3:
					key = Left;
					break;
			case 4:
					key = Right;
					break;
			case 5:
					key = Return;
					break;
			case 6:
					key = BackSpace;
					break;
			default:
					break;
		}
		
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
