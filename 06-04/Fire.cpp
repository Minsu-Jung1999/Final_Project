/**
 * @brief Fire is red
 * @details Fire is a subclass of Item, but it is red and spreads fire
 * @author Natalie Roberts, Minsu Jung
 * @date June/7/2023
 * @version NONE
 */
#include "Fire.h"
#include <iostream>


// Constructs a Fire object with a location of an x and y value
// Extends the Item superclass
Fire::Fire(int x, int y): Item(x,y)
{

}

// Overrides the Item function and sets Fire's color to red
std::string Fire::getColor()
{
    return "red";
}

// Overrides the Item function and makes Fire's toString return an F
std::string Fire::toString()
{
    return "F";
}
