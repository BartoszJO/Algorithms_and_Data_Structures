#include "dlist.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

DList* createDList() {
    DList* l = (DList*)malloc(sizeof(DList));
    l->head = NULL;
    l->size = 0;
    return l;
}

void insertDList(DList *l, int i) {
    DNode* newNode = (DNode*)malloc(sizeof(DNode));
    newNode->value = i;
    if (l->head == NULL) {
        newNode->next = newNode->prev = newNode; // Wskazuje na siebie
        l->head = newNode;
    } else {
        newNode->next = l->head;
        newNode->prev = l->head->prev;
        l->head->prev->next = newNode;
        l->head->prev = newNode;
    }
    l->size++;
}

void mergeDList(DList *l1, DList *l2) {
    if (!l1->head) {
        l1->head = l2->head;
        l1->size = l2->size;
    } else if (l2->head) {
        DNode *l1Last = l1->head->prev;
        DNode *l2Last = l2->head->prev;

        l1Last->next = l2->head;
        l2->head->prev = l1Last;

        l2Last->next = l1->head;
        l1->head->prev = l2Last;

        l1->size += l2->size;
    }
    l2->head = NULL;
    l2->size = 0;
}

int searchDList(DList *l, int value) {
    if (!l->head) return -1; // Lista jest pusta

    srand(time(NULL));
    bool direction = rand() % 2; // Losuje kierunek: 0 dla przód, 1 dla tył
    DNode *temp = l->head;
    int comparisons = 0;

    if (direction) { // Szukaj do przodu
        do {
            comparisons++;
            if (temp->value == value) return comparisons;
            temp = temp->next;
        } while (temp != l->head);
    } else { // Szukaj do tyłu
        do {
            comparisons++;
            if (temp->value == value) return comparisons;
            temp = temp->prev;
        } while (temp != l->head);
    }
    return -1; // Wartość nie znaleziona
}