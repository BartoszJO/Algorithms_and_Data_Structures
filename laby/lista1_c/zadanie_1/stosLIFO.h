#ifndef STOS_LIFO_H
#define STOS_LIFO_H

#include <limits.h>

struct StackNode {
    int data;
    struct StackNode* next;
};

void push(struct StackNode** root, int k);
int pop(struct StackNode** root);
int isEmptyStack(struct StackNode* root);

#endif // STOS_LIFO_H
