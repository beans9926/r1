#pragma once
#include "game.h"

struct PlayerTriangle {
	Vector2 velocity = {0.0, 0.0};
	Vector2 acceleration = {0.0, 0.0};
	Vector2 p1 = {300, 300};
	
	Vector2 mousePosition = GetMousePosition();
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
	
	Rectangle sourceRec;
	Rectangle destRec;


	void updatePlayerPos(PlayerTriangle* player, 
											int *screenWidth, 
											int *screenHeight, 
											int *frameWidth, 
											int *frameHeight);

	void DrawPlayer(Texture2D* playerTexture, 
								 PlayerTriangle* player, 
								 Rectangle* sourceRec, 
								 Rectangle* destRec, 
								 float* angle);
};
