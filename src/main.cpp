#include <iostream>
#include <cmath>
#include "game.h"

int screenHeight = (float) GetScreenHeight();
int screenWidth = (float) GetScreenWidth();

Vector2 mousePosition = {0, 0};
Vector2 v0 = { (float)screenWidth, (float)screenHeight };

float startAngle = 0.0f;

struct PlayerTriangleOrigin{
	Vector2 velocity = {0.0, 0.0};
	Vector2 acceleration = {0.0, 0.0};
	Vector2 position = {(float) screenHeight/2, (float) screenWidth/2};
};
PlayerTriangleOrigin obj_playerTriangleOrigin;

struct PlayerTriangle {
	Vector2 velocity = {0.0, 0.0};
	Vector2 acceleration = {0.0, 0.0};
	Vector2 p1 = {300, 300};
	Vector2 p3 = mousePosition; 
	float len_p1_p3 = sqrt(std::pow((p3.x - p1.x), 2) + 
												std::pow((p3.y - p1.y), 2));
	float k_len_p1_p3 = 50 / len_p1_p3;

	Vector2 p2 = {
		(p1.x + (k_len_p1_p3 * (p3.x - p1.x))),
		(p1.y + (k_len_p1_p3 * (p3.y - p1.y)))
	};

	float deltaX = p2.x - p1.x;
	float deltaY = p2.y - p1.y;

};


void checkMovementInput(PlayerTriangle* player){
	if(IsKeyDown(KEY_W)){
			player->velocity.y -= player->acceleration.y;
			if(player->acceleration.y < 0.15){player->acceleration.y += 0.01;}
		}
		if(IsKeyReleased(KEY_W)){player->acceleration.y = 0.01;}

		if(IsKeyDown(KEY_S)){
			player->velocity.y += player->acceleration.y;
			if(player->acceleration.y < 0.15){player->acceleration.y += 0.01;}
		}
		if(IsKeyReleased(KEY_S)){player->acceleration.y = 0.01;}

		if(IsKeyDown(KEY_A)){
			player->velocity.x -= player->acceleration.x;
			if(player->acceleration.x < 0.15){player->acceleration.x += 0.01;}
		}
		if(IsKeyReleased(KEY_A)){player->acceleration.x = 0.01;}
		
		if(IsKeyDown(KEY_D)){
			player->velocity.x += player->acceleration.x;
			if(player->acceleration.x < 0.15){player->acceleration.x += 0.01;}
		}
		if(IsKeyReleased(KEY_D)){player->acceleration.x = 0.01;}

}


int main(int argc, char* argv[]){
	SetTargetFPS(60);
	ToggleBorderlessWindowed();
	std::cout << "\nGAME-INFO: set fps, set window";
	InitWindow(screenWidth, screenHeight, "window");

	Texture2D playerTexture = LoadTexture("resources/player.png");
	int frameWidth = playerTexture.width;
	int frameHeight = playerTexture.height;

	
	PlayerTriangle player;
	HideCursor();
	int frameCount = 0;

	std::cout << "\nGAME-INFO: set fps, set window, init window, set player, hide cursor";

	while(!WindowShouldClose()){
	
		++frameCount;

		mousePosition = GetMousePosition();
		
		checkMovementInput(&player);
				
		player.p1.x += player.velocity.x;
		player.p1.y += player.velocity.y;
		
		player.p3 = mousePosition;
		player.len_p1_p3 = sqrt(std::pow((player.p3.x - player.p1.x), 2) + 
												std::pow((player.p3.y - player.p1.y), 2));
		player.k_len_p1_p3 = 50/player.len_p1_p3;
		player.p2 = {
			(player.p1.x + (player.k_len_p1_p3 * (player.p3.x - player.p1.x))),
			(player.p1.y + (player.k_len_p1_p3 * (player.p3.y - player.p1.y)))
		};
		player.deltaX = player.p2.x - player.p1.x;
		player.deltaY = player.p2.y - player.p1.y;

		
		
		Rectangle playerTexRenderBounds = {player.p2.x, player.p2.y, 50, 100};

		Vector2 v1Normal = Vector2Normalize(Vector2Subtract(player.p1, v0));
		Vector2 v2Normal = Vector2Normalize(Vector2Subtract(player.p2, v0));

		Vector2 dir = Vector2Subtract(player.p3, player.p2);
		float angle = (atan2f(dir.y, dir.x) * RAD2DEG) + 90;

		
		Rectangle sourceRec = {0.0f, 0.0f, (float)frameWidth, (float)frameHeight};
		Rectangle destRec = {player.p2.x - 25, player.p2.y, 50, 61};

		BeginDrawing();
		ClearBackground(BLACK);
		
		DrawTexturePro(playerTexture, sourceRec, Rectangle{player.p2.x, player.p2.y, 50, 61}, Vector2{25, 0}, angle, WHITE);
		
		{
			//debug rendering
			//DrawCircle(player.p2.x, player.p2.y, 2, GREEN);
			//DrawLine(player.p2.x, player.p2.y, player.p3.x, player.p3.y, BLUE);
			
			//drawing the rectangle bounds
			//DrawRectangleLines(player.p2.x - 25, player.p2.y, 50, 61, WHITE);
			//DrawRectangleLines(destRec.x, destRec.y, destRec.width, destRec.height, RED);
			
			if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
				DrawCircleV(mousePosition, 20, GRAY);
			}
		}
		
		//DrawCircleV(mousePosition, 10, GREEN);
		DrawCrosshair(mousePosition);


		EndDrawing();
	}
	UnloadTexture(playerTexture);
	CloseWindow();
	return 0;
}
