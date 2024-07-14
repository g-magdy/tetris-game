#include "Game.h"

Game::Game()
{
    score = 0;
    game_over = false;
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

bool Game::blockFits()
{
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for (Position p : tiles)
    {
        if (!grid.isCellEmpty(p.row, p.column))
            return false;
    }
    return true;
}

void Game::reset()
{
    score = 0;
    grid.initialize();
    blocks = getBlocks();
    currentBlock = getRandomBLock();
    nextBlock = getRandomBLock();
}

void Game::updateScore(int linesCleared, int moveDownPoints)
{
    switch (linesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += moveDownPoints;
}

void Game::draw()
{
    grid.draw();
    currentBlock.draw(11, 11);
    
    // I block
    if (nextBlock.id == 3)
        nextBlock.draw(255, 290);
    // O block
    else if (nextBlock.id == 4)
        nextBlock.draw(255, 280);
    // all other blocks
    else
        nextBlock.draw(270, 270);

}

void Game::handleInput()
{
    if (IsKeyPressed(KEY_UP))
        RotateBlock();
    else if (IsKeyPressed(KEY_DOWN))
        MoveBlockDown();
    else if (IsKeyPressed(KEY_LEFT))
        MoveBlockLeft();
    else if (IsKeyPressed(KEY_RIGHT))
        MoveBlockRight();
    else if (game_over && IsKeyPressed(KEY_ENTER))
    {
        game_over = false;
        reset();
    }
}

void Game::RotateBlock()
{
    if (game_over == false)
    {
        currentBlock.rotate();
        if (isBlockOutside())
            currentBlock.undoRotation();
    }
}

void Game::MoveBlockLeft()
{
    if (game_over == false)
    {
        currentBlock.move(0, -1);
        if (isBlockOutside() || blockFits() == false)
            currentBlock.move(0, 1);
    }
}
void Game::MoveBlockRight()
{
    if (game_over == false)
    {
        currentBlock.move(0, 1);
        if (isBlockOutside() || blockFits() == false)
            currentBlock.move(0, -1);
    }
}

void Game::MoveBlockDown()
{
    if (game_over == false)
    {
        currentBlock.move(1, 0);
        if (isBlockOutside() || blockFits() == false)
        {
            currentBlock.move(-1, 0);
            lockBlock();
        }
        updateScore(0, 1);
    }
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

void Game::lockBlock()
{
    int clr = currentBlock.id;
    std::vector<Position> tiles = currentBlock.getCellPositions();
    for (Position item : tiles)
    {
        grid.gridCells[item.row][item.column] = clr;
    }

    currentBlock = nextBlock;

    if (blockFits() == false)
        game_over = true;

    nextBlock = getRandomBLock();

    int rows = grid.handleCompletedRows();
    updateScore(rows, 0);
}
