#include "playerTriangle.h"
#include "rayImports.h"

void DrawDebugInfo(PlayerTriangle *player) {

  Font debugFont;

  debugFont = LoadFont("resources/0xProtoNerdFontMono-Regular.ttf");
  DrawTextEx(debugFont,
             TextFormat("mouse position: %.2f, %.2f", player->mousePosition.x,
                        player->mousePosition.y),
             Vector2{10, 0}, 20, 2, GRAY);

  DrawTextEx(
      debugFont,
      TextFormat("player position: %.2f, %.2f", player->p1.x, player->p1.y),
      Vector2{10, 15}, 20, 2, GRAY);

  DrawCircle(player->p1.x, player->p1.y, 3, BLUE);
}
