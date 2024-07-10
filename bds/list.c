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
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/list.h"

// ---
// List node

struct list_node *list_sentinel(list_t *L)
{
        return &L->sentinel;
}

void *list_node_data(struct list_node *node)
{
        return node->data;
}

struct list_node *list_node_prev(struct list_node *node)
{
        return node->prev;
}

struct list_node *list_node_next(struct list_node *node)
{
        return node->next;
}


int list_node_insert(struct list_node *node, void *data)
{
        struct list_node *new = (struct list_node*)malloc(sizeof(struct list_node));
        if (new == NULL) return 1;
        __link(node, new);
        new->data = new;
        
        return 0;
}

void *list_node_erase(struct list_node *node)
{
        __unlink(node);

        void *old = node->data;
        free(node);
        return old;
}
// ---


void list_new(list_t *L)
{
        L->size = 0;
        L->sentinel.data = 0;
        L->sentinel.prev = &L->sentinel;
        L->sentinel.next = &L->sentinel;
}

bool list_empty(list_t L)
{
        return L.size == 0;
}

size_t list_size(list_t L)
{
        return L.size;
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

static void __link(struct list_node *at, struct list_node *node)
{
        node->prev = at;
        node->next = at->next;

        node->prev->next = node;
        node->next->prev = node;
}

static void *__unlink(struct list_node *node)
{
        node->next->prev = node->prev;
        node->prev->next = node->next;

        void *data = node->data;
        free(node);
        return data;
}


int list_push_front(list_t *L, void *data)
{
        return list_node_insert(&L->sentinel, data);
        struct list_node *new = (struct list_node*)malloc(sizeof(struct list_node));
        if (new == NULL) return 1;

        __link(&L->sentinel, new);
        new->data = data;
        L->size++;
}

int list_push_back(list_t *L, void *data)
{
        struct list_node *new = (struct list_node*)malloc(sizeof(struct list_node));
        if (new == NULL) return 1;

        __link(L->sentinel.prev, new);
        new->data = data;
        L->size++;
}

int list_insert(list_t *L, void *data, size_t at)
{
        if (at > L->size) return 1;

        struct list_node *it = __list_at(L, at);
        if (it == NULL) return 1;

        struct list_node *new = (struct list_node*)malloc(sizeof(struct list_node));
        if (new == NULL) return 1;

        __link(it, new);
        new->data = data;
        return 0;
}


void *list_pop_front(list_t *L)
{
        if (list_empty(*L)) return NULL;
        return __unlink(L->sentinel.next);
}

void *list_pop_back(list_t *L)
{
        if (list_empty(*L)) return NULL;
        return __unlink(L->sentinel.prev);
}

void *list_erase(list_t *L, size_t at)
{
        if (at >= L->size) return NULL;

        struct list_node *old = __list_at(L, at);
        if (old == NULL) return NULL;

        return __unlink(old);
}

void *list_front(list_t L)
{
        if (list_empty(L)) return NULL;
        return L.sentinel.next->data;
}

void *list_back(list_t L)
{
        if (list_empty(L)) return NULL;
        return L.sentinel.prev->data;
}

void *list_at(list_t L, size_t at)
{
        if (L.size >= at) return NULL;
        struct list_node *it = __list_at(&L, at);
        if (it == NULL) return NULL;

        return it->data;
}


