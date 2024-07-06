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


typedef struct {
        size_t tail, head;
        size_t capacity;
        size_t size;
        void **data;
} deque_t;


deque_t deque_new();

bool deque_empty(deque_t);
size_t deque_size(deque_t);

int deque_resize(deque_t*, size_t);

int deque_push_front(deque_t*, void*);
int deque_push_back(deque_t*, void*);
void *deque_pop_front(deque_t*);
void *deque_pop_back(deque_t*);


void *deque_at(deque_t, size_t at);
void *deque_front(deque_t);
void *deque_back(deque_t);

#endif
