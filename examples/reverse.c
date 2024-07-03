// Example program demonstaring the usage of stack
// Reads integers and prints them in reverse
#include <stdio.h>
#include <stdlib.h>
#include "../lib/stack.h"


#define ERROR(S, str, ...) { \
        fprintf(stderr, str, ##__VA_ARGS__); \
        while (!stack_empty(S)) free(stack_pop(&S)); \
        exit(1); \
}


int main()
{
        stack_t S = stack_new();

        int num = 0;
        while (scanf(" %9d", &num) != EOF) {
                // This is a bad practice: stack_push(&S, num);
                // You should allocate the memory instead:
                int *data = (int*)malloc(sizeof(int));
                if (data == NULL) {
                        ERROR(S, "Can't allocate new memory!\n");
                }

                *data = num;
                if (stack_push(&S, data)) {
                        free(data);
                        ERROR(S, "Can't push new item to the stack!\n");
                }

        }

        if (ferror(stdin)) {
                ERROR(S, "Error reading integer number %zu!\n", stack_size(S)+1);
        }

        printf("The amount of integers read: %zu\n", stack_size(S));
        
        printf("Integers in reverse:\n");
        while (!stack_empty(S)) {
                int i = *(int*)stack_top(S);
                printf("%d ", i);
                free(stack_pop(&S));
        }

        return 0;
}