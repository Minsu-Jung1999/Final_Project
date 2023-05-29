/*
 * File: welcome.cpp
 * -----------------
 * Sample program used to confirm SGL install.
 */

#include <iostream>
#include <random>
#include "console.h"
#include "gwindow.h"
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
