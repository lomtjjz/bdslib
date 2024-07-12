// Example program demonstaring the usage of queue
// Reads integers and prints them in normal order
#include <bdslib/queue.h>

#include <stdlib.h>
#include <stdio.h>


#define ERROR(Q, str, ...) { \
        fprintf(stderr, str, ##__VA_ARGS__); \
        while (Q.size) free(queue_pop(&Q)); \
        exit(1); \
}


int main()
{
        queue_t Q;
        queue_new(&Q);

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
                ERROR(Q, "Error reading integer number %zu!\n", Q.size+1);
        }

        printf("The amount of integers read: %zu\n", Q.size);
        printf("Integers in normal order: ");
        while (Q.size) {
                int i = *(int*)queue_front(Q);
                printf("%d ", i);
                free(queue_pop(&Q));
        }

        printf("\n");
        return 0;
}