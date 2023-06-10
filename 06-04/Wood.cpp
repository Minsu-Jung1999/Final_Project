/**
 * @brief Wood is brown
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include "Wood.h"

// Constructs a Wood object which is brown and flammable
// Extends the Item superclass
Wood::Wood(int x, int y): Item(x,y)
{

}

// Overrides the Item function and sets Wood's color to brown
std::string Wood::getColor()
{
    return "brown";
}

// Overrides the Item function and returns a D
// (to differentiate from Water)
std::string Wood::toString()
{
    return "D";
}
