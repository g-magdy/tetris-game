#include "Grid.h"
#include "Constants.h"

Grid::Grid()
{
    this->numRows = rowCount;
    this->numCols = columnCount;
    this->cellSize = cellDimension;
    initialize();
    colors = getCellColors();
}

void Grid::initialize()
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            gridCells[i][j] = 0;
        }
    }
}

void Grid::print() const
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            std::cout << gridCells[i][j] << " ";
        }
        std::cout << "\n";
    }
}

std::vector<Color> Grid::getCellColors() const
{

    return {darkGrey, green, red, orange, yellow, purple, cyan, blue};
}

void Grid::draw() const
{
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < numCols; j++)
        {
            // the value in each cell represents the color
            int cellValue = gridCells[i][j];
            // j * cellSize is the x - offset [column]
            // i * cellSize is the y - offset [row]
            DrawRectangle(j * cellSize + 1, i * cellSize + 1, cellSize-1, cellSize-1, colors[cellValue]);
        }
    }   
}