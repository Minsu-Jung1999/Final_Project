/**
 * @brief  House is a subclass of Wood (burns for 10 seconds)
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include <iostream>
#include "House.h"

House::House(int x, int y) : Wood(x,y)
{

}

std::string House::getColor()
{
    return "yellow";
}
std::string House::toString()
{
    return "H";
}

