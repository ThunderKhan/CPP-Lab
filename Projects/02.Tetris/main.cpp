#include <raylib.h>
#include "game.h"
#include "Colors.h"
#include <iostream>

double lastUpdateTime{};

bool EventTriggered(double interval) {
    double currentTime = GetTime();

    if (currentTime - lastUpdateTime >= interval) {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

bool RestartButton(Rectangle r, Font font) {
    Vector2 mouse = GetMousePosition();

    bool hover = CheckCollisionPointRec(mouse, r);
    bool click = hover && IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    DrawRectangleRounded(r, 0.3f, 6, hover ? GRAY : lightBlue);

    const char* text = "Restart";
    float fontSize = 20;
    Vector2 size = MeasureTextEx(font, text, fontSize, 2);

    DrawTextEx(
        font,
        text,
        { r.x + (r.width - size.x) / 2, r.y + (r.height - size.y) / 2 },
        fontSize,
        2,
        WHITE
    );

    return click;
}

int main() {

    InitWindow(500, 620, "Tetris");

    Image icon = LoadImage("tetris.jpg");
    SetWindowIcon(icon);
    UnloadImage(icon);

    SetTargetFPS(60);

    Font font = LoadFontEx("PixelOperator8-Bold.ttf", 64, 0, 0);

    Game game;

    while(!WindowShouldClose()) {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(0.2)) {
            game.MoveBlockDown();
        }

        BeginDrawing();
        ClearBackground(darkBlue);
        DrawTextEx(font, "Score", {345, 15}, 24, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 24, 2, WHITE);
        
        if (game.gameOver) {
            DrawTextEx(font, "GAME OVER", {320, 450}, 18, 2, WHITE);
            
            if (RestartButton({ 320, 500, 170, 40 }, font)) {
                game.Restart();
            }
        }

        DrawRectangleRounded({320, 55, 170, 60}, 0.3, 6, lightBlue);
        
        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 24, 2);

        DrawTextEx(font, scoreText, {320 + (170 - textSize.x) / 2, 75}, 24, 2, WHITE);
        DrawRectangleRounded({320, 215, 170, 180}, 0.3, 6, lightBlue);
        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}