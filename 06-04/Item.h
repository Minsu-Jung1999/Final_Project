/**
 * @brief Item is a supper class.
 * @details Items are objects with characteristics about fire, like flammability, color, and adjacent locations
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <vector>


// Item class respresents an item with a specified color, flammability, type, string representation, and adjacent locations
class Item
{
private:
    int fireTime;   /* stores the number of seconds it will take for the item to catch on fire */
    int burnTime;   /* stores the number of seconds the item will burn for, before becoming burnt (incapable of spreading fire, colored black, not flammable)*/
    std::vector<int> location;       /* stores its position of x, y */
    std::vector<std::vector<int>> adjLocation;    /* stores adjacent positions of x, y */


public:
    Item(int x, int y);
    virtual bool isFlammable();   /* returns true if the object is flammable and can catch fire.*/
    virtual std::string getType();  /* returns a string of the item’s name*/
    virtual std::string getColor(); /* returns a string of the item’s color*/
    virtual std::string toString(); /* returns a string referring to the item*/
    virtual int getX(); /* returns its x location*/
    virtual int getY(); /* returns its y location*/
    virtual std::vector<std::vector<int>> getAdjLocation();   /* returns the locations of the four adjacent positions */


};

#endif // ITEM_H
