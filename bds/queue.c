/*
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>.
*/
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/queue.h"


queue_t queue_new()
{
        return (queue_t){NULL, 0};
}

bool queue_empty(const queue_t Q)
{
        return Q.size == 0;
}

size_t queue_size(const queue_t Q)
{
        return Q.size;
}


int queue_push(queue_t *restrict Q, void *data)
{
        struct queue_node *new = (struct queue_node*)malloc(sizeof(struct queue_node));
        if (new == NULL) return 1;
        new->data = data;
        new->next = 0;

        if (queue_empty(*Q)) Q->tail = new;
        else Q->head->next = new;

        Q->head = new;
        Q->size++;
        return 0;
}

extern void *queue_pop(queue_t *restrict Q)
{
        if (queue_empty(*Q)) return NULL;

        struct queue_node *old = Q->tail;
        void *data = old->data;

        if (Q->tail == Q->head) Q->head = 0;
        Q->tail = Q->tail->next;
        
        free(old);
        Q->size--;
        return data;
}

extern void* queue_front(const queue_t Q)
{
        if (queue_empty(Q)) return NULL;
        return Q.tail->data;
}
