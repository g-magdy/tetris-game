#include "Game.h"

Game::Game()
{
    blocks = getBlocks();
    currentBlock = getRandomBLock();
    nextBlock = getRandomBLock();
}

Block Game::getRandomBLock()
{
    if (blocks.empty())
    {
        // refill
        blocks = getBlocks();
    }

    // semi random: each block appears at least once befor reappearing
    int random_index = rand() % blocks.size();
    Block random_block = blocks[random_index];
    blocks.erase(blocks.begin() + random_index);
    return random_block;
}

std::vector<Block> Game::getBlocks()
{
    return {I_Block(), J_Block(), L_Block(), O_Block(), S_Block(), T_Block(), Z_Block()};   
}

void Game::draw()
{
    grid.draw();
    currentBlock.draw();
}

void Game::handleInput()
{
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_DOWN:
        MoveBlockDown();
        break;

    case KEY_LEFT:
        MoveBlockLeft();
        break;

    case KEY_RIGHT:
        MoveBlockRight();
        break;

    default:
        break;
    }
}

void Game::MoveBlockLeft()
{
    currentBlock.move(0, -1);
    if (isBlockOutside())
        currentBlock.move(0, 1);
}
void Game::MoveBlockRight()
{
    currentBlock.move(0, 1);
    if (isBlockOutside())
        currentBlock.move(0, -1);
}

void Game::MoveBlockDown()
{
    currentBlock.move(1, 0);
    if (isBlockOutside())
        currentBlock.move(-1, 0);
}

bool Game::isBlockOutside()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for (auto tile : tiles)
    {
        if (grid.isCellOutside(tile.row, tile.column))
            return true;
    }
    return false;
}