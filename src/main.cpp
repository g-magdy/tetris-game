#include "Game.h"

const Color darkBlue = {44, 44, 127, 255};
const Color lightBlue = {59, 85, 162, 255};
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
double interval = 0.8;
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
    InitWindow(screenWidth + 200 , screenHeight + 20, "Tetris Game");
    SetTargetFPS(60);

    Game game;

    while (!WindowShouldClose())
    {
        // update positions
        game.handleInput();
        UpdateMusicStream(game.music);

        if (eventTriggered())
            game.MoveBlockDown();

        BeginDrawing();
        ClearBackground(darkBlue);

        DrawText("Score", 350, 15, 38, WHITE);
        DrawRectangleRounded(Rectangle{320, 55, 170, 60}, 0.3, 6, lightBlue);
        int textDims = MeasureText(TextFormat("%i", game.score), 38);
        DrawText(TextFormat("%i", game.score), 320 + (170 - textDims)/2, 65, 38, WHITE);

        if (game.game_over)
        {
            DrawRectangleRounded(Rectangle{320, 440, 170, 170}, 0.3, 6, lightBlue);
            DrawText("GAME OVER", 330, 480, 26, WHITE);
            DrawText("Press ENTER", 330, 520, 22, WHITE);
            DrawText("To Play Again", 330, 545, 22, WHITE);
        }

        DrawText("Next", 360, 175, 38, WHITE);
        DrawRectangleRounded(Rectangle{320, 215, 170, 180}, 0.3, 6, lightBlue);

        game.draw();

        // if (IsKeyPressed(KEY_R))
        //     test.rotationalState = (test.rotationalState + 1) % 4;
        EndDrawing();
    }
    CloseWindow();
}