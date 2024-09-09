#pragma once
#include "macros.h"

class File
{
public: 
	char path[MAXIMUM_FILE_PATH_LENGTH];
	wchar_t path_wchar[MAXIMUM_FILE_PATH_LENGTH];
	File() {}
	File(const char* filePath, const wchar_t* filePathW)
	{
		strncpy(path, filePath, MAXIMUM_FILE_PATH_LENGTH);
		wcsncpy(path_wchar, filePathW, MAXIMUM_FILE_PATH_LENGTH);
		path_wchar[MAXIMUM_FILE_PATH_LENGTH - 1] = L'\0';
	}
};

class Key
{
public:
	char key[KEY_LENGTH];
	char packing_degree_array[LINE_LENGTH_FOR_COMPRESSION_RATE];
	int packing_degree;
};
class FileOperations
{
public:
	int copyFile(File& mutableFile, File& readableFile);
	void PathCharWchar(File& mutableFile, File& readableFile);
	int checkFileSizes(File& mutableFile, File& readableFile, Key& encryptionKey);
	int chekFileType(char mod, File& mutableFile, File& readableFile, File& encryptionFile, Key& encryptionKey);
};