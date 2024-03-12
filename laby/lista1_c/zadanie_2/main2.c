#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printList(List *l) {
    if (l->head == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }
    Node *temp = l->head;
    do {
        printf("%d ", temp->value);
        temp = temp->next;
    } while (temp != l->head);
    printf("\n");
}

void fillArrayWithRandomNumbers(int* array, int size, int max) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max +1);
    }
}

int main() {
    srand(time(NULL)); // Inicjalizacja generatora liczb losowych

// Demonstracja insert i merge
    List *l1 = createList();
    List *l2 = createList();
    
    // Wstawianie dwucyfrowych liczb nieujemnych do l1 i l2
    for (int i = 10; i < 20; i++) {
        insert(l1, i);
    }
    for (int i = 20; i < 30; i++) {
        insert(l2, i);
    }

    printf("Lista l1 przed scaleniem: ");
    printList(l1);
    printf("Lista l2 przed scaleniem: ");
    printList(l2);

    // Scalanie list
    merge(l1, l2);

    printf("Lista l1 po scaleniu z l2: ");
    printList(l1);
    printf("Lista l2 po scaleniu (powinna być pusta): ");
    printList(l2);

    int T[10000];
    fillArrayWithRandomNumbers(T, 10000, 100000);

    List* L = createList();
    for(int i = 0; i < 10000; i++) {
        insert(L, T[i]);
    }

    // Eksperyment wyszukiwania
    int foundComparisons = 0, notFoundComparisons = 0;
    for (int i = 0; i < 1000; i++) {
        int index = rand() % 10000;
        foundComparisons += search(L, T[index]);

        int randomValue = rand() % 100001;
        int result = search(L, randomValue);
        notFoundComparisons += (result == -1) ? L->size : result;
    }

    printf("Średni koszt wyszukiwania istniejącej liczby: %.2f\n", (double)foundComparisons / 1000);
    printf("Średni koszt wyszukiwania losowej liczby: %.2f\n", (double)notFoundComparisons / 1000);

    return 0;
}