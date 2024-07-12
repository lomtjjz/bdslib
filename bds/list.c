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
#include <bdslib/list.h>

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>



void list_new(list_t *L)
{
	L->size = 0;

	L->sentinel.sentinel = &L->sentinel;
	L->sentinel.prev = &L->sentinel;
	L->sentinel.next = &L->sentinel;
	L->sentinel.data = L;
}


static struct list_node *__list_at(list_t *L, size_t at)
{
	if (L->size <= at) return NULL;
	struct list_node *it = &L->sentinel;

	if (at <= L->size/2) {
		at = 0;
		it = it->next;
		while (at--) it = it->next;
	} else {
		at = L->size-at;
		it = it->prev;
		while (at--) it = it->prev;
	}

	return it;
}


int list_push_front(list_t *L, void *data)
{
	return list_node_insert(&L->sentinel, data);
}

int list_push_back(list_t *L, void *data)
{
	return list_node_insert(L->sentinel.prev, data);
}

int list_insert(list_t *L, void *data, size_t at)
{
	if (at > L->size) return 1;

	struct list_node *it = __list_at(L, at);
	if (it == NULL) return 1;
	
	return list_node_insert(it, data);
}


void *list_pop_front(list_t *L)
{
	if (!L->size) return NULL;
	return list_node_erase(L->sentinel.next);
}

void *list_pop_back(list_t *L)
{
	if (!L->size) return NULL;
	return list_node_erase(L->sentinel.prev);
}

void *list_erase(list_t *L, size_t at)
{
	if (at >= L->size) return NULL;

	struct list_node *old = __list_at(L, at);
	if (old == NULL) return NULL;

	return list_node_erase(old);
}


void *list_front(list_t L)
{
	if (!L.size) return NULL;
	return L.sentinel.next->data;
}

void *list_back(list_t L)
{
	if (!L.size) return NULL;
	return L.sentinel.prev->data;
}

void *list_at(list_t L, size_t at)
{
	if (L.size >= at) return NULL;
	struct list_node *it = __list_at(&L, at);
	if (it == NULL) return NULL;

	return it->data;
}
