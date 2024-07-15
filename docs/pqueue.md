Header: `pqueue.h`

# Priority queue
If you don't know what it is, here is an [article](https://en.wikipedia.org/wiki/Priority_queue) about it.


## Data types


```c
// The queue itself.
// You must initialise it with `pqueue_new()`.
typedef struct {
	deque_t heap;
	cmp_func_t cmp;
} pqueue_t;
```
PS: you might be interested in how [deque_t](/docs/deque.md) and [cmp_func_t](/docs/cmp.md) are defined


## Available functions

### Constructor
* `void pqueue_new(pqueue_t*)`
	* Initialises the queue. Must be used against newly created variables before performing any operations.


### Size
* `size_t pqueue_size(pqueue_t)`
	* Returns queue size.
	* Shorthand for `Q.heap.size`.


### Insertion & Deletion
* `int pqueue_push(pqueue_t*, void*)`
	* Pushes new element to the queue.
	* Returns nonzero value on success
* `void *pqueue_pop(pqueue_t*)`
	* Pops last element from the queue and returns it.
	* If empty, returns NULL.


### Access
* `void *pqueue_front(pqueue_t)`
	* Returns first element from the queue.
	* If empty, returns NULL.


## Very important information

- Priority queue is implemented on binary heap resulting in `O(logn)` complexity for insertion/deletion and `O(1)` complexity for retrieving the first element.
- The queue stores pointers, not the pointed data. The queue will never try to access the data.
- **Allocating and freeing memory is up to the caller!**


## Example usage

See [examples/heapsort.c](/examples/heapsort.c)
