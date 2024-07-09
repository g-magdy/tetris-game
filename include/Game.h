#pragma once

#include "Grid.h"
#include "Block.h"
#include "../src/BlockTypes.cpp"

class Game 
{
public:
    Game();
    void draw();
    void handleInput();
    void handleCompletedRows();
    Grid grid;

    void RotateBlock();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
private:
    bool isBlockOutside();
    void lockBlock();
    std::vector<Block> blocks;
    Block getRandomBLock();
    std::vector<Block> getBlocks();
    bool blockFits();
    Block currentBlock;
    Block nextBlock;
};