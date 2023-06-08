/**
 * @brief Water is blue
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include "Water.h"
#include <iostream>

Water::Water(int x, int y): Item(x,y)
{

}

std::string Water::getColor()
{
    return "blue";
}

std::string Water::toString()
{
    return "W";
}
