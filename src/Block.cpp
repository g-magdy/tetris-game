#include "Block.h"

Block::Block()
{
    this->cellSize = cellDimension;
    this->rotationalState = 0;
    this->rowOffset = 0;
    this->columnOffset = 0;
    colors = colorsArray;
}

void Block::draw()
{
    std::vector<Position> tiles = getCellPositions();
    for (auto tile : tiles)
    {
        // here the -1 and the +1 are used to show gridlines between blocks
        DrawRectangle(tile.column * cellSize + 11, tile.row * cellSize + 11, cellSize - 1, cellSize - 1, colors[id]);
    }
}

void Block::move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

std::vector<Position> Block::getCellPositions()
{
    std::vector<Position> tiles = cells[rotationalState];
    std::vector<Position> movedTiles;

    for (auto tile : tiles)    
    {
        movedTiles.push_back(Position(tile.row + rowOffset, tile.column + columnOffset));
    }
    return movedTiles;
}

void Block::rotate()
{
    rotationalState++;
    rotationalState = int(abs(rotationalState) % 4);
}

void Block::undoRotation()
{
    rotationalState--;
    rotationalState = int(abs(rotationalState) % 4);
}