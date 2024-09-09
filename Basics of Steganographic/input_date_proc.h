#pragma once
#include "macros.h"
#include "file_proc.h"
#include "TUI.h"

class InputProc
{
public:
	void getText(int mode);
	int getKey();
	int getFilePath(char mod);
	int getLongtoKey(Key& encryptionKey);
	int packingDegree();
	File mutableFile;
	File readableFile;
	File encryptionFile;
	FileOperations procFile;
	Key encryptionKey;
	TUIBase TUI;
};

