// Example program demonstaring the usage of list
// Quicksort implementation
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/list.h"

#define LIST_SIZE       32
#define SLEEP_MILLIS    100000
int data[LIST_SIZE];
list_t L;


void swap(void **A, void **B)
{
        void *tmp = *A;
        *A = *B;
        *B = tmp;
}

bool flag = false;
void printall()
{
        struct list_node *it = list_sentinel(&L);
        printf("\033[F\033[F");
        
        
        if (!flag) printf("[ ] ");
        else printf("[*] ");
        printf("Sorting...\n");
        flag = !flag;


        it = list_node_next(it);
        do {
                printf("%d", *(int*)list_node_data(it));
        } while ((it = list_node_next(it)) != list_sentinel(&L));
        printf("\n");
        usleep(SLEEP_MILLIS);
}

void quicksort(struct list_node *l, struct list_node *r)
{
        if (l == r) return;

        struct list_node *it = l;
        struct list_node *m = l;
        struct list_node *cmp = list_node_prev(r);
        if (cmp == l) return;
        while (it != cmp) {
                int a = *(int*)list_node_data(it);
                int b = *(int*)list_node_data(cmp);

                if (a <= b) {
                        swap(__list_node_data(it), __list_node_data(m));
                        m = list_node_next(m);
                }
                it = list_node_next(it);
        }
        swap(__list_node_data(cmp), __list_node_data(m));
        printall();

        quicksort(l, m);
        quicksort(m, r);
}

int main()
{
        srand(time(NULL));
        list_new(&L);

        for (int i = 0; i < LIST_SIZE; i++) data[i] = rand()%10;
        for (int i = 0; i < LIST_SIZE; i++) list_push_back(&L, data+i);
        printf("\n\n");

        struct list_node *s = list_sentinel(&L);
        quicksort(list_node_next(s), s);
        printall();

        return 0;
}
