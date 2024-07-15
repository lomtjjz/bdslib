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
#ifndef __PRIORITY_QUEUE_H
#define __PRIORITY_QUEUE_H
#include <stddef.h>
#include <bdslib/deque.h>
#include <bdslib/cmp.h>



// The priority queue itself.
// You must initialise it with `pqueue_new()`.
typedef struct {
	deque_t heap;
	cmp_func_t cmp;
} pqueue_t;



// Initialises the priority queue. 
// Must be used against newly created variables before performing any
// operations.
extern void	pqueue_new(pqueue_t *restrict, cmp_func_t);

// Returns the size of priority queue.
// Shorthand for `Q.heap.size`.
extern size_t	pqueue_size(const pqueue_t Q);


// Pushes new element to the priority queue.
// Returns nonzero value on success.
//
// Please note that it pushes THE POINTER !!!
// Allocating and freeing data is up to the caller.
extern int	pqueue_push(pqueue_t *restrict, void*);

// Pops last element from the priority queue and returns it.
// If empty, returns NULL.
//
// It won't touch the pointer; freeing it is up to the caller.
extern void*	pqueue_pop(pqueue_t *restrict);


// Returns first element from the priority queue.
// If empty, returns NULL.
extern void*	pqueue_first(const pqueue_t Q);


#endif