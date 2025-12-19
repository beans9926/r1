#include "playerTriangle.h"
#include <raylib.h>

void PlayerTriangle::updatePlayerPos(PlayerTriangle *player, int *screenWidth,
                                     int *screenHeight, int *frameWidth,
                                     int *frameHeight) {
  player->p1.x += player->velocity.x;
  player->p1.y += player->velocity.y;

  Vector2 mousePosition = GetMousePosition();
  float dx = mousePosition.x - player->p1.x;
  float dy = mousePosition.y - player->p1.y;
  player->rotation = atan2f(dy, dx) * RAD2DEG + 90.0f;
}

void PlayerTriangle::DrawPlayer(Texture2D *playerTexture,
                                PlayerTriangle *player, Rectangle *sourceRec) {
  Vector2 origin = {25.0f, 30.5f};
  DrawTexturePro(*playerTexture, *sourceRec,
                 Rectangle{player->p1.x, player->p1.y, 50, 61},
                 Vector2{25.0f, 0.0f}, player->rotation, WHITE);
}
