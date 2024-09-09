#include "macros.h"
#include "encryption_gen.h"
#include "input_date_proc.h"

void Encoder::coder(File& mutableFile, File& readableFile, File& encryptionFile, Key& encryptionKey) 
{
    unsigned char text;
    unsigned char img;
    FileOperations FileProc;
    FileProc.copyFile(mutableFile, readableFile);
    process.makeMask(encryptionKey, img, text);
    int old_file_position = process.makeSeed(encryptionKey);
    unsigned char symbol_in_txt = 0;
    unsigned char symbol_in_bmp;
    unsigned char received_bytes_img;
    unsigned char received_bytes_txt;
    unsigned char result;

    FILE* file_read = fopen(readableFile.path, "rb");
    FILE* file_encoder = fopen(encryptionFile.path, "rb");
    FILE* file_write = fopen(mutableFile.path, "rb+");
    fseek(file_read, BMP_SYSTEM_PART, 0);
    fseek(file_write, BMP_SYSTEM_PART, 0);

    unsigned long long int new_file_position = 0;
    struct stat size_write_file;
    stat(mutableFile.path, &size_write_file);
    struct stat size_encoder_file;
    stat(encryptionFile.path, &size_encoder_file);

    int one_percent = size_encoder_file.st_size / ONE_HUNDRED_PERCENT;
    int count_percent = 0;
    int byte_count = 0;
    while (!feof(file_encoder))
    {
        if (byte_count == one_percent)
        {
            count_percent++;
            // show_percentage(count_percent);
            byte_count = 0;
        }
        fread(&symbol_in_txt, sizeof(unsigned char), 1, file_encoder);

        for (int byte_amount = 0; byte_amount < BIT_IN_CHARACTER;byte_amount += encryptionKey.packing_degree)
        {
            new_file_position = process.lcg(old_file_position);
            old_file_position = new_file_position;
            while (new_file_position > size_write_file.st_size || new_file_position < BMP_SYSTEM_PART + 1)
            {
                new_file_position = process.lcg(old_file_position);
                old_file_position = new_file_position;
            }
            fseek(file_read, new_file_position, 0);
            fread(&symbol_in_bmp, sizeof(unsigned char), 1, file_read);
            received_bytes_img = symbol_in_bmp & img;
            received_bytes_txt = symbol_in_txt & text;
            received_bytes_txt = received_bytes_txt >> (BIT_IN_CHARACTER - encryptionKey.packing_degree);
            result = received_bytes_txt | received_bytes_img;
            fseek(file_write, new_file_position, 0);
            fwrite(&result, sizeof(unsigned char), 1, file_write);

            symbol_in_txt = symbol_in_txt << encryptionKey.packing_degree;
        }
        byte_count++;
    }
    fclose(file_write);
    fclose(file_encoder);
    fclose(file_read);
    printf("\n\n\n");
    system("pause");
}

void Decrypt::coder(File& mutableFile, File& readableFile, File& encryptionFile, Key& encryptionKey) 
{
    unsigned char text;
    unsigned char img;
    InputProc InpProc;
    encryptionKey.packing_degree = encryptionKey.key[8] - '0';
    process.makeMask(encryptionKey, img, text);
    img = ~img;
    struct stat size_decrypte_file;
    stat(readableFile.path, &size_decrypte_file);

    int size_img = size_decrypte_file.st_size;
    int size_txt = InpProc.getLongtoKey(encryptionKey);
    int old_file_position = process.makeSeed(encryptionKey);
    FILE* file_read = fopen(readableFile.path, "rb+");
    FILE* file_decrypt = fopen(mutableFile.path, "wb+");

    int read_symb = 0;
    int one_percent = size_txt / ONE_HUNDRED_PERCENT;
    int count_read_symb_for_percent = 0;
    int count_percent = 0;
    fseek(file_read, BMP_SYSTEM_PART, 0);
    while (read_symb <= size_txt)
    {
        if (count_read_symb_for_percent == one_percent)
        {
            count_percent++;
            //show_percentage(count_percent);
            count_read_symb_for_percent = 0;
        }

        unsigned char symbol = 0;
        unsigned char img_byte = 0;
        for (int bites_read = 0; bites_read < 8;bites_read += encryptionKey.packing_degree)
        {
            int new_file_position = process.lcg(old_file_position);
            old_file_position = new_file_position;
            while (new_file_position > size_decrypte_file.st_size || new_file_position < BMP_SYSTEM_PART + 1)
            {
                new_file_position = process.lcg(old_file_position);
                old_file_position = new_file_position;
            }
            fseek(file_read, new_file_position, 0);
            fread(&img_byte, sizeof(unsigned char), 1, file_read);
            img_byte = img_byte & img;
            symbol = symbol << encryptionKey.packing_degree;
            symbol = symbol | img_byte;
        }
        fwrite(&symbol, sizeof(unsigned char), 1, file_decrypt);
        read_symb++;
        count_read_symb_for_percent++;
    }
    fclose(file_read);
    fclose(file_decrypt);
    printf("\n\n\n");
    system("pause");
}