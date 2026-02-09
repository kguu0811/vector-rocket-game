#ifndef OBJECT_LIST_H
#define OBJECT_LIST_H

#include "vector2.h"

/* Generic world object */
typedef struct Object {
    Vec2 pos;
    char symbol;
    struct Object *next;
} Object;

/* Object list operations */
Object* obj_create(Vec2 pos, char symbol);
void    obj_append(Object **head, Object *obj);
int     obj_count(Object *head);
void    obj_destroy_all(Object *head);

#endif /* OBJECT_LIST_H */
