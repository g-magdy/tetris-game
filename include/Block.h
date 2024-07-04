#pragma once

#include "Constants.h"

#include "Position.h"

class Block 
{
public:
    Block();
    int id;

    // the idea here is to have key value pairs
    // keys represent the rotational states (always 4)
    // the values (the vectors) represent 
    // the actual places of the blocks

    // the values are set in the constructor of each 
    // one of the child classes
    std::map<int, std::vector<Position>> cells;

    void draw();

private:
    int cellSize;
    int rotationalState;
    std::vector<Color> colors;
};