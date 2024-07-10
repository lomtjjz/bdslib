// Example program demonstaring the usage of deque
// Reads integers and prints them in normal order
#include <stdio.h>
#include <stdlib.h>
#include "../include/deque.h"


#define ERROR(Q, str, ...) { \
        fprintf(stderr, str, ##__VA_ARGS__); \
        while (Q.size) free(queue_pop(&S)); \
        exit(1); \
}


char *readel()
{
        char *buf = (char*)malloc(sizeof(buf) * 256);
        if (buf == NULL) return NULL;
        getc(stdin);

        char at = 0;
        char ch = getc(stdin);
        while (ch != EOF && ch != '\n' && at < 256) {
                buf[at++] = ch;
                ch = getc(stdin);
        }
        buf[at] = '\0';
        return buf;
}


int main()
{
        deque_t Q = deque_new();

        while (true) {
                printf("\e[1;1H\e[2J");
                printf("Todo list (%d elements, %d space left):\n", Q.size, Q.capacity-Q.size);

                if (Q.size) printf("\n");
                for (int i = 0; i < Q.size; i++) {
                        printf("%d.  %s\n", i, (char*)deque_at(Q, i));
                }
                printf("\n");

                printf("What would you like to do?:\n");
                printf("A - add task at the top:\n");
                printf("a - add task to the bottom:\n");
                printf("R - remove task from the top:\n");
                printf("r - remove task from the bottom:\n");
                printf("q - quit:\n");
                printf("[A/a/R/r/q]: ");

                char todo = getc(stdin);
                char *el;
                switch (todo) {
                default:
                        printf("Command not recognised!\n");
                        char ch;
                        while (ch != EOF && ch != '\n') ch = getc(stdin);
                        break;
                case EOF:
                        printf("Recieved EOF...\n");
                        return 0;
                case 'A':
                        el = readel();
                        if (el == NULL) {
                                printf("Error getting the new element!");
                                break;
                        }
                        deque_push_back(&Q, (void*)el);
                        break;
                case 'a':
                        el = readel();
                        if (el == NULL) {
                                printf("Error getting the new element!");
                                break;
                        }
                        deque_push_front(&Q, (void*)el);
                        break;
                case 'R':
                        free(deque_pop_back(&Q));
                        break;
                case 'r':
                        free(deque_pop_front(&Q));
                        break;

                case 'q':
                        return 0;
                        break;
                }
        }

        return 0;
}