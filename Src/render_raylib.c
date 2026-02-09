#include "render.h"
#include <raylib.h>
#include <math.h>

static Texture2D rocket_tex;
static Vector2 rocket_origin;


// Size of one world unit (cell) in pixels
#define TILE_SIZE 32
#define SHIP_SCALE 0.1f   // 10x smaller


// Window size derived from world size
#define WINDOW_WIDTH  (WIDTH  * TILE_SIZE)
#define WINDOW_HEIGHT (HEIGHT * TILE_SIZE)

static Vector2 world_to_screen(Vec2 p)
{
    return (Vector2){
        p.x * TILE_SIZE + TILE_SIZE * 0.5f,
        p.y * TILE_SIZE + TILE_SIZE * 0.5f
    };
}

void render_init(void)
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Vector Navigation");
    SetTargetFPS(60);

    rocket_tex = LoadTexture("assets/rocket.png");

    rocket_origin = (Vector2){
        rocket_tex.width  * 0.5f,
        rocket_tex.height * 0.5f
    };
}


void render_shutdown(void)
{
    UnloadTexture(rocket_tex);
    CloseWindow();
}


void render_begin_frame(void)
{
    BeginDrawing();
    ClearBackground(BLACK);
}

void render_end_frame(void)
{
    EndDrawing();
}

void render_draw_ship(Vec2 pos, Vec2 vel)
{

    Vector2 screen = {
        pos.x * TILE_SIZE,
        pos.y * TILE_SIZE
    };

    float angle = 0.0f;

    if (fabsf(vel.x) > 0.001f || fabsf(vel.y) > 0.001f)
    {
        angle = atan2f(vel.y, vel.x) * RAD2DEG;
        angle += 90.0f;   // sprite faces up by default
    }

    Rectangle src = {
        0, 0,
        (float)rocket_tex.width,
        (float)rocket_tex.height
    };

    float scale = SHIP_SCALE;

    Rectangle dst = {
        screen.x,
        screen.y,
        rocket_tex.width  * scale,
        rocket_tex.height * scale
    };

    Vector2 origin = {
        (rocket_tex.width  * scale) / 2.0f,
        (rocket_tex.height * scale) / 2.0f
    };


    DrawTexturePro(rocket_tex, src, dst, origin, angle, WHITE);
}


void render_draw_wall(Vec2 pos)
{
    Vector2 s = world_to_screen(pos);

    DrawRectangle(
        (int)(s.x - TILE_SIZE * 0.5f),
        (int)(s.y - TILE_SIZE * 0.5f),
        TILE_SIZE,
        TILE_SIZE,
        GRAY
    );
}

void render_draw_goal(Vec2 pos)
{
    Vector2 s = world_to_screen(pos);

    DrawRectangleLines(
        (int)(s.x - TILE_SIZE * 0.5f),
        (int)(s.y - TILE_SIZE * 0.5f),
        TILE_SIZE,
        TILE_SIZE,
        GREEN
    );
}
