/**
 * @brief ItemGui class that creates a window.
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include "ItemGui.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "gwindow.h"
#include "Item.h"
#include "Wood.h"
#include "Water.h"
#include "Rock.h"
#include "House.h"
#include "Fire.h"

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
    loadButton(nullptr),
    isfinish(false),
    isAnimate(false),
    canAnimate(false)
{
    srand(static_cast<unsigned int>(time(nullptr)));


    // Window Settings
    window = new GWindow(400+60, 400);

    window->setTitle("Simulation");
    window->setBackground("White");
    GridSetting();

    // Tick Button Or Start Button
    startButton = new GButton("Start");
    window->addToRegion(startButton, "EAST");

    // Tick Button
    tickButton = new GButton("Tick");
    window->addToRegion(tickButton, "EAST");

    // Tick Button
    animateButton = new GButton("Animate");
    window->addToRegion(animateButton, "EAST");
    // Before start button is clicked, it is enabled.
    animateButton->setEnabled(false);

    stopAnimateButton = new GButton("StopAnimation");
    window->addToRegion(stopAnimateButton, "EAST");
    stopAnimateButton->setEnabled(false);

    // Save Button
    saveButton = new GButton("Save");
    window->addToRegion(saveButton, "EAST");

    // Load Button
    loadButton = new GButton("Load");
    window->addToRegion(loadButton, "EAST");


    // Start Button Click Event
    startButton->setActionListener([this]() {
        this->start();
        canAnimate=true;
    });

    // Tick Button Click Event
    tickButton->setActionListener([this]() {
        this->update();
    });

    // Animate Button Click Event
    animateButton->setActionListener([this]() {
        isAnimate= true;
    });

    // Save Button Click Event
    saveButton->setActionListener([this]() {
        this->saveClassesToFile();
    });

    // Load Button Click Event
    loadButton->setActionListener([this]() {
        this->loadClassesFromFile();
    });

    // Stop Button Click Event
    stopAnimateButton->setActionListener([this]() {
        isAnimate=false;
    });

    // asks the model to update and then redraw every half second
    window->setTimerListener(500, [this] {
        this->drawGrid();
        if(canAnimate)
            animateButton->setEnabled(true);
        if(isAnimate)
        {
            stopAnimateButton->setEnabled(true);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            this->update();
        }
    });

    // Set the random starting point for fire
    RandomPositionGenerator();
}

/**
 * @brief GridSetting initializes the grid vector by resizing it to the specified number of rows and columns.
 *        It iterates over each cell of the grid and assigns a randomly selected class object (Wood, Water, Rock, or House) based on a randomly generated number.
 */
void ItemGUI::GridSetting()
{
    grid.resize(rows, vector<Item*>(cols));

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            int randomNumber = rand() % 100;

            if (randomNumber < 40) {
                grid[row][col] = new Wood(row, col);
            } else if (randomNumber < 50) {
                grid[row][col] = new Water(row, col);
            } else if (randomNumber < 70) {
                grid[row][col] = new Rock(row, col);
            } else {
                grid[row][col] = new House(row, col);
            }
        }
    }
}

/**
 * @brief RandomPositionGenerator sets the random starting point for fire.
 */
void ItemGUI::RandomPositionGenerator()
{
    // Set the random starting point for fire
    startingX = rand() % 20;
    startingY = rand() % 20;

    cout << "Random Position = [" << startingX << "] [" << startingY << "]" << endl;
}

/**
 * @brief drawGrid iterates over each cell of the grid and sets the color properties of the window based on the color of the class object stored in that cell.
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
 * @brief isWindowOpen returns false if the GUI window is closed.
 */
bool ItemGUI::isWindowOpen()
{
    return window->isOpen();
}

/**
 * @brief start is invoked when the Start Button is clicked.
 *        If the random class is a flammable Item (Wood, House), it sets the starting point as Fire.
 *        If it is not a flammable Item (Rock, Water), it generates a new random starting point and calls start() again.
 */
void ItemGUI::start()
{
    cout << "start() called" << endl;

    // If the random class is a flammable Item (Wood, House)
    if (grid[startingX][startingY]->isFlammable())
    {
        grid[startingX][startingY] = new Fire(startingX, startingY);
    }
    // If it is not a flammable Item (Rock, Water)
    else
    {
        RandomPositionGenerator();
        start();
    }
}

/**
 * @brief saveClassesToFile saves the classes stored in the grid vector to a text file.
 */
void ItemGUI::saveClassesToFile()
{
    ofstream outputFile("classes.txt");
    if (outputFile.is_open()) {
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                outputFile << grid[row][col]->toString();
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
 * @brief update updates the grid after each tick.
 */
void ItemGUI::update() {
    cout << "tick is called()" << endl;

    // Create a temporary grid to store edits in this tick call
    vector<vector<Item*>> tempGrid = grid;

    bool canSpreadFire = false; // Flag to track if fire can spread

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            // Check if the square is a fire item
            if (grid[r][c]->isOnFire()) {
                // Get the adjacent locations of the current square
                vector<vector<int>> adjLocs = grid[r][c]->getAdjLocation();

                // Spread the fire to flammable adjacent squares
                for (const auto& loc : adjLocs) {
                    int adjR = loc[0];
                    int adjC = loc[1];

                    // Check if the adjacent square is within the grid boundaries and is flammable
                    if (adjR >= 0 && adjR < rows && adjC >= 0 && adjC < cols && tempGrid[adjR][adjC]->isFlammable()) {
                        // Make the adjacent square a fire item
                        tempGrid[adjR][adjC] = new Fire(adjR, adjC);
                        canSpreadFire = true; // Fire can spread
                    }
                }
            }
        }
    }

    // Update the grid with the changes made in this tick
    grid = tempGrid;

    // Check if fire can no longer spread
    if (!canSpreadFire) {
        window->setTitle("Finish!");
        isfinish=true;
    }
}

/**
 * @brief loadClassesFromFile loads the classes from the "classes.txt" file and reinitializes the grid vector.
 */
void ItemGUI::loadClassesFromFile()
{
    ifstream inputFile;
    inputFile.open("classes.txt");
    char temp;
    string line;

    for (int row = 0; row < rows; ++row) {
        getline(inputFile,line);
        for (int col = 0; col < cols; ++col) {
            // find which item it is by checking if its a "F" or "W" etc
            temp = line[col];

            //inputFile >> temp;
            if(temp=='F'){
                grid[row][col] = new Fire(row, col);
            } else if (temp=='H'){
                grid[row][col] = new House(row, col);
            } else if (temp=='R'){
                grid[row][col] = new Rock(row, col);
            } else if (temp=='W'){
                grid[row][col] = new Water(row, col);
            } else if (temp=='D'){
                grid[row][col] = new Wood(row, col);
            }
        }
    }

    drawGrid();

}
