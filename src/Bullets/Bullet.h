#pragma once
#include "raylib.h"
#include "Math/YetiMath.h"

struct Bullet
{
    V2 Direction;
    V2 Position;
    V2 Center;
    float Width, Length;
    float Speed;
    Color Tint;

    bool IsActive;

    Bullet();
    Bullet(float posX, float posY, V2 direction, Color color);
    void Initialize(float posX, float posY, V2 direction, Color color);
    void MoveAndDraw();
};
