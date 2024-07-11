Header: `stack.h`

# Stack
If you don't know what it is, here is an [article](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) about it.


## Data types

```c
// The stack itself.
// You must initialise it with `stack_new()`.
typedef struct {
	struct stack_node *head;
	void *data;
	size_t size;
} stack_t;
```

## Available functions

### Constructor
* `stack_t stack_new()`
	* Returns an initialised stack. Its return value must be assigned to newly created variables before performing any other operations


### Insertion & Deletion
* `int stack_push(stack_t*, void*)`
	* Pushes new element to the stack.
	* Returns nonzero value on success.
* `void *stack_pop(stack_t*)`
	* Pops last element from the stack and returns it.
	* If empty, returns NULL.


### Access
* `void *stack_top(stack_t)`
	* Returns last element from the stack.
	* If empty, returns NULL.


## Very important information

- The stack stores pointers, not the pointed data. The stack will never try to access the data.
- **Allocating and freeing memory is up to the caller!**


## Example usage

See [examples/reverse.c](/examples/reverse.c)
