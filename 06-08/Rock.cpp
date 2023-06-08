/**
 * @brief Rock is gray
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include "Rock.h"


Rock::Rock(int x, int y) : Item(x,y)
{

}

std::string Rock::getColor()
{
    return "gray";
}

std::string Rock::toString()
{
    return "R";
}

