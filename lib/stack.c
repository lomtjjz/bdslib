#include <stdbool.h>
#include <stdlib.h>
#include "stack.h"



stack_t stack_new()
{
	return (stack_t){NULL, NULL, 0};
}

bool stack_empty(const stack_t S)
{
	return S.head == NULL;
}

size_t stack_size(const stack_t S)
{
	return S.size;
}


int stack_push(stack_t *restrict S, void *data)
{
	struct stack_node *new = (struct stack_node*)malloc(sizeof(struct stack_node));
	if (new == NULL) return 1;
	new->data = data;

	if (!stack_empty(*S)) new->head = S->head;
	S->head = new;

	S->size++;
	return 0;
}

void* stack_pop(stack_t *restrict S)
{
	if (stack_empty(*S)) return NULL;

	void *data = S->head->data;

	stack_t *prev = S->head->head;
	free(S->head);
	S->head = prev;
	
	S->size--;
	return data;
}


void *stack_top(const stack_t S) 
{
	if (stack_empty(S)) return NULL;
	else return S.head->data;
}
