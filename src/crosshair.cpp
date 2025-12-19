#include <raylib.h>

void DrawCrosshair(Vector2 *mousePosition) {
  DrawCircleV(*mousePosition, 1, WHITE);

  DrawLine(mousePosition->x, mousePosition->y - 5, mousePosition->x,
           mousePosition->y - 15, WHITE);
  DrawLine(mousePosition->x - 5, mousePosition->y, mousePosition->x - 15,
           mousePosition->y, WHITE);
  DrawLine(mousePosition->x + 5, mousePosition->y, mousePosition->x + 15,
           mousePosition->y, WHITE);
  DrawLine(mousePosition->x, mousePosition->y + 5, mousePosition->x,
           mousePosition->y + 15, WHITE);
}
