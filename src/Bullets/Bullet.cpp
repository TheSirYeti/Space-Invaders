#include "Bullet.h"

#include <iostream>

void Bullet::MoveAndDraw()
{
    Position.x += Direction.x * Speed * GetFrameTime();
    Position.y += Direction.y * Speed * GetFrameTime();

    Center.x = Position.x + Width / 2;
    Center.y = Position.y + Length / 2;
    
    DrawRectangle(Position.x, Position.y, Width, Length, Tint);
}

Bullet::Bullet(){}

Bullet::Bullet(float posX, float posY, V2 direction, Color color)
{
    IsActive = false;
    
    Position = V2(posX, posY);
    Direction = direction;

    Center.x = Position.x + Width / 2;
    Center.y = Position.y + Length / 2;

    Speed = 250.f;
    Width = 2.f;
    Length = 5.f;
    Tint = color;
}

void Bullet::Initialize(float posX, float posY, V2 direction, Color color)
{
    IsActive = true;
    
    Position = V2(posX, posY);
    Direction = direction;

    Center.x = Position.x + Width / 2;
    Center.y = Position.y + Length / 2;

    Speed = 250.f;
    Width = 2.f;
    Length = 5.f;
    Tint = color;
}


