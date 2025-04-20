#include "Player.h"
#include "raymath.h"
#include "Bullets/Bullet.h"

Player::Player()
{
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
}

void Player::Shoot()
{
    Bullet bullet = Bullet(Position.x, Position.y, V2_UP, Tint);
}


