#include "playerTriangle.h"
#include <raylib.h>

void PlayerTriangle::updatePlayerPos(PlayerTriangle* player, int *screenWidth, int *screenHeight, int *frameWidth, int *frameHeight){
	player->p1.x += player->velocity.x;
	player->p1.y += player->velocity.y;
	
	player->p3 = mousePosition;
	player->len_p1_p3 = sqrt(std::pow((player->p3.x - player->p1.x), 2) + 
											std::pow((player->p3.y - player->p1.y), 2));
	player->k_len_p1_p3 = 50/player->len_p1_p3;
	player->p2 = {
		(player->p1.x + (player->k_len_p1_p3 * (player->p3.x - player->p1.x))),
		(player->p1.y + (player->k_len_p1_p3 * (player->p3.y - player->p1.y)))
	};
	player->deltaX = player->p2.x - player->p1.x;
	player->deltaY = player->p2.y - player->p1.y;

	
	
	Rectangle playerTexRenderBounds = {player->p2.x, player->p2.y, 50, 100};

	Vector2 v0 = { (float)*screenWidth, (float)*screenHeight };
	Vector2 v1Normal = Vector2Normalize(Vector2Subtract(player->p1, v0));
	Vector2 v2Normal = Vector2Normalize(Vector2Subtract(player->p2, v0));

	
	


}

void PlayerTriangle::DrawPlayer(Texture2D* playerTexture, PlayerTriangle* player, Rectangle*sourceRec, Rectangle* destRec ,float* angle){
	DrawTexturePro(*playerTexture, *sourceRec, Rectangle{player->p2.x, player->p2.y, 50, 61}, Vector2{25, 0}, *angle, WHITE);
		

}
