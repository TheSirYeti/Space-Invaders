#include "YetiMath.h"

V2 operator+(V2 a, V2 b) 
{
    V2 result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    return result;
}

V2 operator-(V2 a, V2 b)
{
    V2 result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    return result;
}

V2 operator*(V2 a, float b)
{
    V2 result;
    result.x = a.x * b;
    result.y = a.y * b;
    return result;
}

V2 operator*(float b, V2 a)
{
    return a * b;
}

bool operator==(V2 a, V2 b) 
{
    return((a.x == b.x) && (a.y == b.y));
}


bool operator!=(V2 a, V2 b)
{
    return !(a == b);
}