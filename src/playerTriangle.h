#pragma once
// #include "game.h"
#include "rayImports.h"

struct PlayerTriangle {
  Vector2 velocity = {0.0, 0.0};
  Vector2 acceleration = {0.0, 0.0};
  Vector2 p1 = {300, 300};
  Vector2 mousePosition = GetMousePosition();
  Rectangle sourceRec;
  float rotation;

  void updatePlayerPos(PlayerTriangle *player, int *screenWidth,
                       int *screenHeight, int *frameWidth, int *frameHeight);

  void DrawPlayer(Texture2D *playerTexture, PlayerTriangle *player,
                  Rectangle *sourceRec);
};
