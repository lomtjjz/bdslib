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



// List node.
// You may encounter it if you try iterating the list.
struct list_node {
	struct list_node *sentinel;
	struct list_node *prev;
	struct list_node *next;

	void *data;
};

// The list itself.
// You must initialise it with `list_new()`.
typedef struct {
	struct list_node sentinel;
	size_t size;
} list_t;



// Initialises the list. 
// Must be used against newly created variables before performing any
// operations.
extern void	list_new(list_t *restrict);


// Inserts new element at the beginning.
// Returns nonzero value on failure.
extern int	list_push_front(list_t *restrict, void*);

// Inserts new element at the end.
// Returns nonzero value on failure.
extern int	list_push_back(list_t *restrict, void*);

// Inserts new element at specified index.
// Returns nonzero value on failure.
extern int	list_insert(list_t *restrict, void*, size_t);;

// Removes the first element and returns it.
// If empty, returns NULL.
extern void*	list_pop_front(list_t *restrict);

// Removes the last element and returns it.
// If empty, returns NULL.
extern void*	list_pop_back(list_t *restrict);

// Removes the element at specified position and returns it.
// If list is too small, returns NULL.
extern void*	list_erase(list_t *restrict, size_t);


// Returns the element at the specified position.
// If list is too small, returns NULL.
extern void*	list_at(const list_t, size_t);

// Returns the first element.
// If empty, returns NULL.
extern void*	list_front(const list_t);

// Returns the last element.
// If empty, returns NULL.
extern void*	list_back(const list_t);


// Inserts a new node after the provided node.
// Returns nonzero value on failure.
extern int	list_node_insert(struct list_node *restrict, void*);

// Removes the node and returns its value.
// Returns NULL if provided node is a sentinel node.
extern void*	list_node_erase(struct list_node *restrict);

// Same as `list_node_data()`, except returns the pointer to where
// `list_node_data()` value is stored.
extern void**	__list_node_data(struct list_node *restrict);



#endif
