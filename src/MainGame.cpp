#include <algorithm>
#include <iostream>

#include "raylib.h"
#include "Math/YetiMath.h"
#include "./Ships/Player.h"
#include "Bullets/BulletPool.h"
#include "Managers/AlienManager.h"
#include "Managers/GameManager.h"

const int ScreenWidth = 640;
const int ScreenHeight = 480;

int main ()
{
	InitWindow(ScreenWidth, ScreenHeight, "YETI INVADERS");

	bool startGame = false;
	while (!startGame)
	{
		ClearBackground(BLACK);

		const char* text = "YETI INVADERS";
		int fontSize = 50;
			
		int textWidth = MeasureText(text, fontSize);
		int textHeight = fontSize;
			
		int x = (GetScreenWidth()  - textWidth )/2;
		int y = ((GetScreenHeight() / 2) - textHeight)/2;
			
		DrawText(text, x, y, fontSize, WHITE);

		text = "START";
		fontSize = 25;
			
		textWidth = MeasureText(text, fontSize);
		textHeight = fontSize;
			
		x = (GetScreenWidth()  - textWidth )/2;
		y = ((GetScreenHeight()) + textHeight)/2;

		DrawText(text, x, y, fontSize, WHITE);

		Rectangle startRect = Rectangle();
		startRect.x = x;
		startRect.y = y;
		startRect.width = textWidth;
		startRect.height = textHeight;
		
		if(CheckCollisionCircleRec(GetMousePosition(), 5, startRect) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
			startGame = true;


		
		EndDrawing();
	}
	
	Player player = Player();
	BulletPool bulletPool = BulletPool(250);
	AlienManager alienManager = AlienManager(25, 5);
	GameManager gameManager = GameManager();
	alienManager.InitializeAliens();
	
	while (!GameManager::instance->gameOver)
	{
		BeginDrawing();

		ClearBackground(BLACK);
		
		V2 inputs = V2_ZERO;
		inputs.x = IsKeyDown(KEY_D) ? 1 : IsKeyDown(KEY_A) ? -1 : 0;
	
		player.MoveAndDraw(inputs.x, 0);

		if(IsKeyPressed(KEY_SPACE))
		{
			bulletPool.ActivateBullet(player.GetPosition(), V2_UP, player.GetTint());
		}

		GameManager::instance->Update();
		
		bulletPool.UpdateBullets();
		alienManager.UpdateAliens();
		alienManager.CheckForAlienCollisions(&bulletPool);
		alienManager.CheckForPlayerCollisions(&player);
		
		EndDrawing();
	}

	if(GameManager::instance->hasWon)
	{
		while(!WindowShouldClose())
		{
			BeginDrawing();

			ClearBackground(BLACK);

			const char *text = "YOU WON!";
			int fontSize = 50;
			
			int textWidth = MeasureText(text, fontSize);
			int textHeight = fontSize;
			
			int x = (GetScreenWidth()  - textWidth )/2;
			int y = (GetScreenHeight() - textHeight)/2;
			
			DrawText(text, x, y, fontSize, WHITE);

			EndDrawing();
		}
	}
	else
	{
		while(!WindowShouldClose())
		{
			BeginDrawing();

			ClearBackground(BLACK);

			const char *text = "YOU LOST...";
			int fontSize = 50;
			
			int textWidth = MeasureText(text, fontSize);
			int textHeight = fontSize;
			
			int x = (GetScreenWidth()  - textWidth )/2;
			int y = (GetScreenHeight() - textHeight)/2;
			
			DrawText(text, x, y, fontSize, WHITE);

			EndDrawing();
		}
	}
}