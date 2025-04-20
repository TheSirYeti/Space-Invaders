#include "Player.h"

#include <iostream>
#include <ostream>
#include <string>

#include "raymath.h"
#include "Bullets/Bullet.h"
#include "Managers/GameManager.h"

Player::Player()
{
    hp = 3;
    Position = V2(GetScreenWidth() / 2, GetScreenHeight() - 80);
    Velocity = V2_ZERO;
    Radius = 15;
    FireRate = 0.5f;
    Speed = 150.f;
    Tint = GREEN;
}

void Player::MoveAndDraw(float x, float y)
{
    Position.x += x * Speed * GetFrameTime();
    Position.y += y * Speed * GetFrameTime();
    
    if(Position.x > GetScreenWidth()) Position.x = GetScreenWidth() - 5;
    if(Position.x < 0) Position.x = 5;

    DrawCircle(Position.x, Position.y, Radius, Tint);
    
    std::string scoreText = "LIVES: " + std::to_string(hp);
    DrawText(scoreText.c_str(), 0, GetScreenHeight() - 35, 24, WHITE);
}

void Player::CheckShootingStatus()
{
    Bullet bullet = Bullet(Position.x, Position.y, V2_UP, Tint);
}

void Player::TakeDamage()
{
    std::cout << "OUCH!" << std::endl;
    hp--;
    
    if(hp <= 0)
        GameManager::instance->EndGame(false);
}


