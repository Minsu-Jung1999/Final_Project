/**
 * @brief Item cpp
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */

#include "Item.h"
#include <iostream>

// constructs an item object at a coordinate location
Item::Item(int x, int y)
{
    location.push_back(x);
    location.push_back(y);

}

// returns true if the item is flammable
bool Item::isFlammable()
{
    return true;
}

// returns a string representation of the item's type
std::string Item::getType()
{
    return "";
}

// returns the item's color
std::string Item::getColor()
{
    return "";
}

// returns a string representation of the item
 std::string Item::toString()
{
    return "";
}

// returns the item's x value
int Item::getX()
{
    return location[0]; // return x
}

//returns the item's y value
int Item::getY()
{
    return location[1]; // return y
}

// returns the locations of the two, three, or four adjacent squares of a current square
// returns a vector of two, three, or four vectors containing <row, col> values
std::vector<std::vector<int>> Item::getAdjLocation()
{
    /**
     * each item will have either two, three, or four adjacent locations
     *
     * location0 is North (above current location)
     * location1 is East (to the right of current location)
     * location2 is South (under current location)
     * location3 is West (to the left of current location)
     *
     * top edge locations have location1, location2, location3
     * right edge locations have location0, location2, location3
     * bottom edge locations have location0, location1, location3
     * left edge locations have location0, location1, location2
     */
    
    int currentR = location[0];
    int currentC = location[1];

    // Calculate adjacent locations
    int dr[] = {-1, 0, 1, 0}; // Change in row (North, East, South, West)
    int dc[] = {0, 1, 0, -1}; // Change in column (North, East, South, West)

    for (int i = 0; i < 4; ++i) {
        int newRow = currentR + dr[i];
        int newCol = currentC + dc[i];

        // Check if the adjacent location is within the grid
        if (newRow >= 0 && newRow < 20 && newCol >= 0 && newCol < 20) {
            adjLocation.push_back({newRow, newCol});
        }
    }

    return adjLocation;
}

