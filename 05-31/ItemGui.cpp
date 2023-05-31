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
    height(20)

{


    // Window Settings
    window = new GWindow(400, 400);
    window->setTitle("Simulation");
    window->setBackground("White");
    GridSetting();

    window->setTimerListener(50, [this] {
        this->drawGrid();
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
                grid[row][col] = new Wood();
                break;
            case 1:
                grid[row][col] = new Water();
                break;
            case 2:
                grid[row][col] = new Rock();
                break;
            case 3:
                grid[row][col] = new House();
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
