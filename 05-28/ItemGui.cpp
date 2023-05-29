
#include "ItemGui.h"
#include "gwindow.h"
#include "Item.h"
#include "Wood.h"
#include "Water.h"
#include "Rock.h"
#include "House.h"

using namespace sgl;
using namespace std;

ItemGUI::ItemGUI() :
    // Grid Settings
    Rows(20),
    Cols(20),
    width(20),
    height(20)

{


    // Window Settings
    window = new GWindow(400, 400);
    window->setTitle("Simulation");
    window->setBackground("White");
}

void ItemGUI::drawGrid()
{
    const int Rows = 20;
    const int Cols = 20;
    const int width = 20;
    const int height = 20;

    vector<vector<Item*>> grid(Rows, vector<Item*>(Cols));

    for (int row = 0; row < Rows; ++row) {
        for (int col = 0; col < Cols; ++col) {
            int randomNumber = rand() % 100;
            cout << "[ " << row << " ][ " << col << " ] = " << randomNumber << endl;
            Item* item;
            switch(randomNumber % 4)
            {
            case 0:
                item = new Wood();
                break;
            case 1:
                item = new Water();
                break;
            case 2:
                item = new Rock();
                break;
            case 3:
                item = new House();
                break;
            }


            grid[row][col] = item;

            window->setColor(item->getColor());
            window->setFillColor(item->getColor());
            window->fillRect(col * width, row * height, width, height);
        }
    }

    // Clean up allocated memory
    for (int row = 0; row < Rows; ++row) {
        for (int col = 0; col < Cols; ++col) {
            delete grid[row][col];
        }
    }
}


