/**
 * @brief Water is blue
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#ifndef WATER_H
#define WATER_H

#include "Item.h"
#include <iostream>


class Water : public Item
{
public:
    Water();
    virtual std::string getColor() override;

};

#endif // WATER_H
