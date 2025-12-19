#include <iostream>
// #include "game.h"
#include "crosshair.h"
#include "movementInput.h"
#include "playerTriangle.h"

int screenHeight = (float)GetScreenHeight();
int screenWidth = (float)GetScreenWidth();

float startAngle = 0.0f;

bool printDebug = false;

Font debugFont;

struct PlayerTriangleOrigin {
  Vector2 velocity = {0.0, 0.0};
  Vector2 acceleration = {0.0, 0.0};
  Vector2 position = {(float)screenHeight / 2, (float)screenWidth / 2};
};
PlayerTriangleOrigin obj_playerTriangleOrigin;

int main(int argc, char *argv[]) {
  SetTargetFPS(60);
  ToggleBorderlessWindowed();
  std::cout << "\nGAME-INFO: set fps, set window";
  InitWindow(screenWidth, screenHeight, "window");

  debugFont = LoadFont("resources/0xProtoNerdFontMono-Regular.ttf");
  std::cout << GetWorkingDirectory() << std::endl;

  Texture2D playerTexture = LoadTexture("resources/player.png");
  int frameWidth = playerTexture.width;
  int frameHeight = playerTexture.height;

  PlayerTriangle player;
  HideCursor();
  int frameCount = 0;

  std::cout << "\nGAME-INFO: set fps, set window, init window, set player, "
               "hide cursor";

  while (!WindowShouldClose()) {

    ++frameCount;

    player.mousePosition = GetMousePosition();

    checkMovementInput(&player);
    Rectangle sourceRec = {0.0f, 0.0f, (float)frameWidth, (float)frameHeight};
    // Rectangle destRec = {player.p1.x, player.p1.y, 50.0f, 61.0f};
    Vector2 dir = Vector2Subtract(player.p3, player.p2);
    float angle = (atan2f(dir.y, dir.x) * RAD2DEG) + 90;

    player.updatePlayerPos(&player, &screenWidth, &screenHeight, &frameWidth,
                           &frameHeight);
    if (IsKeyPressed(KEY_I)) {
      if (printDebug == false) {
        printDebug = true;
      } else if (printDebug == true) {
        printDebug = false;
      }
    }

    BeginDrawing();
    ClearBackground(BLACK);
    player.DrawPlayer(&playerTexture, &player, &sourceRec, &angle);

    if (printDebug == true) {
      DrawTextEx(debugFont,
                 TextFormat("mouse position: %.2f, %.2f",
                            player.mousePosition.x, player.mousePosition.y),
                 Vector2{10, 0}, 20, 2, GRAY);

      DrawTextEx(
          debugFont,
          TextFormat("player position: %.2f, %.2f", player.p1.x, player.p1.y),
          Vector2{10, 15}, 20, 2, GRAY);

      DrawCircle(player.p1.x, player.p1.y, 3, BLUE);
    }
    {
      // debug rendering
      // DrawCircle(player.p2.x, player.p2.y, 2, GREEN);
      // DrawLine(player.p2.x, player.p2.y, player.p3.x, player.p3.y, BLUE);

      // drawing the rectangle bounds
      // DrawRectangleLines(player.p2.x - 25, player.p2.y, 50, 61, WHITE);
      // DrawRectangleLines(destRec.x, destRec.y, destRec.width, destRec.height,
      // RED);

      if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        DrawCircleV(player.mousePosition, 20, GRAY);
      }
    }

    // DrawCircleV(mousePosition, 10, GREEN);
    DrawCrosshair(&player.mousePosition);

    EndDrawing();
  }
  UnloadTexture(playerTexture);
  CloseWindow();
  return 0;
}
