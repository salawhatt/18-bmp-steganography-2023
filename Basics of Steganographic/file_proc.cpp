#include "file_proc.h"

void FileOperations::PathCharWchar(File& mutableFile, File& readableFile)
{
    int array_element = 0;
    while (readableFile.path[array_element] != '\0')
    {
        readableFile.path_wchar[array_element] = readableFile.path[array_element];
        array_element++;
    }
    readableFile.path_wchar[array_element] = '\0';
    array_element = 0;
    while (mutableFile.path[array_element] != '\0')
    {
        mutableFile.path_wchar[array_element] = mutableFile.path[array_element];
        array_element++;
    }
    mutableFile.path_wchar[array_element] = '\0';
}

int FileOperations::checkFileSizes(File& encryptionFile, File& readableFile, Key& encryptionKey)
{

    struct stat size_file_1;
    struct stat size_file_2;
    stat(readableFile.path, &size_file_1);
    stat(encryptionFile.path, &size_file_2);
    unsigned long long int size_img = size_file_1.st_size;
    unsigned long long int size_cry = size_file_2.st_size;

    if (size_cry >= (size_img * encryptionKey.packing_degree / 8 - BMP_SYSTEM_PART))
    {
        return ERROR_FILE_TOO_LARGEE;
    }
    else
    {
        return NO_ERRORS;
    }
}

int FileOperations::copyFile(File& mutableFile, File& readableFile)
{
    int result = 0;
    PathCharWchar(mutableFile, readableFile);
    result = CopyFile(readableFile.path_wchar, mutableFile.path_wchar, 0);
    if (result == 0)
    {
        return 0;
    }
    else
    {
        return NO_ERRORS;
    }
}

int FileOperations::chekFileType(char mod, File& mutableFile, File& readableFile, File& encryptionFile, Key& encryptionKey)
{
    if (mod == TYPE_ENCRYPT_2 || mod == TYPE_DECRYPTION_1)
    {
        for (int array_element = 0; array_element < MAXIMUM_FILE_PATH_LENGTH; array_element++)
        {
            if (readableFile.path[array_element] == '\n')
            {
                readableFile.path[array_element] = '\0';
            }
        }
        char format_file[LINE_LENGTH_FOR_FORMAT_FILE] = { 0 };
        FILE* file = fopen(readableFile.path, "rb");
        if (file == 0)
        {
            return ERROR_FILE_NOT_OPEN;
        }
        else
        {
            fread(&format_file, sizeof(char), LINE_LENGTH_FOR_FORMAT_FILE, file);

            if (format_file[0] == 'B' && format_file[1] == 'M')
            {
                return NO_ERRORS;
            }
            else
            {
                return ERROR_FILE_NOT_BMP;
            }
        }
    }
    else if (mod == TYPE_ENCRYPT_3)
    {
        for (int array_element = 0; array_element < MAXIMUM_FILE_PATH_LENGTH; array_element++)
        {
            if (encryptionFile.path[array_element] == '\n')
            {
                encryptionFile.path[array_element] = '\0';
            }
        }
        FILE* file = fopen(encryptionFile.path, "rb");
        if (file == 0)
        {
            return ERROR_FILE_NOT_OPEN;
        }
        if (file != 0)
        {
            if (checkFileSizes(mutableFile, readableFile, encryptionKey) == ERROR_FILE_TOO_LARGEE)
            {
                return ERROR_FILE_TOO_LARGEE;
            }
            return NO_ERRORS;
        }
    }
    else if (mod == TYPE_ENCRYPT_3_5)
    {
        for (int array_element = 0; array_element < MAXIMUM_FILE_PATH_LENGTH; array_element++)
        {

            if (mutableFile.path[array_element] == '.' && mutableFile.path[array_element + 1] == 'b' && mutableFile.path[array_element + 2] == 'm' && mutableFile.path[array_element + 3] == 'p')
            {
                if (mutableFile.path[array_element + 4] == '\n')
                {
                    mutableFile.path[array_element + 4] = '\0';
                }
                int makefile = copyFile(mutableFile, readableFile);
                if (makefile == 0)
                {
                    return ERROR_FILE_NOT_CREATED;
                }
                else
                {
                    return NO_ERRORS;
                }
            }

        }
        return ERROR_FILE_NOT_BMP;
    }
    else if (mod == TYPE_DECRYPTION_3)
    {
        for (int array_element = 0; array_element < MAXIMUM_FILE_PATH_LENGTH; array_element++)
        {
            if (mutableFile.path[array_element] == '\n')
            {
                mutableFile.path[array_element] = '\0';
            }
        }
        char format_file[LINE_LENGTH_FOR_FORMAT_FILE] = { 0 };
        FILE* file = fopen(mutableFile.path, "wb");
        if (file == 0)
        {
            return ERROR_FILE_NOT_CREATED;
        }
        else
        {
            fclose(file);
            return NO_ERRORS;
        }
    }
    return 0;
}

