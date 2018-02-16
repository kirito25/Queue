#include "queue.h"
#include <stdio.h>

int enqueue(Queue * q, Node * v) {
    Node * oldLast = q->last;
    v->next = NULL;
    q->last = v;
    if (q->true_count == 0) {
        q->true_first = v;
    }
    if (q->count == 0) { 
        q->first = v; 
    }
    else { 
        oldLast->next = v; 
    }
    q->count++;
    q->true_count++;
    q->true_last = v;
    return 0;
}

Node * dequeue(Queue * q) {
    if (q->count == 0) { 
        printf("Queue is empty\n");
        return NULL; 
    }
    Node * v = q->first;
    q->first = v->next;
    q->count--;
    return v;
}

Queue * initqueue() {
    Queue * q = (Queue *) malloc(sizeof(Queue));
    if (q == NULL) { 
        printf("Could not allocate memory for Queue\n");
        return NULL; 
    }
    q->first = NULL;
    q->last = NULL;
    q->true_last = NULL;
    q->true_first = NULL;
    q->true_count = 0;
    q->count = 0;
    return q;
}

void reset(Queue * q) {
    q->first = q->true_first;
    q->last = q->true_last;
    q->count = q->true_count;
}

void wipe(Queue * q) {
    reset(q);
    while(q->count > 0) {
        Node * v = dequeue(q);
        free(v);
    }
    q->first = NULL;
    q->last = NULL;
    q->true_last = NULL;
    q->true_first = NULL;
    q->true_count = 0;
    q->count = 0;
}
