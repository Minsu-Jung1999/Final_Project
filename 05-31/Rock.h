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


class Rock : public Item
{
public:
    Rock();
    virtual std::string getColor() override;
};

#endif // ROCK_H
