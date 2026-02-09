#include <stdlib.h>
#include "object_list.h"

Object* obj_create(Vec2 pos, char symbol)
{
    Object *obj = malloc(sizeof(Object));
    if (!obj) {
        return NULL;
    }

    obj->pos = pos;
    obj->symbol   = symbol;
    obj->next     = NULL;

    return obj;
}

void obj_append(Object **head, Object *obj)
{
    if (!obj) return;

    if (*head == NULL) {
        *head = obj;
        return;
    }

    Object *curr = *head;
    while (curr->next) {
        curr = curr->next;
    }

    curr->next = obj;
}

int obj_count(Object *head)
{
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

void obj_destroy_all(Object *head)
{
    while (head) {
        Object *next = head->next;
        free(head);
        head = next;
    }
}
