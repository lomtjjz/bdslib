#include <bdslib/pqueue.h>
#include <bdslib/macros.h>


void pqueue_new(pqueue_t *restrict Q, cmp_func_t cmp)
{
	deque_new(&Q->heap);
	Q->cmp = cmp;
}

size_t pqueue_size(const pqueue_t Q)
{
	return Q.heap.size;
}

static bool fix(cmp_func_t cmp, void **child, void **parent)
{
	bool chck = cmp(*child, *parent);
	if (chck) swap(*child, *parent);
	return chck;
}

int pqueue_push(pqueue_t *restrict Q, void *data)
{
	if (deque_push_back(&Q->heap, data)) return 1;

	size_t at = Q->heap.size-1;
	while (at) {
		fix(
			Q->cmp,
			__deque_at(Q->heap, at),
			__deque_at(Q->heap, (at-1)/2)
		);
		at = (at-1)/2;
	}

	return 0;
}

void* pqueue_pop(pqueue_t *restrict Q)
{
	if (!Q->heap.size) return NULL;
	void **a = __deque_at(Q->heap, 0);
	void **b = __deque_at(Q->heap, Q->heap.size-1);
	swap(*a, *b);
	
	void *out = deque_pop_back(&Q->heap);
	size_t at = 0;
	while (true) {
		void **v = __deque_at(Q->heap, at);

		if (2*at + 1 >= Q->heap.size) break;
		a = __deque_at(Q->heap, 2*at + 1);

		if (2*at + 2 < Q->heap.size) {
			b = __deque_at(Q->heap, 2*at + 2);
			if (!Q->cmp(*a, *b)) swap(a, b);
		}
		
		if (__deque_at(Q->heap, 2*at + 1) == a) at = 2*at + 1;
		else at = 2*at + 2;

		if (!fix(Q->cmp, a, v)) break;
	}
	return out;
}

void* pqueue_first(const pqueue_t Q)
{
	return deque_front(Q.heap);
}