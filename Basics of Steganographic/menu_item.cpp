#include "menu_items.h"
#include "input_date_proc.h"
#include "encryption_gen.h"
int EncoderMenu::encoderItem()
{
    InputProc inputProcessor;
    Encoder en; 
    int go_to_menu = 1;
    while (go_to_menu == 1)
    {
        int chek_packing_degree = 0;
        chek_packing_degree = inputProcessor.packingDegree();
        if (chek_packing_degree == BACK_TO_MENU)
        {
            go_to_menu = BACK_TO_MENU;
        }
        else if (chek_packing_degree == UNACCEPTABLE_COMPRESSION_RATE)
        {
            warnings(UNACCEPTABLE_COMPRESSION_RATE);
        }
        while (chek_packing_degree == NO_ERRORS)
        {
            int chek_way = inputProcessor.getFilePath(TYPE_ENCRYPT_2);
            if (chek_way == BACK_TO_MENU)
            {
                chek_packing_degree = BACK_TO_MENU;
            }
            else
            {
                if (chek_way == ERROR_FILE_NOT_OPEN)
                {
                    warnings(ERROR_FILE_NOT_OPEN);
                }
                else  if (chek_way == ERROR_FILE_NOT_BMP)
                {
                    warnings(ERROR_FILE_NOT_BMP);
                }
            }
            while (chek_way == NO_ERRORS)
            {
                int chek_way_2 = inputProcessor.getFilePath(TYPE_ENCRYPT_3);
                if (chek_way_2 == BACK_TO_MENU)
                {
                    chek_way = BACK_TO_MENU;
                }
                else if (chek_way_2 == ERROR_FILE_NOT_OPEN)
                {
                    warnings(ERROR_FILE_NOT_OPEN);
                }
                else if (chek_way_2 == ERROR_FILE_TOO_LARGEE)
                {
                    warnings(ERROR_FILE_TOO_LARGEE);
                }
                else if (chek_way_2 == NO_ERRORS)
                {
                    while (chek_way_2 == NO_ERRORS)
                    {
                        int chek_way_3 = inputProcessor.getFilePath(TYPE_ENCRYPT_3_5);

                        if (chek_way_3 == BACK_TO_MENU)
                        {
                            chek_way_2 = BACK_TO_MENU;
                        }
                        else if (chek_way_3 == ERROR_FILE_NOT_CREATED)
                        {
                            warnings(ERROR_FILE_NOT_CREATED);
                        }
                        else if (chek_way_3 == ERROR_FILE_NOT_BMP)
                        {
                            warnings(ERROR_FILE_NOT_BMP);
                        }
                        while (chek_way_3 == NO_ERRORS)
                        {
                            int chek_key = inputProcessor.getKey();
                            if (chek_key == NO_ERRORS)
                            {
                                drawTUI(FIELD_HEIGHT_POINTS, TYPE_ENCRYPT_5, inputProcessor.encryptionKey.key);
                                en.coder(inputProcessor.mutableFile, inputProcessor.readableFile, inputProcessor.encryptionFile, inputProcessor.encryptionKey);
                                return NO_ERRORS;
                            }
                        }
                    }

                }
            }
        }
    }
    return 0;
}

int DecoderMenu::decoderItem()
{
    InputProc inputProcessor;
    Decrypt de;
    int go_to_menu = 1;
    while (1)
    {
        int chek_way = inputProcessor.getFilePath(TYPE_DECRYPTION_1);
        if (chek_way == BACK_TO_MENU)
        {
            return 0;
        }
        else  if (chek_way == ERROR_FILE_NOT_OPEN)
        {
            warnings(ERROR_FILE_NOT_OPEN);
        }
        else if (chek_way == ERROR_FILE_NOT_BMP)
        {
            warnings(ERROR_FILE_NOT_BMP);
        }
        while (chek_way == NO_ERRORS)
        {
            int chek_way_2 = inputProcessor.getFilePath(TYPE_DECRYPTION_3);
            if (chek_way_2 == BACK_TO_MENU)
            {
                chek_way = BACK_TO_MENU;
            }
            else if (chek_way_2 == ERROR_FILE_NOT_CREATED)
            {
                warnings(ERROR_FILE_NOT_CREATED);
            }
            else if (chek_way_2 == NO_ERRORS)
            {
                drawTUI(FIELD_HEIGHT_POINTS, TYPE_DECRYPTION_2);
                inputProcessor.getText(MODE_GET_KEY_DECRYPTION);
                de.coder(inputProcessor.mutableFile, inputProcessor.readableFile, inputProcessor.encryptionFile, inputProcessor.encryptionKey);
                if (inputProcessor.encryptionKey.key[0] == '0' && inputProcessor.encryptionKey.key[1] == '\n')
                {
                    chek_way = BACK_TO_MENU;
                }
                else
                {
                    //decrypt();
                    return NO_ERRORS;
                }
              
            }
        }
    }
}