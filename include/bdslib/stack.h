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
#ifndef __STACK_H
#define __STACK_H
#include <stddef.h>



// Used internally.
struct __stack_node {
	struct __stack_node *head;
	void *data;
};

// The stack itself.
// You must initialise it with `stack_new()`.
typedef struct {
	struct __stack_node *head;
	size_t size;
} stack_t;



// Returns an initialised stack. 
// Its return value must be assigned to newly created variables before
// performing any other operations
extern void	stack_new(stack_t *restrict);


// Pushes new element to the stack.
// Returns nonzero value on success.
//
// Please note that it pushes THE POINTER !!!
// Allocating and freeing data is up to the caller.
extern int	stack_push(stack_t *restrict, void*);

// Pops last element from the stack and returns it.
// If empty, returns NULL.
//
// Pops item from the stack and returns it.
// It won't touch the data; freeing it is up to the caller.
// If the stack is empty, returns NULL.
extern void*	stack_pop(stack_t *restrict);


// Returns last element from the stack.
// If empty, returns NULL.
extern void*	stack_top(const stack_t);



#endif