
#ifndef ITEMGUI_H
#define ITEMGUI_H


#include "gwindow.h"

class ItemGUI
{
private:
    sgl::GWindow* window;

    const int Rows;
    const int Cols;
    const int width;
    const int height;

public:
    ItemGUI();
    void drawGrid();
};

#endif // ITEMGUI_H
