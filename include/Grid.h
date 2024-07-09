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
    void draw() const;
    bool isCellOutside(int row, int col);
    bool isCellEmpty(int row, int column);
};