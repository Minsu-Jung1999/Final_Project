#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include "Item.h"


class House : public Item
{
private:

public:
    House();
    virtual std::string getColor() override;

};

#endif // HOUSE_H
