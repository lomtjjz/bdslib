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
#ifndef __DEQUE_H
#define __DEQUE_H
#include <stdbool.h>
#include <stddef.h>



// The deque itself.
// You must initialise it with `deque_new()`
typedef struct {
        size_t tail, head;
        size_t capacity;
        size_t size;
        void **data;
} deque_t;



// Returns an initialised deque. 
// Its return value must be assigned to newly created variables before
// performing any operations.
extern deque_t deque_new();

// Frees memory occupied by deque.
// You must call it after you have finished interracting with deque.
// You may interact with deque after the call.
extern void deque_free(deque_t *restrict);


// Reallocates new deque container.
// If new size is smaller, trims last elements.
// Returns nonzero value on failure.
extern int deque_resize(deque_t *restrict, size_t);


// Inserts new element at the beginning.
// Returns nonzero value on failure.
//
// Please note that it pushes THE POINTER !!!
// Allocating and freeing data is up to the caller.
extern int deque_push_front(deque_t *restrict, void*);

// Inserts new element at the end.
// Returns nonzero value on failure.
//
// Please note that it pushes THE POINTER !!!
// Allocating and freeing data is up to the caller.
extern int deque_push_back(deque_t *restrict, void*);

// Removes the first element and returns it.
// Returns NULL, if already empty.
//
// It won't touch the pointer; freeing it is up to the caller.
extern void *deque_pop_front(deque_t *restrict);

// Removes the last element and returns it.
// Returns NULL, if already empty.
//
// It won't touch the pointer; freeing it is up to the caller.
extern void *deque_pop_back(deque_t *restrict);


// Returns element at the specified position.
// If deque is too small, returns NULL.
extern void *deque_at(const deque_t, size_t);

// Returns the first element.
// Returns NULL, if empty.
extern void *deque_front(const deque_t);

// Returns the last element.
// Returns NULL, if empty.
extern void *deque_back(const deque_t);


// Same as `deque_at()`, except returns the pointer to where `deque_at()`
// value is stored.
extern void **__deque_at(const deque_t, size_t);


#endif
