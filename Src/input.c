#include <raylib.h>
#include "input.h"
#include "config.h"
#include "vector2.h"

Vec2 input_get_thrust(void)
{
    Vec2 t = {0.0f, 0.0f};

    if (IsKeyDown(KEY_W)) t.y -= THRUST_MAG;
    if (IsKeyDown(KEY_S)) t.y += THRUST_MAG;
    if (IsKeyDown(KEY_A)) t.x -= THRUST_MAG;
    if (IsKeyDown(KEY_D)) t.x += THRUST_MAG;

    // BOOST: if shift is held, double the thrust
    if (IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT))
        t = vec_scale(t, 4.0f);

    return t;
}
