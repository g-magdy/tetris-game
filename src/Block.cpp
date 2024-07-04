#include "Block.h"

Block::Block()
{
    this->cellSize = cellDimension;
    this->rotationalState = 0;
    colors = colorsArray;
}

void Block::draw()
{
    std::vector<Position> tiles = cells[rotationalState];
    for (auto tile : tiles)
    {
        // here the -1 and the +1 are used to show gridlines between blocks
        DrawRectangle(tile.column * cellSize + 1, tile.row * cellSize + 1, cellSize - 1, cellSize - 1, colors[id]);
    }
}