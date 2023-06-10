/**
 * @brief Water is blue and inflammable
 * @details Water is a subclass of item, but it is blue and inflammable
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#ifndef WATER_H
#define WATER_H

#include "Item.h"
#include <iostream>

// Constructs a Water object which is blue and inflammable
// Extends the Item superclass
class Water : public Item
{
public:
    Water(int x, int y);
    virtual std::string getColor() override;
    virtual std::string toString() override;

};

#endif // WATER_H
