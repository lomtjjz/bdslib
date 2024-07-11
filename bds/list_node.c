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


int list_node_insert(struct list_node *node, void *data)
{
	struct list_node *new = (struct list_node*)malloc(sizeof(struct list_node));
	if (new == NULL) return 1;
	__link(node, new);
	
	new->sentinel = node->sentinel;
	new->data = data;

	((list_t*)node->sentinel->data)->size++;
	return 0;
}

void *list_node_erase(struct list_node *node)
{
	if (node == node->sentinel) return NULL;

	((list_t*)node->sentinel->data)->size--;
	return __unlink(node);
}
