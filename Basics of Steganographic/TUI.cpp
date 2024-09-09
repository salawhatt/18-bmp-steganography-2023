#include "TUI.h"

void TUIBase::cursorMovementXY(SHORT x, SHORT y)
{
	COORD p = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
}

void TUIBase::drawTUI(int height, char type)
{
    system("cls");
    for (int Y_axis_box = 0; Y_axis_box < height + 1; Y_axis_box++)
    {
        cursorMovementXY(0, Y_axis_box);
        cout << "|";
        cursorMovementXY(FIELD_WIDTH, Y_axis_box);
        cout << "|";
    }
    for (int X_axis_box = 0; X_axis_box < FIELD_WIDTH + 1; X_axis_box++)
    {
        cursorMovementXY(X_axis_box, 0);
        cout << "~";
        cursorMovementXY(X_axis_box, height);
        cout << "~";
    }
    if (type == TYPE_MAIN_MENU) {
        cursorMovementXY(MAXIMUM_POSITION_POINT_Y_AXIS_MENU + 16, POINT_HOME_Y_AXIS - 2);
        cout << "Encrypt or Decrypt text" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS, POINT_HOME_Y_AXIS);
        cout << "1. Encrypt text in BMP" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS, POINT_HOME_Y_AXIS + POINT_STEP);
        cout << "2. Decrypt text" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS, POINT_HOME_Y_AXIS + (POINT_STEP * 2));
        cout << "3. Instruction " << endl;
        cursorMovementXY(POINT_HOME_X_AXIS, POINT_HOME_Y_AXIS + (POINT_STEP * 2) + 2);
        cout << "4. Exit " << endl;
    }
    else if (type == TYPE_DECRYPTION_1) {
        cursorMovementXY(MAXIMUM_POSITION_POINT_Y_AXIS_MENU + 16, POINT_HOME_Y_AXIS - 2);
        cout << "Decryption the text " << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS);
        cout << "Maximum length 260 characters" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP);
        cout << "If the path is longer, it will be cut off!" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + (POINT_STEP * 4));
        cout << "Enter the path to the image container:";
    }
    else if (type == TYPE_DECRYPTION_2) {
        cursorMovementXY(MAXIMUM_POSITION_POINT_Y_AXIS_MENU + 16, POINT_HOME_Y_AXIS - 2);
        cout << "Decryption the text " << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 2);
        cout << "Maximum length 19 characters" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 3);
        cout << "If the key is longer, it will be cut off!" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + (POINT_STEP * 5));
        cout << "                     -------------------" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + (POINT_STEP * 4));
        cout << "Enter Encryption KEY:";
    }
    else if (type == TYPE_DECRYPTION_3) {
        cursorMovementXY(MAXIMUM_POSITION_POINT_Y_AXIS_MENU + 16, POINT_HOME_Y_AXIS - 2);
        cout << "Decryption the text " << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS);
        cout << "Maximum length 260 characters" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP);
        cout << "If the path is longer, it will be cut off!" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + (POINT_STEP * 4));
        cout << "Enter the path to save the decrypted:";
    }
    else if (type == TYPE_ENCRYPT_1) {
        cursorMovementXY(MAXIMUM_POSITION_POINT_Y_AXIS_MENU + 16, POINT_HOME_Y_AXIS - 2);
        cout << "Encrypt text in BMP" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + (POINT_STEP * 2));
        cout << "Maximum length 1 characters " << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 3);
        cout << "If the length is longer, it will be cut off!" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + (POINT_STEP * 4));
        cout << "Enter compression ratio (1, 2, 4, 8):";
    }
    else if (type == TYPE_ENCRYPT_2) {
        cursorMovementXY(MAXIMUM_POSITION_POINT_Y_AXIS_MENU + 16, POINT_HOME_Y_AXIS - 2);
        cout << "Encrypt text in BMP" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 2);
        cout << "Maximum length 260 characters" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 3);
        cout << "If the path is longer, it will be cut off!" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + (POINT_STEP * 4));
        cout << "Enter the path to the container file:";
    }
    else if (type == TYPE_ENCRYPT_3) {
        cursorMovementXY(MAXIMUM_POSITION_POINT_Y_AXIS_MENU + 16, POINT_HOME_Y_AXIS - 2);
        cout << "Encrypt text in BMP" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 2);
        cout << "Maximum length 260 characters" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 3);
        cout << "If the path is longer, it will be cut off!" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + (POINT_STEP * 4));
        cout << "Enter the path to the encrypted file:";
    }
    else if (type == TYPE_ENCRYPT_3_5) {
        cursorMovementXY(MAXIMUM_POSITION_POINT_Y_AXIS_MENU + 16, POINT_HOME_Y_AXIS - 2);
        cout << "Encrypt text in BMP" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 2);
        cout << "Maximum length 260 characters" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 3);
        cout << "If the path is longer, it will be cut off!" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + (POINT_STEP * 4));
        cout << "Enter the path to save the copy:";
    }
    else if (type == TYPE_ENCRYPT_4)
    {
        cursorMovementXY(MAXIMUM_POSITION_POINT_Y_AXIS_MENU + 16, POINT_HOME_Y_AXIS - 2); 
        cout << "Encrypt text in BMP" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 2);
        cout << "Maximum length 8 characters" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 3);
        cout << "If the key is longer, it will be cut off!" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 3 + 1);
        cout << "Your key will be padded with one character at the end!" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + (POINT_STEP * 5)); 
        cout << "                     --------" << endl;
        cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + (POINT_STEP * 4)); 
        cout << "Enter Encryption KEY:";
    }
}

void TUIBase::drawTUI(int height, char type, char* key)
{
    system("cls");
    for (int Y_axis_box = 0; Y_axis_box < height + 1; Y_axis_box++)
    {
        cursorMovementXY(0, Y_axis_box);
        cout << "|";
        cursorMovementXY(FIELD_WIDTH, Y_axis_box);
        cout << "|";
    }
    for (int X_axis_box = 0; X_axis_box < FIELD_WIDTH + 1; X_axis_box++)
    {
        cursorMovementXY(X_axis_box, 0);
        cout << "~";
        cursorMovementXY(X_axis_box, height);
        cout << "~";
    }
    cursorMovementXY(MAXIMUM_POSITION_POINT_Y_AXIS_MENU + 14, POINT_HOME_Y_AXIS - 2);
    cout << "Text successfully written to BMP" << endl;
    cursorMovementXY(POINT_HOME_X_AXIS - 23, POINT_HOME_Y_AXIS + POINT_STEP * 2);
    cout << "Your KEY:" << endl; 
    for (int i = 0; i < 19; i++)
    {
        cout << key[i];
    }
}

int TUIBase::arrowMovement(int maximum_position_y)
{
    int pressed_button = 0; //нажатая кнопка
    int pointer_location = POINT_HOME_Y_AXIS; //отслеживание местоположения курсора
    cursorMovementXY(POINT_HOME_X_AXIS, POINT_HOME_Y_AXIS);
    cout << '\b' << ">";
    cursorMovementXY(HIDDEN_POINT_POSITION, HIDDEN_POINT_POSITION);

    while (pressed_button != ENTER_BUTTON) //если не Enter
    {

        pressed_button = getch();

        if (pressed_button == BUTTON_DOWN) //вниз
        {

            cursorMovementXY(POINT_HOME_X_AXIS - 1, pointer_location);
            cout << ' ';

            pointer_location = pointer_location + POINT_STEP;
            if (pointer_location == maximum_position_y + POINT_STEP)
            {
                pointer_location = POINT_HOME_Y_AXIS;
            }
            cursorMovementXY(POINT_HOME_X_AXIS, pointer_location);
            cout << '\b' << ">";
            cursorMovementXY(HIDDEN_POINT_POSITION, HIDDEN_POINT_POSITION);

        }
        else if (pressed_button == BUTTON_UP) //вверх
        {

            cursorMovementXY(POINT_HOME_X_AXIS - 1, pointer_location);
            cout << ' ';
            pointer_location = pointer_location - POINT_STEP;
            if (pointer_location == POINT_HOME_Y_AXIS - POINT_STEP)
            {
                pointer_location = maximum_position_y;
            }
            cursorMovementXY(POINT_HOME_X_AXIS, pointer_location);
            cout << '\b' << ">";
            cursorMovementXY(HIDDEN_POINT_POSITION, HIDDEN_POINT_POSITION);
        }
    }
    int translation_location_to_point_number = (pointer_location / 2) - 1;
    return translation_location_to_point_number;
}

void OtherMessages::instruction()
{
    system("cls");
    cout << "Шифровка файла\n"
        << "\t\t1) Введите путь к файлу, который будет являться стегоконтейнером.\n"
        << "\t\t2) Введите путь к файлу, который будет шифроваться.\n"
        << "\t\t3) Введите путь к файлу, который станет итоговым изображением\n"
        << "\t\t4) Введите код длинной 8 символов. Учтите, что код будет дополнен дополнительными \n"
        << "символами. Запомните его для дальнейшей дешифровки.\n"
        << "\n\n"
        << "Дешифровка файла \n"
        << "\t\t1)	Введите путь к файлу, который является стегоконтейнером.\n"
        << "\t\t2)	Введите путь к файлу, куда будет сохранена расшифровка. Он создастся там, где вы \n укажете.\n"
        << "\t\t3)	Введите ключ для дешифровки.\n"
        << "\t\t4)	Файл расшифрован.\n"
        << "\n\n"
        << "Другое:\n"
        << "\t•	Для возврата из любого пункта назад введите 0\n"
        << "\t•	При больших размерах контейнера или шифруемого файла, шифровка может занять около 30 секунд\n"
        << "\t•	Процесс шифровки и дешифровки вы можете отслеживать. \n\n";
    system("pause");
}

void OtherMessages::warnings(int mod)
{
    cursorMovementXY(HIDDEN_POINT_POSITION, CURSOR_POSITION_FOR_WARNING);
    if (mod == ERROR_INVALID_INPUT)
    {
        cout << "Invalid value\n";
    }
    else if (mod == ERROR_FILE_NOT_OPEN)
    {
        cout << "File not open\n";
    }
    else if (mod == ERROR_FILE_NOT_BMP)
    {
        cout << "File not BMP\n";
    }
    else if (mod == ERROR_BLANK_FIELD)
    {
        cout << "You didn't enter anything\n";
    }
    else if (mod == ERROR_WRONG_KEY_INPUT)
    {
        cout << "Key entered incorrectly\n";
    }
    else if (mod == ERROR_FILE_TOO_LARGEE)
    {
        cout << "File does not fit in image\n";
    }
    else if (mod == ERROR_FILE_NOT_CREATED)
    {
        cout << "File could not be created\n";
    }
    system("pause");
}
