#ifndef DLIST_H
#define DLIST_H

typedef struct DNode {
    int value;
    struct DNode *next;
    struct DNode *prev;
} DNode;

typedef struct {
    DNode *head;
    int size;
} DList;

DList* createDList();
void insertDList(DList *l, int i);
void mergeDList(DList *l1, DList *l2);
int searchDList(DList *l, int value);

#endif