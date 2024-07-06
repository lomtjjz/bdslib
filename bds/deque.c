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
#include "../include/deque.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>


deque_t deque_new()
{
        return (deque_t){0, 0, 0, 0, NULL};
}

void deque_free(deque_t *Q)
{
        free(Q->data);
        *Q = deque_new();
}

bool deque_empty(deque_t Q)
{
        return Q.size == 0;
}

size_t deque_size(deque_t Q)
{
        return Q.size;
}


int deque_resize(deque_t *Q, size_t size)
{
        if (size == Q->size) return 0;
        if (size == 0) {
                deque_free(Q);
                return 0;
        }

        void** new = (void**)malloc(sizeof(void*)*size);
        if (new == NULL) return 1;

        if (Q->capacity != 0) {
                size_t mn = min(Q->size, size);
                for (size_t i = 0; i < mn; i++) {
                        new[i] = Q->data[(i + Q->tail) % Q->capacity];
                }
                free(Q->data);
                Q->tail = 0;
                Q->head = Q->size;
        }
        Q->capacity = size;
        Q->data = new;
        return 0;
}


static size_t __next_size(deque_t Q)
{
        // The actual length of size_t is platform-dependent, thus we cannot
        // use __builtin_clzX(). One solution might be just converting
        // the capacity to `long`, but I don't like that either as it would not
        // compile on 16bit machines.
        if (Q.capacity == 0) return 1;

        int lg2 = 0;
        while (Q.capacity >= ((size_t)1<<lg2)) lg2++;
        return (size_t)1<<lg2;
}

int deque_push_front(deque_t *Q, void *data)
{
        if (deque_size(*Q) == Q->capacity) {
                if (deque_resize(Q, __next_size(*Q))) return 1;
        }

        Q->data[Q->head] = data;
        Q->head = (Q->head + 1) % Q->capacity;

        Q->size++;
        return 0;
}


int deque_push_back(deque_t *Q, void *data)
{
        if (deque_size(*Q) == Q->capacity) {
                if (deque_resize(Q, __next_size(*Q))) return 1;
        }

        Q->tail = (Q->tail - 1 + Q->capacity) % Q->capacity;
        Q->data[Q->tail] = data;

        Q->size++;
        return 0;
}


void *deque_pop_front(deque_t *Q)
{
        if (deque_empty(*Q)) return NULL;

        Q->head = (Q->head - 1 + Q->capacity) % Q->capacity;

        Q->size--;
        return Q->data[Q->head];
}

void *deque_pop_back(deque_t *Q)
{
        if (deque_empty(*Q)) return NULL;

        void *old = Q->data[Q->tail];
        Q->tail = (Q->tail + 1) % Q->capacity;

        Q->size--;
        return old;
}

void *deque_at(deque_t Q, size_t at)
{
        if (at >= Q.capacity) return NULL;
        return Q.data[(Q.tail + at) % Q.capacity];
}

void *deque_front(deque_t Q)
{
        if (deque_empty(Q)) return NULL;
        return Q.data[Q.head-1];
}

void *deque_back(deque_t Q)
{
        if (deque_empty(Q)) return NULL;
        return Q.data[Q.tail];
}
