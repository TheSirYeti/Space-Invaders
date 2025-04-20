#include "AlienShip.h"

AlienShip::~AlienShip()
{
    
}

void AlienShip::CheckShootingStatus()
{
    currentFireRate -= FireRate * GetFrameTime();
}

AlienShip::AlienShip()
{
    IsAlive = true;
    Position = V2(-100, -100);
    currentFireRate = FireRate + GetRandomValue(0, maxRandInterval);
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
    currentFireRate = FireRate + GetRandomValue(0, 15);
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

void AlienShip::TakeDamage()
{
    IsAlive = false;
    SetPosition(V2(-100, -100));
    
    GameManager::instance->AddScore(100);
}


