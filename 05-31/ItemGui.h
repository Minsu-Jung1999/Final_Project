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
#include "Item.h"

class ItemGUI
{
private:
    sgl::GWindow* window;
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
};

#endif // ITEMGUI_H
