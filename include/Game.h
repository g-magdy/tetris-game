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
    bool game_over;
    void RotateBlock();
    void MoveBlockDown();

    int score;
    Music music;
    Sound rotateSound;
    Sound clearSound;
    ~Game();

private:
    Grid grid;
    void MoveBlockLeft();
    void MoveBlockRight();
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