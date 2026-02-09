#include <stdio.h>
#include "game.h"

#define BLOCK_WIDTH   6
#define BLOCK_HEIGHT  30

/* Initialise ship state */
void game_init(Ship *ship)
{
    ship->position = (Vec2){0.0f, 0.0f};
    ship->velocity = (Vec2){0.0f, 0.0f};
    ship->thrust   = (Vec2){0.0f, 0.0f};
}

/*
 * Applies high-level game rules based on motion interpretation.
 * No physics updates here.
 */
void game_apply_rules(Ship *ship, Vec2 target)
{
    /* ---- Speed check ---- */
    float speed = vec_mag(ship->velocity);

    if (speed > MAX_SPEED) {
        printf("WARNING: Speed too high (%.2f)\n", speed);
    }
}

int game_reached_target(const Ship *ship, Vec2 target)
{
    Vec2 to_target = vec_sub(target, ship->position);
    return vec_mag(to_target) < CAPTURE_RADIUS;
}

void game_enforce_bounds(Ship *ship)
{
    /* X bounds */
    if (ship->position.x < WORLD_MIN_X) {
        ship->position.x = WORLD_MIN_X;
        ship->velocity.x = 0.0f;
    }
    else if (ship->position.x > WORLD_MAX_X) {
        ship->position.x = WORLD_MAX_X;
        ship->velocity.x = 0.0f;
    }

    /* Y bounds */
    if (ship->position.y < WORLD_MIN_Y) {
        ship->position.y = WORLD_MIN_Y;
        ship->velocity.y = 0.0f;
    }
    else if (ship->position.y > WORLD_MAX_Y) {
        ship->position.y = WORLD_MAX_Y;
        ship->velocity.y = 0.0f;
    }
}

void game_build_corridor(Object **walls)
{
    int block_x0 = WIDTH / 2 - BLOCK_WIDTH / 2;
    int block_y0 = 1;   // just under the top border
    
    /* Top protruding block */

    for (int y = 0; y < BLOCK_HEIGHT; y++) {
        for (int x = 0; x < BLOCK_WIDTH; x++) {

            int wx = block_x0 + x;
            int wy = block_y0 + y;

            Vec2 p = { (float)wx, (float)wy };
            obj_append(walls, obj_create(p, '#'));
        }
    }
}

int game_check_collision(Object *walls, Vec2 new_pos)
{
    int nx = (int)new_pos.x;
    int ny = (int)new_pos.y;

    Object *cur = walls;
    while (cur) {
        int wx = (int)cur->pos.x;
        int wy = (int)cur->pos.y;

        if (nx == wx && ny == wy) {
            return 1;  // collision
        }

        cur = cur->next;
    }

    return 0;  // no collision
}

void game_move_ship(Ship *ship, Object *walls)
{
    Vec2 new_pos = vec_add(ship->position,
                           vec_scale(ship->velocity, DT));

    if (!game_check_collision(walls, new_pos)) {
        ship->position = new_pos;
    } else {
        // Simple collision response: stop velocity
        ship->velocity.x = 0.0f;
        ship->velocity.y = 0.0f;
    }
}

Vec2 field_at(Vec2 pos)
{
    (void)pos;  // ignore input for now, optional for more advanced fields
    return (Vec2){ 0.2f, 0.05f }; // small drift per second
}