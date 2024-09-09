#include "macros.h"
#include "TUI.h"
#include "menu_items.h"

class Programm {
public:
    TUIBase MainMenu;
    OtherMessages Item;
    EncoderMenu MenuItemEnc;
    DecoderMenu MenuItemDec;
    void run()
    {
        while (1)
        {
            system("cls");
            MainMenu.drawTUI(FIELD_HEIGHT_MENU, TYPE_MAIN_MENU);
            int selected_item = MainMenu.arrowMovement(MAXIMUM_POSITION_POINT_Y_AXIS_MENU);
            if (selected_item == 1)
                MenuItemEnc.encoderItem();
            else if (selected_item == 2)
                MenuItemDec.decoderItem();
            else if (selected_item == 3)
                Item.instruction();
            else if (selected_item == 4) {
                system("cls");
                exit(0);
            }
               
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Programm Start;
    Start.run();
    return 0;
}