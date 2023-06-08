/**
 * @brief Fire is red
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date June/7/2023
 * @version NONE
 */
#include "Fire.h"
#include <iostream>

Fire::Fire(int x, int y): Item(x,y)
{

}

std::string Fire::getColor()
{
    return "red";
}

std::string Fire::toString()
{
    return "F";
}

bool Fire::isOnFire()
{
    return true;
}
