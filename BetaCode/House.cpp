/**
 * @brief  House is a subclass of Wood (burns for 10 seconds)
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include <iostream>
#include "House.h"

House::House(int x, int y) : Item(x,y)
{

}

/* returns yellow */
std::string House::getColor()
{
    return "yellow";
}
