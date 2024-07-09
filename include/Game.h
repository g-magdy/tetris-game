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
    Grid grid;

private:
    void RotateBlock();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    bool isBlockOutside();
    void lockBlock();
    std::vector<Block> blocks;
    Block getRandomBLock();
    std::vector<Block> getBlocks();
    bool blockFits();
    Block currentBlock;
    Block nextBlock;
};