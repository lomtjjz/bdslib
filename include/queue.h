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


// Returns initialised queue. You must assign it to newly created variable 
// before doing anything with it.
extern queue_t  queue_new();

// Returns queue size.
extern size_t   queue_size(queue_t);

// Returns true if queue is empty.
extern bool     queue_empty(queue_t);

// Push new item to the queue. Please note that it pushes THE POINTER
// Allocating and freeing the data is up to the caller.
// Returns 0 on success, 1 on failure.
extern int      queue_push(queue_t*, void*);

// Pops item from the queue and returns it.
// It won't touch the data; freeing it is up to the caller.
// If the queue is empty, returns NULL.
extern void*    queue_pop(queue_t*);

// Returns the front element if there is any.
// Returns NULL otherwise.
extern void*    queue_front(queue_t);

#endif