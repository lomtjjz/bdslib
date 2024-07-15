Header: `cmp.h`

# Comparator

Basically, a function that answers the question "should `a` stand before `b` in a sorted structure"

```c
// Here is how it looks
bool comparator(const void *a, const void *b)
{
	// ...
}

// Shorthand pointer in `<bdslib/cmp.h>`
typedef bool (*cmp_func_t)(const void *a, const void *b);
```


## How to use it

You just pass it to any structure that supports it in `*_new()` function.


## Example usage

See [examples/heapsort.c](/examples/heapsort.c)
