#include <math.h>
#include "vector2.h"

Vec2 vec_add(Vec2 a, Vec2 b)
{
    return (Vec2){ a.x + b.x, a.y + b.y };
}

Vec2 vec_sub(Vec2 a, Vec2 b)
{
    return (Vec2){ a.x - b.x, a.y - b.y };
}

Vec2 vec_scale(Vec2 v, float s)
{
    return (Vec2){ v.x * s, v.y * s };
}

float vec_dot(Vec2 a, Vec2 b)
{
    return a.x * b.x + a.y * b.y;
}

float vec_mag(Vec2 v)
{
    return sqrtf(v.x * v.x + v.y * v.y);
}
