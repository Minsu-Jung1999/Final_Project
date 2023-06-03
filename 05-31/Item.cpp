/**
 * @brief Item cpp
 * @details NONE
 * @author Natalie Roberts, Minsu Jung
 * @date May/15/2023
 * @version NONE
 */
#include "Item.h"
#include <iostream>
Item::Item()
{

}

bool Item::isFlammable()
{
    return true;
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
    return true;
}
int Item::getX()
{
    return 0;
}
int Item::getY()
{
    return 0;
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
    
    /* location0 */
    adjLocation[0][0] = currentR-1;
    adjLocation[0][1] = currentC;
    
    /* location1 */
    adjLocation[1][0] = currentR;
    adjLocation[1][1] = currentC+1;
    
    /* location2 */
    adjLocation[2][0] = currentR+1;
    adjLocation[2][1] = currentC;
    
    /* location3 */
    adjLocation[3][0] = currentR;
    adjLocation[3][1] = currentC-1;
        
    /**
     * if the index is -1 or 20, the location is off the grid (current location is an edge or corner)
     * and that location doesn't exist, so must be erased
     */
    
    for(int i = 0; i<4; i++){
        if(adjLocation[i][0] < 0 || adjLocation[i][0] > 19){
            adjLocation.erase(adjLocation.begin()+i);
            i--;
        }
        if(adjLocation[i][1] < 0 || adjLocation[i][1] > 19){
            adjLocation.erase(adjLocation.begin()+i);
            i--;
        }
    }
        
    return adjLocation;
    
}

