#ifndef KOLEJKA_FIFO_H
#define KOLEJKA_FIFO_H

#include <limits.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

struct Queue* createQueue();
void enqueue(struct Queue* q, int k);
int dequeue(struct Queue* q);
int isEmpty(struct Queue* q);

#endif // KOLEJKA_FIFO_H
