#ifndef VECTOR2_H
#define VECTOR2_H

typedef struct {
    float x;
    float y;
} Vec2;

/* Vector operations */
Vec2  vec_add(Vec2 a, Vec2 b);
Vec2  vec_sub(Vec2 a, Vec2 b);
Vec2  vec_scale(Vec2 v, float s);
float vec_dot(Vec2 a, Vec2 b);
float vec_mag(Vec2 v);

#endif /* VECTOR2_H */
