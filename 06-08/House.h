/**
 * @brief  House is a subclass of Wood (burns for 10 seconds)
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include "Wood.h"


class House : public Wood
{
private:

public:
    House(int x, int y);

    /* returns its color */
    virtual std::string getColor() override;
    virtual std::string toString() override;

};

#endif // HOUSE_H
