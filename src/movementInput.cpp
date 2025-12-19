#include "playerTriangle.h"
#include "rayImports.h"

void checkMovementInput(PlayerTriangle *player) {
  if (IsKeyDown(KEY_W)) {
    player->velocity.y -= player->acceleration.y;
    if (player->acceleration.y < 0.15) {
      player->acceleration.y += 0.01;
    }
  }
  if (IsKeyReleased(KEY_W)) {
    player->acceleration.y = 0.01;
  }

  if (IsKeyDown(KEY_S)) {
    player->velocity.y += player->acceleration.y;
    if (player->acceleration.y < 0.15) {
      player->acceleration.y += 0.01;
    }
  }
  if (IsKeyReleased(KEY_S)) {
    player->acceleration.y = 0.01;
  }

  if (IsKeyDown(KEY_A)) {
    player->velocity.x -= player->acceleration.x;
    if (player->acceleration.x < 0.15) {
      player->acceleration.x += 0.01;
    }
  }
  if (IsKeyReleased(KEY_A)) {
    player->acceleration.x = 0.01;
  }

  if (IsKeyDown(KEY_D)) {
    player->velocity.x += player->acceleration.x;
    if (player->acceleration.x < 0.15) {
      player->acceleration.x += 0.01;
    }
  }
  if (IsKeyReleased(KEY_D)) {
    player->acceleration.x = 0.01;
  }
}
