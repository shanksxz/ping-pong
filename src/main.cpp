#include <raylib.h>
// #include "ball.h"
#include "ping.cpp"

int main()
{
    Color darkGreen = Color{20, 160, 133, 255};

    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Ping Pong");
    // Ball ball = Ball();
    // Line line = Line();
    Game game = Game();

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {

        game.updateBall();
        game.updateLine();
        game.displayScore();
        BeginDrawing();
        ClearBackground(darkGreen);
        game.drawBall();
        game.drawLine();
        EndDrawing();
    }


    CloseWindow();
    return 0;
}