/**
 * @brief Water is blue
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include "Water.h"
#include <iostream>


// Constructs a Water object which is blue and inflammable
// Extends the Item superclass
Water::Water(int x, int y): Item(x,y)
{

}

// Overrides the Item function and sets Water's color to blue
std::string Water::getColor()
{
    return "blue";
}

// Overrides the Item function and makes Water's toString return a W
std::string Water::toString()
{
    return "W";
}
