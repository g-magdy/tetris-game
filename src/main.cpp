#include "Game.h"

const Color darkBlue = {44, 44, 127, 255};
const Color darkGrey = {26, 31, 40, 255};
const Color green = {47, 230, 23, 255};
const Color red = {232, 18, 18, 255};
const Color orange = {226, 116, 17, 255};
const Color yellow = {237, 234, 4, 255};
const Color purple = {166, 0, 247, 255};
const Color cyan = {21, 204, 209, 255};
const Color blue = {13, 64, 216, 255};

const std::vector<Color> colorsArray = {darkGrey, green, red, orange, yellow, purple, cyan, blue};

const int screenWidth = 300;
const int screenHeight = 600;
const int rowCount = 20;
const int columnCount = 10;
const int cellDimension = 30;

double lastUpdate = 0;
double interval = 0.03;
bool eventTriggered()
{
    double curr = GetTime();
    if (curr - lastUpdate > interval)
    {
        lastUpdate = curr;
        return true;
    }
    return false;
}

int main()
{
    srand(time(0));
    InitWindow(screenWidth, screenHeight, "Tetris Game");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {
        // update positions
        game.handleInput();

        if (eventTriggered())
            game.MoveBlockDown();

        BeginDrawing();
        ClearBackground(darkBlue);

        game.draw();

        // if (IsKeyPressed(KEY_R))
        //     test.rotationalState = (test.rotationalState + 1) % 4;
        EndDrawing();
    }
    CloseWindow();
}