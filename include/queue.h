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



// Used internally.
struct queue_node {
        struct queue_node *next;
        void *data;
};

// The queue itself.
// You must initialise it with `queue_new()`.
typedef struct {
        struct queue_node *head;
        struct queue_node *tail;
        size_t size;
} queue_t;



// Returns an initialised queue. 
// Its return value must be assigned to newly created variables before
// performing any other operations.
extern queue_t  queue_new();


// Returns true, if queue is empty.
extern bool     queue_empty(const queue_t);

// Returns queue size.
extern size_t   queue_size(const queue_t);


// Pushes new element to the queue.
// Returns nonzero value on success.
//
// Please note that it pushes THE POINTER !!!
// Allocating and freeing data is up to the caller.
extern int      queue_push(queue_t *restrict, void*);

// Pops last element from the queue and returns it.
// If empty, returns NULL.
//
// It won't touch the pointer; freeing it is up to the caller.
extern void*    queue_pop(queue_t *restrict);


// Returns first element from the queue.
// If empty, returns NULL.
extern void*    queue_front(const queue_t);



#endif