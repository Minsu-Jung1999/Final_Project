/**
 * @brief ItemGui makes window.
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
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
    rows(20),
    cols(20),
    width(20),
    height(20),
    tickButton(nullptr)
{


    // Window Settings
    window = new GWindow(400+60, 400);

    window->setTitle("Simulation");
    window->setBackground("White");
    GridSetting();
    GButton* button = new GButton("Random Posigion");
    window->addToRegion(button, "EAST");

    drawGrid();

    // Button Click Event
    button->setActionListener([this]()
                              {
                                  this->called();
                              });
}
void ItemGUI::GridSetting()
{
    grid.resize(rows, vector<Item*>(cols));

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int randomNumber = rand() % 100;
            switch(randomNumber % 4)
            {
            case 0:
                grid[row][col] = new Wood(row,col);
                break;
            case 1:
                grid[row][col] = new Water(row,col);
                break;
            case 2:
                grid[row][col] = new Rock(row,col);
                break;
            case 3:
                grid[row][col] = new House(row,col);
                break;
            }
        }
    }



}
void ItemGUI::drawGrid()
{
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            window->setColor(grid[row][col]->getColor());
            window->setFillColor(grid[row][col]->getColor());
            window->fillRect(col * width, row * height, width, height);
        }
    }
}

/**
 * When the Start Button is clicked, this function will be invoked.
 */
void ItemGUI::called()
{
    int randomRow = rand() % 20;
    int randomCol = rand() % 20;
    cout<<"randomem Row = " << randomRow<<endl;
    cout<<"randomem Col = " << randomCol << endl;
    cout<<"currentLocation : " << "[" << grid[randomRow][randomCol]->getX() << "]" << "[" << grid[randomRow][randomCol]->getY() << "]" << endl;
}


