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

class ItemGUI
{
private:
    sgl::GWindow* window;
    sgl::GButton* tickButton;
    sgl::GButton* saveButton;
    sgl::GButton* loadButton;
    std::vector<std::vector<Item*>> grid;/* stores the classes in each grid */
    const int rows;
    const int cols;
    const int width;
    const int height;

public:
    ItemGUI();
    void draw();
    void setting();
    void drawGrid();
    void openGUI();
    void GridSetting();
    void addButton();
    void saveClassesToFile();
    void loadClassesFromFile();
    bool isWindowOpen();
    void start();



    // test function
    void called();
};

#endif // ITEMGUI_H
