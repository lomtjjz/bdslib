// Example program demonstaring the usage of priority queue
// Heapsort implementation (using heap from <bdslib/pqueue.h>)
#include <bdslib/pqueue.h>

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>


#define DATA_SIZE       16
int data[DATA_SIZE];
pqueue_t Q;

bool comparator(const void *a, const void *b)
{
	int l = *(int*)a;
	int r = *(int*)b;
	return l < r;
}


int main()
{
        srand(time(NULL));
        pqueue_new(&Q, comparator);

        for (int i = 0; i < DATA_SIZE; i++) data[i] = rand()%10;

	printf("Randomly generated digit sequence:\n");
	for (int i = 0; i < DATA_SIZE; i++) printf("%d ", data[i]);
	printf("\n\n");

	for (int i = 0; i < DATA_SIZE; i++) {
		if (pqueue_push(&Q, &data[i])) {
			printf("Error pushing to the queue!");
			return 1;
		}
	}

	printf("Heap contents:\n");
	for (int i = 0; i < DATA_SIZE; i++) {
		int *v = (int*)deque_at(Q.heap, i);
		if (v == NULL) {
			printf("Oh shit!");
			return 1;
		}
		printf("%d ", *v);
	}
	printf("\n\n");

	printf("That same sequence sorted using priority queue:\n");
        while (pqueue_size(Q)) {
		printf("%d ", *(int*)pqueue_pop(&Q));
	}
	printf("\n");
        return 0;
}