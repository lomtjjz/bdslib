// Example program demonstaring the usage of queue
// Reads integers and prints them in normal order
#include <stdio.h>
#include <stdlib.h>
#include "../lib/queue.h"


#define ERROR(S, str, ...) { \
        fprintf(stderr, str, ##__VA_ARGS__); \
        while (!queue_empty(S)) free(queue_pop(&S)); \
        exit(1); \
}


int main()
{
        queue_t Q = queue_new();

        int num = 0;
        while (scanf(" %9d", &num) != EOF) {
                // This is a bad practice: stack_push(&S, num);
                // You should allocate the memory instead:
                int *data = (int*)malloc(sizeof(int));
                if (data == NULL) {
                        ERROR(Q, "Can't allocate new memory!\n");
                }

                *data = num;
                if (queue_push(&Q, data)) {
                        free(data);
                        ERROR(Q, "Can't push new item to the queue!\n");
                }

        }

        if (ferror(stdin)) {
                ERROR(Q, "Error reading integer number %zu!\n", queue_size(Q)+1);
        }

        printf("The amount of integers read: %zu\n", queue_size(Q));
        printf("Integers in normal order:\n");
        while (!queue_empty(Q)) {
                int i = *(int*)queue_front(Q);
                printf("%d ", i);
                free(queue_pop(&Q));
        }

        return 0;
}