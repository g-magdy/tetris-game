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
    bool game_over;
    void RotateBlock();
    void MoveBlockLeft();
    void MoveBlockRight();
    void MoveBlockDown();

    int score;

private:
    bool isBlockOutside();
    void lockBlock();
    std::vector<Block> blocks;
    Block getRandomBLock();
    std::vector<Block> getBlocks();
    bool blockFits();
    Block currentBlock;
    Block nextBlock;
    void reset();
    void updateScore(int linesCleared, int moveDownPoints);
};