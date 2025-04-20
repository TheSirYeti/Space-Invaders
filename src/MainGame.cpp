#include <algorithm>
#include <iostream>

#include "raylib.h"
#include "Math/YetiMath.h"
#include "./Ships/Player.h"
#include "Bullets/BulletPool.h"
#include "Managers/AlienManager.h"

const int ScreenWidth = 640;
const int ScreenHeight = 480;

int main ()
{
	InitWindow(ScreenWidth, ScreenHeight, "YETI INVADERS");

	Player player = Player();
	BulletPool bulletPool = BulletPool(250);
	AlienManager alienManager = AlienManager(25, 5);
	alienManager.InitializeAliens();
	
	while (true)
	{
		BeginDrawing();

		ClearBackground(BLACK);
		
		V2 inputs = V2_ZERO;
		inputs.x = IsKeyDown(KEY_D) ? 1 : IsKeyDown(KEY_A) ? -1 : 0;
		//inputs.y = IsKeyDown(KEY_S) ? 1 : IsKeyDown(KEY_W) ? -1 : 0;
	
		player.MoveAndDraw(inputs.x, 0);

		if(IsKeyPressed(KEY_SPACE))
		{
			bulletPool.ActivateBullet(player.GetPosition(), V2_UP, player.GetTint());
		}

		bulletPool.UpdateBullets();
		alienManager.UpdateAliens();
		alienManager.CheckForCollisions(&bulletPool);
		
		EndDrawing();
	}
}