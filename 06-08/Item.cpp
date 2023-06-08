/**
 * @brief Item cpp
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include "Item.h"
#include <iostream>
Item::Item(int x, int y)
{
    location.push_back(x);
    location.push_back(y);
    onFire = false;
}

bool Item::isFlammable()
{
    return false;
}
std::string Item::getType()
{
    return "";
}
std::string Item::getColor()
{
    return "";
}
 std::string Item::toString()
{
    return "";
}
int Item::getBurnTime()
{
    return 0;
}
int Item::getFireTime()
{
    return 0;
}
bool Item::isOnFire()
{
    return onFire;
}
int Item::getX()
{
    return location[0]; // return x
}
int Item::getY()
{
    return location[1]; // return y
}
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

