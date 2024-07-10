Header: `list.h`

# List
If you don't know what it is, here is an [article](https://en.wikipedia.org/wiki/List_(abstract_data_type)) about it.


## Data types

```c
// List node.
// You may encounter it if you try iterating the list.
struct list_node {
        struct list_node *sentinel;
        struct list_node *prev;
        struct list_node *next;

        void *data;
};

// The list itself.
// You must initialise it with `list_new()`.
typedef struct {
        struct list_node sentinel;
        size_t size;
} list_t;
```

* `list_t`
	* The list itself.
	* You must initialise it with `list_new()`.
* `struct list_node`
	* List node.
	* You may encounter it if you try iterating the list.


## Available functions

### Constructor
* `void list_new(list_t*)`
	* Initialises the list. Must be used against newly created variables before performing any operations.


### Insertion
* `int list_push_front(list_t*, void*)`
	* Inserts new element at the beginning.
	* Returns nonzero value on failure.
* `int list_push_back(list_t*, void*)`
	* Inserts new element at the end.
	* Returns nonzero value on failure.
* `int list_insert(list_t*, void*, size_t)`
	* Inserts new element at specified index.
	* Returns nonzero value on failure.


### Deletion
* `void *list_pop_front(list_t*)`
	* Removes the first element and returns it.
	* If empty, returns NULL.
* `void *list_pop_back(list_t*)`
	* Removes the last element and returns it.
	* If empty, returns NULL.
* `void *list_erase(list_t*, size_t)`
	* Removes the element at specified position and returns it.
	* If list is too small, returns NULL.


### Access
* `void *list_at(list_t*, size_t)`
	* Returns the element at the specified position.
	* If list is too small, returns NULL.
* `void *list_front(list_t)`
	* Returns the first element.
	* If empty, returns NULL.
	* Shortcut for `L.sentinel->next->data`
* `void *list_back(list_t)`
	* Returns the last element.
	* If empty, returns NULL.
	* Shortcut for `L.sentinel->prev->data`


### List nodes
* `int list_node_insert(struct list_node*, void*)`
	* Inserts a new node after the provided node.
	* Returns nonzero value on failure.
* `void* list_node_erase(struct list_node*);`
	* Removes the node and returns its value.
	* Returns NULL if provided node is a sentinel node.


## Very important information

- List is implemented using *doubly-linked list* resulting in at most `N/2` iterations (which is still `O(N)`).
- List stores pointers, not the pointed data. The list will never try to access the data.
- **Allocating and freeing memory is up to the caller!**


## Example usage

See [examples/perf_test.c](/examples/perf_test.c)


### How to iterate through a list
```c
struct list_node *it = list_sentinel(&L);
do {
	// ...iterate in normal order
} while ((it = list_next(L)) != list_sentinel(L));
```

```c
struct list_node *it = list_sentinel(&L);
do {
	// ...iterate in reverse order
} while ((it = list_prev(L)) != list_sentinel(L));
```
