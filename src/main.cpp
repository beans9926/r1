#include <iostream>
// #include "game.h"
#include "crosshair.h"
#include "drawDebugInfo.h"
#include "movementInput.h"
#include "playerTriangle.h"

int screenHeight = (float)GetScreenHeight();
int screenWidth = (float)GetScreenWidth();

float startAngle = 0.0f;

bool printDebug = false;

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
    player.DrawPlayer(&playerTexture, &player, &sourceRec);

    if (printDebug == true) {

      DrawDebugInfo(&player);
    }

    // DrawCircleV(mousePosition, 10, GREEN);
    DrawCrosshair(&player.mousePosition);

    EndDrawing();
  }
  UnloadTexture(playerTexture);
  CloseWindow();
  return 0;
}
