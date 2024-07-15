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
#include <bdslib/deque.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>


void deque_new(deque_t *restrict Q)
{
	Q->capacity = 0;
	Q->size = 0;

	Q->head = 0;
	Q->tail = 0;
	Q->data = NULL;
}

void deque_free(deque_t *restrict Q)
{
	free(Q->data);
	deque_new(Q);
}


int deque_resize(deque_t *restrict Q, size_t size)
{
	if (size == Q->size) return 0;
	if (size == 0) {
		deque_free(Q);
		return 0;
	}

	void** new = (void**)malloc(sizeof(void*)*size);
	if (new == NULL) return 1;

	if (Q->capacity != 0) {
		size_t mn = (Q->size < size ? Q->size : size);
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


static size_t __next_size(const deque_t Q)
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

int deque_push_front(deque_t *restrict Q, void *data)
{
	if (Q->size == Q->capacity) {
		if (deque_resize(Q, __next_size(*Q))) return 1;
	}

	Q->tail = (Q->tail - 1 + Q->capacity) % Q->capacity;
	Q->data[Q->tail] = data;

	Q->size++;
	return 0;
}

int deque_push_back(deque_t *restrict Q, void *data)
{
	if (Q->size == Q->capacity) {
		if (deque_resize(Q, __next_size(*Q))) return 1;
	}

	Q->data[Q->head] = data;
	Q->head = (Q->head + 1) % Q->capacity;

	Q->size++;
	return 0;
}


void *deque_pop_front(deque_t *restrict Q)
{
	if (!Q->size) return NULL;

	void *old = Q->data[Q->tail];
	Q->tail = (Q->tail + 1) % Q->capacity;

	Q->size--;
	return old;
}

void *deque_pop_back(deque_t *restrict Q)
{
	if (!Q->size) return NULL;

	Q->head = (Q->head - 1 + Q->capacity) % Q->capacity;

	Q->size--;
	return Q->data[Q->head];
}


void **__deque_at(const deque_t Q, size_t at)
{
	if (at >= Q.size) return NULL;
	return &Q.data[(Q.tail + at) % Q.capacity];
}

void *deque_at(const deque_t Q, size_t at)
{
	return *__deque_at(Q, at);
}

void *deque_front(const deque_t Q)
{
	if (!Q.size) return NULL;
	return Q.data[Q.tail];
}

void *deque_back(const deque_t Q)
{
	if (!Q.size) return NULL;
	return Q.data[(Q.head - 1 + Q.capacity) % Q.capacity];
}
