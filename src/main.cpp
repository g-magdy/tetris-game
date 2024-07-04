#include "Grid.h"
#include "BlockTypes.cpp"

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



int main()
{
    InitWindow(screenWidth, screenHeight, "Tetris Game");
    SetTargetFPS(60);

    L_Block test;

    Grid grid;
    grid.print();
    // grid.gridCells[0][1] = 1;
    // grid.gridCells[0][2] = 2;
    // grid.gridCells[0][3] = 3;
    // grid.gridCells[0][4] = 4;

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(darkBlue);
        grid.draw();
        test.draw();
        EndDrawing();
    }
    CloseWindow();
}