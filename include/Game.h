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
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();
    bool isBlockOutside();
    Grid grid;

private:
    std::vector<Block> blocks;
    Block getRandomBLock();
    std::vector<Block> getBlocks();
    Block currentBlock;
    Block nextBlock;
};