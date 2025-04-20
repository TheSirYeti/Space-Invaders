#pragma once
#include <corecrt_startup.h>

#include "math.h"
#include "raylib.h"

#define V2_ZERO V2(0, 0)
#define V2_RIGHT V2(1, 0)
#define V2_LEFT V2(-1, 0)
#define V2_UP V2(0, -1)
#define V2_DOWN V2(0, 1)

struct V2 
{
public:
    float x;
    float y;

    V2(){}
    V2(float x, float y) {
        this->x = x;
        this->y = y;
    }

    float Length()
    {
        return sqrtf((x*x) + (y*y));
    };

    static float Length(V2 a)
    {
        return a.Length();
    }

    static Vector2 CastToVector2(V2 a)
    {
        Vector2 result;
        result.x = a.x;
        result.y = a.y;
        return result;
    }
};

V2 operator+(V2 a, V2 b);

V2 operator-(V2 a, V2 b);

V2 operator*(V2 a, float b);

V2 operator*(float b, V2 a);

bool operator==(V2 a, V2 b);

bool operator!=(V2 a, V2 b);