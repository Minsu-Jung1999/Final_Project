/**
 * @brief Fire is red
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date June/7/2023
 * @version NONE
 */
#ifndef FIRE_H
#define FIRE_H

#include "Item.h"
#include <iostream>


class Fire : public Item
{
public:
    Fire(int x, int y);
    virtual std::string getColor() override;
    virtual std::string toString() override;
    virtual bool isOnFire() override;
};

#endif // FIRE_H
