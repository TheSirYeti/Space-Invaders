#pragma once
#include "Math/YetiMath.h"
#include "raylib.h"

class Ship
{
protected:
    V2 Position;
    V2 Velocity;
    V2 Center;
    float Radius;
    float FireRate;
    float Speed;
    Color Tint;

public:
    Ship(){}
    ~Ship(){}
    
    V2 GetPosition(){ return Position; }
    V2 GetVelocity(){ return Velocity; }
    float GetRadius(){ return Radius; }
    float GetFireRate(){ return FireRate; }
    Color GetTint(){ return Tint; }

    void SetPosition(V2 vector){ Position = vector; }
    void SetPosition(Vector2 vector)
    {
        Position.x = vector.x;
        Position.y = vector.y;
    }
    
    void SetVelocity(V2 vector){ Velocity = vector; }
    void SetVelocity(Vector2 vector)
    {
        Velocity.x = vector.x;
        Velocity.y = vector.y;
    }
    
    void SetRadius(float radius){ Radius = radius; }
    void SetFireRate(float rate){ FireRate = rate; }
    void SetTint(Color color){ Tint = color; }

    virtual void MoveAndDraw(float x, float y);
    virtual void CheckShootingStatus();
    virtual void TakeDamage();
};
