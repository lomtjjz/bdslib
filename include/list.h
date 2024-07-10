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
#ifndef __LIST_H
#define __LIST_H
#include <stdbool.h>
#include <stddef.h>



struct list_node {
        struct list_node *sentinel;
        struct list_node *prev;
        struct list_node *next;

        void *data;
};

typedef struct {
        struct list_node sentinel;
        size_t size;
} list_t;



extern void list_new(list_t*);


extern bool list_empty(list_t);
extern size_t list_size(list_t);


extern int list_push_front(list_t*, void*);
extern int list_push_back(list_t*, void*);
extern int list_insert(list_t*, void*, size_t);


extern void *list_pop_front(list_t*);
extern void *list_pop_back(list_t*);
extern void *list_erase(list_t*, size_t);


extern void *list_front(list_t);
extern void *list_back(list_t);
extern void *list_at(list_t, size_t);



extern struct list_node *list_sentinel(list_t*);
extern void *list_node_data(struct list_node*);
extern struct list_node *list_node_prev(struct list_node*);
extern struct list_node *list_node_next(struct list_node*);

extern int list_node_insert(struct list_node*, void*);
extern void *list_node_erase(struct list_node*);



#endif