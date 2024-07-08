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

// The deque itself. You must initialise it with `deque_new()`
typedef struct {
        size_t tail, head;
        size_t capacity;
        size_t size;
        void **data;
} deque_t;


// Returns an initialised deque.
// Its return value must be assigned to newly created variables before
// performing any other operations.
deque_t deque_new();

// Frees memory occupied by deque.
// You must call it after you have finished interracting with deque.
// You may interact with deque after the call.
void deque_free(deque_t);


// Returns true, if deque is empty.
bool deque_empty(deque_t);

// Returns deque size.
size_t deque_size(deque_t);

// Reallocates new deque container.
// If the new size is smaller, trims last elements.
// Returns nonzero value on failure.
int deque_resize(deque_t*, size_t);


// Inserts new element at the beginning.
// Returns nonzero value on failure
int deque_push_front(deque_t*, void*);

// Inserts new element at the end.
// Returns nonzero value on failure.
int deque_push_back(deque_t*, void*);

// Removes the first element and returns it.
void *deque_pop_front(deque_t*);

// Removes the last element and returns it.
void *deque_pop_back(deque_t*);


// Returns element at the specified position.
// If deque is too small, returns NULL.
void *deque_at(deque_t, size_t at);

// Returns the first element.
// Returns NULL, if empty.
void *deque_front(deque_t);

// Return the last element.
// Returns NULL, if empty.
void *deque_back(deque_t);

#endif
