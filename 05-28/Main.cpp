/*
 * File: welcome.cpp
 * -----------------
 * Sample program used to confirm SGL install.
 */

#include <iostream>
#include "console.h"
#include "gwindow.h"
using namespace std;
using namespace sgl;



void simulation()
{
    GWindow* window = new GWindow(400, 400);
    window->setTitle("Simulation");
    window->setBackground("Green");
}

int main()
{
    cout << "Animate? ";
    string choise;
    getline(cin, choise);
    simulation();
    return 0;
}
