#ifndef GAME_H
#define GAME_H

#include "vector2.h"
#include "render.h"
#include "config.h"
#include "object_list.h" 

typedef struct {
    Vec2 position;
    Vec2 velocity;
    Vec2 thrust;
} Ship;

/* Tunable gameplay constants */
#define MAX_SPEED  5.0f

void game_init(Ship *ship);
void game_apply_rules(Ship *ship, Vec2 target);

#define CAPTURE_RADIUS 1.0f

int game_reached_target(const Ship *ship, Vec2 target);

void game_enforce_bounds(Ship *ship);

void game_build_corridor(Object **walls);

int game_check_collision(Object *walls, Vec2 new_pos);

void game_move_ship(Ship *ship, Object *walls);

Vec2 field_at(Vec2 pos);


#endif /* GAME_H */
