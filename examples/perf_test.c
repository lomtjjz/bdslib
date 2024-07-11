// Example program demonstaring the usage of list and deque
// Measures the efficiency of different data structures
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "../include/deque.h"
#include "../include/list.h"

#define DATA_SIZE (10000000)
#define RAND_SIZE (10000)


#define to_millis(x) (1e3 * (x).tv_sec + 1e-6 * (x).tv_nsec)
#define MEASURE(str, ...) { \
        struct timespec begin, end; \
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &begin); \
        \
        __VA_ARGS__ \
        \
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end); \
        printf(str, to_millis(end) - to_millis(begin)); \
}

void swap(void **A, void **B)
{
        void *tmp = *A;
        *A = *B;
        *B = tmp;
}

int main()
{
        srand(time(NULL));
        printf("list and deque performance compared\n\n");

        deque_t Q;
        list_t L;
        deque_new(&Q);
        list_new(&L);


        printf("Add %d elements:\n", DATA_SIZE);
        MEASURE("  * list: %lf ms\n", {
                for (int i = 0; i < DATA_SIZE; i++) list_push_back(&L, NULL);
        });

        MEASURE("  * deque: %lf ms\n", {
                for (int i = 0; i < DATA_SIZE; i++) deque_push_back(&Q, NULL);
        });

        deque_free(&Q);
        MEASURE("  * deque (preallocated): %lf ms\n", {
                if (deque_resize(&Q, DATA_SIZE)) {
                        printf("Error resizing deque!\n");
                        return 1;
                }
                for (int i = 0; i < DATA_SIZE; i++) deque_push_back(&Q, NULL);
        });
        printf("\n");



        printf("Delete %d elements:\n", DATA_SIZE);
        MEASURE("  * list: %lf ms\n", {
                while (L.size) list_pop_back(&L);
        });

        MEASURE("  * deque: %lf ms\n", {
                while (Q.size) deque_pop_back(&Q);
        });
        printf("\n\n");


        printf("Add %d elements (in random order):\n", RAND_SIZE);
        MEASURE("  * list: %lf ms\n", {
                list_push_back(&L, NULL);
                for (int i = 1; i < RAND_SIZE; i++) {
                        if (list_insert(&L, NULL, rand()%L.size)) {
                                printf("Error inserting!\n");
                                return 1;
                        }
                }
        });
        MEASURE("  * deque: %lf ms\n", {
                deque_push_back(&Q, NULL);
                for (int i = 1; i < RAND_SIZE; i++) {
                        int at = rand()%Q.size;
                        if (deque_push_back(&Q, NULL)) {
                                printf("Error pushing new element!\n");
                                return 1;
                        };
                        for (int j = Q.size-1; j > at; j--) {
                                swap(__deque_at(Q, j-1), __deque_at(Q, j));
                        }
                }
        });
        printf("\n");

        printf("Remove %d elements (in random order)\n", RAND_SIZE);
        MEASURE("  * list: %lf ms\n", {
                while (L.size) list_erase(&L, rand()%L.size);
        });
        MEASURE("  * deque: %lf ms\n", {
                while (Q.size) {
                        for (int i = rand()%Q.size+1; i < Q.size; i++) {
                                swap(__deque_at(Q, i-1), __deque_at(Q, i));
                        }
                        deque_pop_back(&Q);
                }
        });

        return 0;
}