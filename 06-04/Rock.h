/**
 * @brief Rock is gray
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#ifndef ROCK_H
#define ROCK_H

#include <iostream>
#include "Item.h"

// Rock class extends Item and is gray and inflammable
class Rock : public Item
{
public:
    Rock(int x, int y);
    virtual std::string getColor() override; /* returns gray */
    virtual std::string toString() override; /* returns R */
};

#endif // ROCK_H
