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
        struct list_node *it = &L.sentinel;
        printf("\033[F\033[F");
        
        
        if (!flag) printf("[ ] ");
        else printf("[*] ");
        printf("Sorting...\n");
        flag = !flag;


        it = it->next;
        do {
                printf("%d", *(int*)it->data);
        } while ((it = it->next) != &L.sentinel);
        printf("\n");
        usleep(SLEEP_MILLIS);
}

void quicksort(struct list_node *l, struct list_node *r)
{
        if (l == r) return;

        struct list_node *it = l;
        struct list_node *m = l;
        struct list_node *cmp = r->prev;

        if (cmp == l) return;
        while (it != cmp) {
                int a = *(int*)it->data;
                int b = *(int*)cmp->data;

                if (a <= b) {
                        swap(&it->data, &m->data);
                        m = m->next;
                }
                it = it->next;
        }
        swap(&cmp->data, &m->data);
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

        struct list_node *s = &L.sentinel;
        quicksort(s->next, s);
        printall();

        return 0;
}
