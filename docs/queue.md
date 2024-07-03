Header: `queue.h`

# Queue
If you don't know what it is, here is an [article](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) about it.

## Data types

* `queue_t`
  * The queue itself.
* `struct queue_node`
  * Used internally, you will never see it.

## Available functions

* `queue_t queue_new()`
  * Returns an initialised queue. Its return value must be assigned to newly created variables before performing any other operations
* `bool queue_empty(stack_t)`
  * Returns true, if queue is empty.
* `size_t queue_size(stack_t)`
  * Returns stack size.
* `int queue_push(stack_t*, void*)`
  * Pushes new element to the queue.
  * Returns nonzero value on success
* `void *queue_pop(stack_t*)`
  * Pops last element from the queue and returns it.
  * If empty, returns NULL.
* `void *queue_front(stack_t)`
  * Returns last element from the queue.
  * If empty, returns NULL.

## Very important information

- The queue stores pointers, not the pointed data. The queue will never try to access the data
- **Allocating and freeing memory is up to the caller!**


## Example usage

See [examples/normal.c](/examples/normal.c)
