
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
