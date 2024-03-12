#include "list.h"
#include <stdlib.h>

List* createList() {
    List* l = (List*)malloc(sizeof(List));
    l->head = NULL;
    l->size = 0;
    return l;
}

void insert(List* l, int i) {
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->value = i;
    if (l->head == NULL) {
        newNode->next = newNode; // Tworzy cykl
        l->head = newNode;
    } else {
        Node* temp = l->head;
        while (temp->next != l->head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = l->head;
    }
    l->size++;
}

void merge(List *l1, List *l2) {
    if (l1->head == NULL) {
        l1->head = l2->head;
        l1->size = l2->size;
    } else if (l2->head != NULL) {
        Node* temp = l1->head;
        while (temp->next != l1->head) {
            temp = temp->next;
        }
        temp->next = l2->head;
        Node* temp2 = l2->head;
        while (temp2->next != l2->head) {
            temp2 = temp2->next;
        }
        temp2->next = l1->head;
        l1->size += l2->size;
    }
    // Resetujemt l2
    l2->head = NULL;
    l2->size = 0;
}

int search(List *l, int value) {
    int comparisons = 0;
    if (l->head == NULL) return -1; // Lista jest pusta

    Node* temp = l->head;
    do {
        comparisons++;
        if (temp->value == value) return comparisons; // Znaleziono wartość
        temp = temp->next;
    } while (temp != l->head);

    return -1; // Wartość nie zostałą znaleziona
}