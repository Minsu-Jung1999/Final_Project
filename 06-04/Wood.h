/**
 * @brief Wood is brown
 * @details Wood is a subclass of item, but it is brown and flammable
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#ifndef WOOD_H
#define WOOD_H

#include "Item.h"
#include <iostream>

// Wood class extends Item and overrides getColor() and toString()
// Wood objects are brown and flammable
class Wood : public Item
{
public:
    Wood(int x, int y);
    virtual std::string getColor() override;
    virtual std::string toString() override;

};

#endif // WOOD_H
