#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * Test the queue functions above
 */
int main() {
    Queue * q;
    int i = 0;
    q = initqueue();
    for (i = 0; i < 10; i++) {
        Node  * v;
        v = (Node *) malloc(sizeof(Node));
        v->id = i;
        v->next = NULL;
        enqueue(q, v);
    }
    while (q->count > 0) {
        Node * v = dequeue(q);
        printf("%d ", v->id);
    }
    printf("\nTesting queue reset and adding 10 - 19 to be printed\n");
    reset(q);
    for (i = 10; i < 20; i++) {
        Node  * v;
        v = (Node *) malloc(sizeof(Node));
        v->id = i;
        v->next = NULL;
        enqueue(q, v);
    }
    while (q->count > 0) {
        Node * v = dequeue(q);
        printf("%d ", v->id);
        free(v);
    }
    printf("\n");
    wipe(q);
    printf("Testing after wipe once again\n");
    for (i = 0; i < 10; i++) {
        Node  * v;
        v = (Node *) malloc(sizeof(Node));
        v->id = i;
        v->next = NULL;
        enqueue(q, v);
    }
    while (q->count > 3) {
        Node * v = dequeue(q);
        printf("%d ", v->id);
    }
    printf("\n");
    wipe(q);
    free(q);
    return 0;
}
