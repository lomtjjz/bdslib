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
#include <bdslib/stack.h>

#include <stdlib.h>
#include <stddef.h>



void stack_new(stack_t *S)
{
	S->head = NULL;
	S->size = 0;
}


int stack_push(stack_t *restrict S, void *data)
{
	struct __stack_node *new = (struct __stack_node*)malloc(sizeof(struct __stack_node));
	if (new == NULL) return 1;
	new->data = data;

	if (S->size) new->head = S->head;
	S->head = new;

	S->size++;
	return 0;
}

void* stack_pop(stack_t *restrict S)
{
	if (!S->size) return NULL;

	void *data = S->head->data;

	struct __stack_node *prev = S->head->head;
	free(S->head);
	S->head = prev;
	
	S->size--;
	return data;
}


void *stack_top(const stack_t S) 
{
	if (!S.size) return NULL;
	else return S.head->data;
}
