/**
 * @brief Item cpp
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include "Item.h"
#include <iostream>
Item::Item()
{

}

bool Item::isFlammable()
{
    return true;
}
std::string Item::getType()
{
    return "";
}
std::string Item::getColor()
{
    return "";
}
 std::string Item::toString()
{
    return "";
}
int Item::getBurnTime()
{
    return 0;
}
int Item::getFireTime()
{
    return 0;
}
bool Item::isOnFire()
{
    return true;
}
int Item::getX()
{
    return 0;
}
int Item::getY()
{
    return 0;
}
std::vector<std::vector<int>> Item::getAdjLocation()
{
    return adjLocation;
}

