#include "physics.h"

/*
 * Euler integration:
 *   drag   = DRAG * vel
 *   accel  = thrust - drag
 *   vel    = vel + accel * dt
 *   pos    = pos + vel * dt
 */
void physics_update(Vec2 *vel, Vec2 thrust, float dt)
{
    /* drag = DRAG * vel */
    Vec2 drag = vec_scale(*vel, DRAG);

    /* accel = thrust - drag */
    Vec2 accel = vec_sub(thrust, drag);

    /* vel = vel + accel * dt */
    *vel = vec_add(*vel, vec_scale(accel, dt));
}
