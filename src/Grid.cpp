#include "Grid.h"
#include "Constants.h"

Grid::Grid()
{
    this->numRows = rowCount;
    this->numCols = columnCount;
    this->cellSize = cellDimension;
    initialize();
    colors = colorsArray;
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

bool Grid::isCellOutside(int row, int col)
{
    return !(row >= 0 && row < numRows && col >= 0 && col < numCols);
}

bool Grid::isCellEmpty(int row, int column)
{
    return (gridCells[row][column] == 0);
}

bool Grid::isRowComplete(int row)
{
    for (int i = 0; i < columnCount; i++)
        if (gridCells[row][i] == 0)
            return false;

    return true;
}

void Grid::shiftRowDown(int row, int shift)
{
    for (int i = 0; i < columnCount; i++)
    {
        if (row + shift < numRows)
            gridCells[row + shift][i] = gridCells[row][i];
        
        gridCells[row][i] = 0;
    }
}

void Grid::clearRow(int row)
{
    for (int i = 0; i < columnCount; i++)
    {
        gridCells[row][i] = 0;
    }
}

void Grid::handleCompletedRows()
{
    int completedRows = 0;
    for (int r = rowCount - 1; r >= 0; r--)
    {
        if (isRowComplete(r))
        {
            completedRows++;
            clearRow(r);
        }
        else if (completedRows > 0)
        {
            shiftRowDown(r, completedRows);
        }
    }
}