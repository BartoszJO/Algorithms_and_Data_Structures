#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} List;

List* createList();
void insert(List *l, int i);
void merge(List *l1, List *l2);
int search(List *l, int value);

#endif