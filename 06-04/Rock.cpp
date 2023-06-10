/**
 * @brief Rock is gray
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include "Rock.h"

// Constructs a Rock object with a location of an x and y value
// Extends the Item superclass
Rock::Rock(int x, int y) : Item(x,y)
{

}

// Overrides the Item function and sets Rock's color to gray
std::string Rock::getColor()
{
    return "gray";
}

// Overrides the Item function and makes Rock's toString return an R
std::string Rock::toString()
{
    return "R";
}

