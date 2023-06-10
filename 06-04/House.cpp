/**
 * @brief  House is a subclass of Item 
 * @details  House is a subclass of Item, but it is yellow and flammable
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include <iostream>
#include "House.h"

// Constructs a House object with a location of an x and y value
// Extends the Item superclass
House::House(int x, int y) : Item(x,y)
{

}

// Overrides the Item function and sets House's color to yellow
std::string House::getColor()
{
    return "yellow";
}

// Overrides the Item function and makes House's toString return an H
std::string House::toString()
{
    return "H";
}
