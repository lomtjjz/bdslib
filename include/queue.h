/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>.
*/
#ifndef __QUEUE_H
#define __QUEUE_H
#include <stdbool.h>
#include <stddef.h>


struct queue_node {
        struct queue_node *next;
        void *data;
};

typedef struct {
        struct queue_node *head;
        struct queue_node *tail;
        size_t size;
} queue_t;


extern queue_t queue_new();

extern bool queue_empty(queue_t);
extern size_t queue_size(queue_t);

extern int queue_push(queue_t*, void*);
extern void *queue_pop(queue_t*);
extern void* queue_front(queue_t);

#endif