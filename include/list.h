#ifndef __LIST_H
#define __LIST_H
#include <stdbool.h>
#include <stddef.h>



struct list_node {
        struct list_node *prev;
        struct list_node *next;
        void *data;
};

typedef struct {
        struct list_node sentinel;
        size_t size;
} list_t;



extern list_t list_new();


extern bool list_empty(list_t);
extern size_t list_size(list_t);


extern int list_insert(list_t*, void*, size_t);
extern int list_push_front(list_t*, void*);
extern int list_push_back(list_t*, void*);


extern void *list_erase(list_t*, size_t);
extern void *list_pop_front(list_t*);
extern void *list_pop_back(list_t*);


extern void *list_front(list_t);
extern void *list_back(list_t);


extern list_node list_it_begin(list_t);
extern list_node list_it_end(list_t);
extern list_node list_it_prev(list_node);
extern list_node list_it_next(list_node);



#endif