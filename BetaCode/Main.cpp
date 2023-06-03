/**
 * @brief Our simulation runs on a 20x20 grid of Items and simulates each item being burned and spreading to another item.
 * @details Each square is randomly assigned as Water, Wood, House, or Rock. Each subclass has unique characteristics: Water is non-flammable and blue, Wood is flammable (burn time of 5 seconds) and brown, House is a subclass of Wood (burns for 10 seconds), and Rock is non-flammable and gray.
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */

#include <iostream>
#include <random>
#include "console.h"
#include "gwindow.h"
#include "gbutton.h"
#include "Item.h"
#include "Wood.h"
#include "Water.h"
#include "Rock.h"
#include "House.h"
#include "ItemGui.h"

using namespace std;
using namespace sgl;

int main()
{

    cout << "Animate? ";
    string choise;
    getline(cin, choise);
    ItemGUI gui;

    gui.drawGrid();

    return 0;
}
