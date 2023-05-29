
#ifndef WOOD_H
#define WOOD_H

#include "Item.h"


class Wood : public Item
{
public:
    Wood();
    virtual std::string getColor() override;
};

#endif // WOOD_H
