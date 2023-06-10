/**
 * @brief Fire is red
 * @details  Fire is a subclass of Item, but it is red and spreads fire
 * @author Natalie Roberts, Minsu Jung
 * @date June/7/2023
 * @version NONE
 */
#ifndef FIRE_H
#define FIRE_H

#include "Item.h"
#include <iostream>


// Fire class extends Item and overrides getColor() and toString()
class Fire : public Item
{
public:
    Fire(int x, int y);
    virtual std::string getColor() override;
    virtual std::string toString() override;
};

#endif // FIRE_H
