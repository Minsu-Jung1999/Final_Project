/**
 * @brief ItemGui makes window.
 * @details ItemGui creates an interactive GUI window containing a 20x20 grid of squares corresponding to Item objects
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
#include "Fire.h"

using namespace sgl;
using namespace std;

ItemGUI::ItemGUI() :
    // Default Grid Settings
    rows(20),
    cols(20),
    width(20),
    height(20),
    startButton(nullptr),
    tickButton(nullptr),
    saveButton(nullptr),
    loadButton(nullptr)
{
    // Window Settings
    window = new GWindow(400+60, 400);

    window->setTitle("Simulation");
    window->setBackground("White");
    GridSetting();
        
    // Start Button
    startButton = new GButton("start");
    window->addToRegion(startButton, "EAST");

    // Tick Button
    tickButton = new GButton("tick");
    window->addToRegion(tickButton, "EAST");    
        
    // Save Button
    saveButton = new GButton("Save");
    window->addToRegion(saveButton, "EAST");

    // Load Button
    loadButton = new GButton("Load");
    window->addToRegion(loadButton, "EAST");

    // Start Button Click Event
    startButton->setActionListener([this]() {
        this->start();
    });

    // Tick Button Click Event
    tickButton->setActionListener([this]() {
        this->update();
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
 * @brief ItemGUI::It iterates over each cell of the grid
 * and sets the color properties of the window 
 * based on the color of the class object stored in that cell.
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
 * randomly assigns a fire item to one of the 400 squares in the grid
 */
void ItemGUI::start()
{

    int randR = rand() % 20;
    int randC = rand() % 20;
    
    grid[randR][randC] = new Fire(randR, randC);
    
    drawGrid();
    
}

/**
 * @brief ItemGUI::update() updates the grid after each tick
 */
void ItemGUI::update(){
    
    // finds if each square on the grid is a fire square,
    // then spreads the fire to flammable adjacent squares
    
    // creates a temporary grid to store edits in this tick call
    vector<vector<int>> tempGrid;
     for(int r = 0; r<rows; r++){
        for(int c = 0; c<cols; c++){
            tempGrid[r][c].push_back(grid[r][c]);
        }
     }
            
    vector<vector<int>> adjLocs;
    
    for(int r = 0; r<rows; r++){
        for(int c = 0; c<cols; c++){
            
            // check if the square is a fire item
            if(grid[r][c]->getColor()=="red"){
                
                adjLocs = grid[r][c]->getAdjLocation();
                
                for(int i = 0; i<4; i++){
                    int adjR = adjLocs[i][0];
                    int adjC = adjLocs[i][1];
                    
                    // if the adjacent square is flammable (wood or house), make it a fire item
                    if(grid[adjR][adjC]->getColor=="brown" || grid[adjR][adjC]->getColor=="yellow"){
                       tempGrid[adjR][adjC] = new Fire();
                    }
                }
            }
        }
    }
    
    for(int r = 0; r<rows; r++){
        for(int c = 0; c<cols; c++){
            grid[r][c]=tempGrid[r][c]);
        }
     }
    
    drawGrid();
    
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
    ifstream inputFile("classes.txt");
    inputFile.open();
    char temp;
    string line;
    
    for (int row = 0; row < rows; ++row) {
        line = inputFile.getLine();
        for (int col = 0; col < cols; ++col) {
            // find which item it is by checking if its a "F" or "W" etc
            line[col] = temp;
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

