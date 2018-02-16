/* Cristian Peguero
 * Sat Jan 27, 2018
 * This file describes the FIFO queue API.
 */
#include <stdlib.h>

typedef struct node {
    int id;
    struct timeval enter_queue, leave_queue, leave_system;
    struct node * next;
} Node;

typedef struct queue {
    Node * first;
    Node * last;
    Node * true_last;
    Node * true_first;
    int count, true_count;
} Queue;

/* Initlize a queue and return a pointer to that queue
 * Returns NULL if malloc fails
 */
Queue * initqueue();

/* Put the node in the queue.
 * Return 0 on success
 */
int enqueue(Queue * q, Node * v);

/* Remove node from the queue and put it on v.
 * Return NULL when the queue is empty
 */
Node * dequeue(Queue * q);

/* Allows to loop through the queue once again
 */
void reset(Queue * q);

/* Will free everything in the queue using free() but the q pointer can be used again
 */
void wipe(Queue * q);
