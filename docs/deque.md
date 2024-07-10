Header: `deque.h`

# Deque
If you don't know what it is, here is an [article](https://en.wikipedia.org/wiki/Double-ended_queue) about it.


## Data types


* `deque_t`
  * The deque itself.
  * You must initialise it with `deque_new()`.


## Available functions

### Constructor & Destructor
* `deque_t deque_new()`
  * Returns an initialised deque. Its return value must be assigned to newly created variables before performing any operations.
* `void deque_free(deque_t*)`
  * Frees memory occupied by deque.
  * You must call it after you have finished interracting with deque.
  * You may interact with deque after the call. 


### Size & Capacity
* `bool deque_empty(deque_t)`
  * Returns true, if deque is empty.
* `size_t deque_size(deque_t)`
  * Returns deque size.
* `int deque_resize(deque_t*, size_t)`
  * Reallocates new deque container.
  * If new size is smaller, trims last elements.
  * Returns nonzero value on failure.


### Insertion & Deletion
* `int deque_push_front(deque_t*, void*)`
  * Inserts new element at the beginning.
  * Returns nonzero value on failure.
* `int deque_push_back(deque_t*, void*)`
  * Inserts new element at the end.
  * Returns nonzero value on failure.
* `void *deque_pop_front(deque_t*)`
  * Removes the first element and returns it.
  * If empty, returns NULL.
* `void *deque_pop_back(deque_t*)`
  * Removes the last element and returns it.
  * If empty, returns NULL.


### Access
* `void *deque_at(deque_t, size_t)`
  * Returns element at the specified position.
  * If deque is too small, returns NULL.
* `void *deque_front(deque_t)`
  * Returns the first element.
  * If empty, returns NULL.
* `void *deque_back(deque_t)`
  * Returns the last element.
  * If empty, returns NULL.


### Extra
* `void **__deque_at(deque_t, size_t)`
  * Same as `deque_at()`, except returns the pointer to where `deque_at()`
  value is stored.
  * May be used for swapping values.

## Very important information

- Deque is implemented on dynamic array resulting in `amortized O(1)` complexity.
- Deque stores pointers, not the pointed data. The deque will never try to access the data.
- **Allocating and freeing memory is up to the caller!**


## Example usage

See [examples/todo_deque.c](/examples/todo_deque.c)
