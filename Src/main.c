#include <stdio.h>
#include <unistd.h>

#include "vector2.h"
#include "physics.h"
#include "game.h"
#include "render.h"
#include "input.h"
#include "object_list.h" 
#include <raylib.h>



#define DT           0.2f

Object *walls = NULL;
Object *exit_obj  = NULL;


int main(void)
{
    Ship ship;
    Vec2 target = {
        WIDTH - 10.0f,
        HEIGHT - 38.0f
    };

    game_init(&ship);
    ship.position = (Vec2){5.0f, 5.0f};

    game_build_corridor(&walls);

    render_init();

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        /* 1. Input */
        ship.thrust = input_get_thrust();

        /* 2. Physics */
        physics_update(&ship.velocity,ship.thrust,dt);

        /* --- COLLISION / RULES --- */
        if (game_reached_target(&ship, target))
        {
            printf("\n===========================\n");
            printf(" TARGET REACHED! 🚀\n");
            printf(" Final position: (%.2f, %.2f)\n",
                   ship.position.x, ship.position.y);
            printf("===========================\n\n");
            break;
        }

        /* 3. Game rules */
        game_apply_rules(&ship, target);
        game_move_ship(&ship, walls);
        game_enforce_bounds(&ship);

        /* 4. Render */
        render_begin_frame();

        for (Object *w = walls; w; w = w->next)
            render_draw_wall(w->pos);

        render_draw_goal(target);
        render_draw_ship(ship.position, ship.velocity);

        render_end_frame();
    }

render_shutdown();


    return 0;
}
