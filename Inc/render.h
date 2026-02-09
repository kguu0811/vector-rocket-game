#ifndef RENDER_H
#define RENDER_H

#include "vector2.h"
#include "config.h"
#include "object_list.h" 

void render_init(void);
void render_shutdown(void);

void render_begin_frame(void);
void render_end_frame(void);

void render_draw_ship(Vec2 pos, Vec2 vel);
void render_draw_wall(Vec2 pos);
void render_draw_goal(Vec2 pos);

#endif /* RENDER_H */
