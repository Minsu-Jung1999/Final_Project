/**
 * @brief Wood is brown
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include "Wood.h"

Wood::Wood(int x, int y): Item(x,y)
{

}

std::string Wood::getColor()
{
    return "brown";
}
