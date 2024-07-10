Header: `queue.h`

# Queue
If you don't know what it is, here is an [article](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) about it.


## Data types


```c
// Used internally
struct queue_node {};


// The queue itself.
// You must initialise it with `queue_new()`.
typedef struct {
        struct queue_node *head;
        struct queue_node *tail;
        size_t size;
} queue_t;
```

## Available functions

### Constructor
* `queue_t queue_new()`
	* Returns an initialised queue. Its return value must be assigned to newly created variables before performing any other operations.


### Size
* `bool queue_empty(queue_t)`
	* Returns true, if queue is empty.
* `size_t queue_size(queue_t)`
	* Returns queue size.


### Insertion & Deletion
* `int queue_push(queue_t*, void*)`
	* Pushes new element to the queue.
	* Returns nonzero value on success
* `void *queue_pop(queue_t*)`
	* Pops last element from the queue and returns it.
	* If empty, returns NULL.


### Access
* `void *queue_front(queue_t)`
	* Returns first element from the queue.
	* If empty, returns NULL.


## Very important information

- The queue stores pointers, not the pointed data. The queue will never try to access the data.
- **Allocating and freeing memory is up to the caller!**


## Example usage

See [examples/normal.c](/examples/normal.c)
