/**
 * @brief  House is a subclass of Item
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include "Item.h"

// House class extends Item and overrides getColor() and toString()
class House : public Item
{
private:

public:
    House(int x, int y);

    /* returns its color */
    virtual std::string getColor() override;
    /* returns a string representation */
    virtual std::string toString() override;

};

#endif // HOUSE_H
