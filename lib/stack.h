#ifndef __STACK_H
#define __STACK_H
#include <stdbool.h>
#include <stddef.h>


typedef struct stack_node {
    struct stack_node *head;
    void *data;
    size_t size;
} stack_t;


// Returns initialised stack. You must assign it to newly created variable 
// before doing anything with it.
extern stack_t  stack_new();

// Returns stack size.
extern size_t   stack_size(const stack_t);

// Returns true if stack is empty.
extern bool     stack_empty(const stack_t);

// Push new item to the stack. Please note that it pushes THE POINTER
// Allocating and freeing the data is up to the caller.
// Returns 0 on success, 1 on failure.
extern int      stack_push(stack_t *restrict, void*);

// Pops item from the stack and returns it.
// It won't touch the data; freeing it is up to the caller.
// If the stack is empty, returns NULL.
extern void*    stack_pop(stack_t *restrict);

// Returns the top element if there is any.
// Returns NULL otherwise.
extern void*    stack_top(const stack_t);


#endif