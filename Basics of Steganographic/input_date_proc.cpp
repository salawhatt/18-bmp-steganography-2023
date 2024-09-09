#include "input_date_proc.h"

void InputProc::getText(int mode)
{
    if (mode == MODE_GET_COMPRESSION_RATE)
    {
        fgets(encryptionKey.packing_degree_array, GET_PATH_TO_FILE_FOR_STORING_ENCRYPTION + 1, stdin);
        cout << "\n Нажмите Enter, чтобы продолжить";
        while (getchar() != '\n');
    }
    if (mode == GET_PATH_TO_FILE_FOR_COPY)
    {
        fgets(mutableFile.path, MAXIMUM_FILE_PATH_LENGTH, stdin);
        cout << "\n Нажмите Enter, чтобы продолжить";
        while (getchar() != '\n');
    }
    if (mode == GET_PATH_TO_FILE_FOR_STORING_ENCRYPTION)
    {
        fgets(readableFile.path, MAXIMUM_FILE_PATH_LENGTH, stdin);
        cout << "\n Нажмите Enter, чтобы продолжить";
        while (getchar() != '\n');
    }
    if (mode == MODE_GET_KEY_ENCRYPTION)
    {
        fgets(encryptionKey.key, KEY_LENGTH_STAGE_ONE, stdin);
        cout << "\n Нажмите Enter, чтобы продолжить";
        while (getchar() != '\n');
    }
    if (mode == MODE_GET_KEY_DECRYPTION)
    {
        fgets(encryptionKey.key, KEY_LENGTH, stdin);
        cout << "\n Нажмите Enter, чтобы продолжить";
        while (getchar() != '\n');
    }
    if (mode == GET_PATH_TO_FILE_FOR_ENCRYPTION)
    {
        fgets(encryptionFile.path, MAXIMUM_FILE_PATH_LENGTH, stdin);
        cout << "\n Нажмите Enter, чтобы продолжить";
        while (getchar() != '\n');
    }
}

int InputProc::getKey()
{
    TUI.drawTUI(FIELD_HEIGHT_POINTS, TYPE_ENCRYPT_4);
    TUI.cursorMovementXY(22, 13);
    getText(MODE_GET_KEY_ENCRYPTION);
        if (encryptionKey.key[0] == ' ' || encryptionKey.key[1] == ' ' || encryptionKey.key[2] == ' ' || encryptionKey.key[3] == ' ' ||
            encryptionKey.key[5] == ' ' || encryptionKey.key[6] == ' ' || encryptionKey.key[7] == ' ' || encryptionKey.key[7] == '\n' || encryptionKey.key[7] == '\0' || encryptionKey.key[8] == '\n')
        {
            return ERROR_WRONG_KEY_INPUT;
        }
        else
        {
            char array_size[FILE_SIZE_LENGTH_IN_BYTES] = { 0 };

            struct stat buff_2;
            stat(encryptionFile.path, &buff_2);

            unsigned long long int size_cry = buff_2.st_size;
            itoa(size_cry, array_size, FILE_SIZE_LENGTH_IN_BYTES);

            for (int num_el = 0; num_el < FILE_SIZE_LENGTH_IN_BYTES; num_el++)
            {
                if (array_size[num_el] == '\0')
                {
                    array_size[num_el] = SYMBOL_FILLING_BLANK_CELLS;
                }
            }
            encryptionKey.key[9] = array_size[3];
            encryptionKey.key[10] = array_size[0];
            encryptionKey.key[11] = array_size[1];
            encryptionKey.key[12] = array_size[2];
            encryptionKey.key[13] = array_size[5];
            encryptionKey.key[14] = array_size[9];
            encryptionKey.key[15] = array_size[7];
            encryptionKey.key[16] = array_size[4];
            encryptionKey.key[17] = array_size[6];
            encryptionKey.key[18] = array_size[8];
            encryptionKey.key[8] = encryptionKey.packing_degree + '0';
            return NO_ERRORS;
        }
}

int InputProc::getFilePath(char mod)
{
    int chek_text = 0;
    if (mod == TYPE_ENCRYPT_2 || mod == TYPE_DECRYPTION_1)
    {
        TUI.drawTUI(FIELD_HEIGHT_POINTS, mod);
        getText(GET_PATH_TO_FILE_FOR_STORING_ENCRYPTION);
        if (readableFile.path[0] == '0' && readableFile.path[1] == '\n')
        {
            return BACK_TO_MENU;
        }
        else
        {
            chek_text = procFile.chekFileType(mod, mutableFile, readableFile, encryptionFile, encryptionKey);
            if (chek_text == ERROR_FILE_NOT_OPEN)
            {
                return ERROR_FILE_NOT_OPEN;
            }
            if (chek_text == ERROR_FILE_NOT_BMP)
            {
                return ERROR_FILE_NOT_BMP;
            }
            if (chek_text == NO_ERRORS)
            {
                return NO_ERRORS;
            }
        }
    }
    if (mod == TYPE_ENCRYPT_3)
    {
        TUI.drawTUI(FIELD_HEIGHT_POINTS, mod);
        getText(GET_PATH_TO_FILE_FOR_ENCRYPTION);
        if (encryptionFile.path[0] == '0' && encryptionFile.path[1] == '\n')
        {
            return BACK_TO_MENU;
        }
        else
        {
            chek_text = procFile.chekFileType(mod, mutableFile, readableFile, encryptionFile, encryptionKey);
            if (chek_text == ERROR_FILE_NOT_OPEN)
            {
                return ERROR_FILE_NOT_OPEN;
            }
            if (chek_text == ERROR_FILE_TOO_LARGEE)
            {
                return ERROR_FILE_TOO_LARGEE;
            }
            if (chek_text == NO_ERRORS)
            {
                return NO_ERRORS;
            }
        }
    }
    if (mod == TYPE_ENCRYPT_3_5)
    {
        TUI.drawTUI(FIELD_HEIGHT_POINTS, mod);
        getText(GET_PATH_TO_FILE_FOR_COPY);
        if (mutableFile.path[0] == '0' && mutableFile.path[1] == '\n')
        {
            return BACK_TO_MENU;
        }
        else
        {
            chek_text = procFile.chekFileType(mod, mutableFile, readableFile, encryptionFile, encryptionKey);
            if (chek_text == ERROR_FILE_NOT_CREATED)
            {
                return ERROR_FILE_NOT_CREATED;
            }
            if (chek_text == ERROR_FILE_NOT_BMP)
            {
                return ERROR_FILE_NOT_BMP;
            }
            return NO_ERRORS;
        }
    }
    if (mod == TYPE_DECRYPTION_3)
    {
        TUI.drawTUI(FIELD_HEIGHT_POINTS, mod);
        getText(GET_PATH_TO_FILE_FOR_COPY);
        if (mutableFile.path[0] == '0' && mutableFile.path[1] == '\n')
        {
            return BACK_TO_MENU;
        }
        else
        {
            chek_text = procFile.chekFileType(mod, mutableFile, readableFile, encryptionFile, encryptionKey);
            if (chek_text == ERROR_FILE_NOT_CREATED)
            {
                return ERROR_FILE_NOT_CREATED;
            }
            return NO_ERRORS;
        }
    }
    return 0;
}

int InputProc::getLongtoKey(Key& encryptionKey)
{
    unsigned int size_file;
    char array_size[FILE_SIZE_LENGTH_IN_BYTES];
    array_size[0] = encryptionKey.key[10]; //1
    array_size[1] = encryptionKey.key[11]; // 2 
    array_size[2] = encryptionKey.key[12]; //  3
    array_size[3] = encryptionKey.key[9];  //   4

    array_size[4] = encryptionKey.key[16];
    array_size[5] = encryptionKey.key[13];
    array_size[6] = encryptionKey.key[17];
    array_size[7] = encryptionKey.key[15];
    array_size[8] = encryptionKey.key[18];
    array_size[9] = encryptionKey.key[14];

    for (int element_number = 0; element_number < FILE_SIZE_LENGTH_IN_BYTES; element_number++)
    {
        if (array_size[element_number] == SYMBOL_FILLING_BLANK_CELLS)
        {
            array_size[element_number] = '\0';
        }
    }
    size_file = atoi(array_size);
    return size_file;
}

int InputProc::packingDegree()
{
    TUI.drawTUI(FIELD_HEIGHT_POINTS, TYPE_ENCRYPT_1);
    getText(MODE_GET_COMPRESSION_RATE);
    if (encryptionKey.packing_degree_array[0] == '0' && encryptionKey.packing_degree_array[1] == '\n')
    {
        return BACK_TO_MENU;
    }
    else if ((encryptionKey.packing_degree_array[0] == '1' || encryptionKey.packing_degree_array[0] == '2' || encryptionKey.packing_degree_array[0] == '4' || encryptionKey.packing_degree_array[0] == '8') && encryptionKey.packing_degree_array[1] == '\n')
    {
        encryptionKey.packing_degree = encryptionKey.packing_degree_array[0] - '0';
        return NO_ERRORS;
    }
    else
    {
        return UNACCEPTABLE_COMPRESSION_RATE;
    }
}