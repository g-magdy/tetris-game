#pragma once
#include "Constants.h"

class Grid
{
private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> colors;

public:
    Grid();
    int gridCells[20][10];
    void initialize();
    void print() const;
    std::vector<Color> getCellColors() const ;
    void draw() const;
};