/**
 * @brief ItemGui makes window.
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include "ItemGui.h"
#include <fstream>
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
    tickButton(nullptr),
    saveButton(nullptr),
    loadButton(nullptr)
{
    // Window Settings
    window = new GWindow(400+60, 400);

    window->setTitle("Simulation");
    window->setBackground("White");
    GridSetting();

    // Tick Button Or Start Button
    tickButton = new GButton("start");
    window->addToRegion(tickButton, "EAST");

    // Save Button
    saveButton = new GButton("Save");
    window->addToRegion(saveButton, "EAST");

    // Load Button
    loadButton = new GButton("Load");
    window->addToRegion(loadButton, "EAST");

    // Button Click Event
    tickButton->setActionListener([this]() {
        this->start();
    });

    // Save Button Click Event
    saveButton->setActionListener([this]() {
        this->saveClassesToFile();
    });

    // Load Button Click Event
    loadButton->setActionListener([this]() {
        this->loadClassesFromFile();
    });

    // asks the model to update and then redraw every half second
    window->setTimerListener(500, [this] {
        this->drawGrid();
    });
}

/**
 *  @brief GridSetting::initializes the grid vector by resizing it to the specified number of rows and columns.
 *  It iterates over each cell of the grid and assigns a randomly selected class object (Wood, Water, Rock, or House) based on a randomly generated number.
 */
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

/**
 * @brief ItemGUI::It iterates over each cell of the grid and sets the color properties of the window based on the color of the class object stored in that cell.
 */
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
 * @brief isWindowOpen:: returns false if the gui window is closed.
 */
bool ItemGUI::isWindowOpen()
{
    return window->isOpen();
}

/**
 * @brief start::When the Random Position Button is clicked, this function will be invoked.
 */
void ItemGUI::start()
{
    // Implementation in progress.

    // just for the checking
    cout<<"start() called" <<endl;
}

/**
 * @brief saveClassesToFile::Function to save the classes stored in the grid vector to a txt file.
 */
void ItemGUI::saveClassesToFile()
{
    ofstream outputFile("classes.txt");
    if (outputFile.is_open()) {
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                outputFile << grid[row][col]->toString() << " ";
            }
            outputFile << endl;
        }
        outputFile.close();
        cout << "Classes saved to file: classes.txt" << endl;
    } else {
        cout << "Unable to open the file for writing." << endl;
    }
}

/**
 * @brief loadClassesFromFile:: Function to load the classes from the "classes.txt" file and reinitialize the grid vector.
 */
void ItemGUI::loadClassesFromFile()
{
    // Implementation in progress.
    cout<<"loadClassesFromFile() called" <<endl;

}
