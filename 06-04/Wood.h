/**
 * @brief Wood is brown
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#ifndef WOOD_H
#define WOOD_H

#include "Item.h"
#include <iostream>


class Wood : public Item
{
public:
    Wood(int x, int y);
    virtual std::string getColor() override;
    virtual std::string toString() override;

};

#endif // WOOD_H
