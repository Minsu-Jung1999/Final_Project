/**
 * @brief ItemGui makes window.
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#ifndef ITEMGUI_H
#define ITEMGUI_H

#include <vector>
#include <iostream>
#include "gwindow.h"
#include "gbutton.h"
#include "Item.h"

/**
 * @brief ItemGUI class creates an interactive gui window with buttons and a grid of colored squares
 */
class ItemGUI
{
private:
    sgl::GWindow* window; /* the gui window */
    sgl::GButton* tickButton; /* a button to tick the simulation forward once */
    sgl::GButton* saveButton; /* a button to save the current simulation to a file for later use */
    sgl::GButton* loadButton; /* a button to load a previous simulation from a file */
    std::vector<std::vector<Item*>> grid; /* stores the classes in each grid */
    const int rows;
    const int cols;
    const int width;
    const int height;

public:
    ItemGUI(); 
    void draw(); /* draws each shape */
    void setting(); 
    void drawGrid(); /* draws the entire grid */
    void openGUI(); /* opens the gui */
    void GridSetting(); 
    void addButton(); /* adds a button */
    void saveClassesToFile(); /* saves the current simulation to a txt file */
    void loadClassesFromFile(); /* reads a previous simulation from a txt file */
    bool isWindowOpen(); /* returns true if the gui is open */
    void start(); /* places a fire square on the grid to begin the simulation */



    // test function
    void called();
};

#endif // ITEMGUI_H
