#include "AlienShip.h"

AlienShip::~AlienShip()
{
    
}

void AlienShip::Shoot()
{
    
}

AlienShip::AlienShip()
{
    IsAlive = true;
    Position = V2(-100, -100);
    Velocity = V2_ZERO;
    Radius = 15;
    FireRate = 2.f;
    Speed = 50.f;
    Tint = RED;
}

AlienShip::AlienShip(V2 position)
{
    IsAlive = true;
    Position = position;
    Velocity = V2_ZERO;
    Radius = 15;
    FireRate = 2.f;
    Speed = 50.f;
    Tint = RED;
}

void AlienShip::MoveAndDraw(float x, float y)
{
    if(x != 0)
        Position.x =+ (x * Speed * GetFrameTime()) + movementOffset;
    if(y != 0)
        Position.y =+ (y * Speed * GetFrameTime()) + movementOffset;

    DrawCircle(Position.x, Position.y, Radius, Tint);
}

