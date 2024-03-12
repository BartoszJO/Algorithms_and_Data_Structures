#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArrayWithRandomNumbers(int* array, int size, int max) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (max + 1);
    }
}

void printDList(DList *l) {
    if (l->head == NULL) {
        printf("Lista jest psta.\n");
        return;
    }
    DNode *temp = l->head;
    do {
        printf("%d ", temp->value);
        temp = temp->next;
    } while (temp != l->head);
    printf("\n");
}

int main() {
    srand(time(NULL)); // Inicjalizacja generatora liczb losowych

    // Demonstracja insert i merge dla listy dwukierunkowej
    DList *l1 = createDList();
    DList *l2 = createDList();

    // Wstawianie dwucyfrowych liczb nieujmenych do l1 i l2
    for (int i = 10; i < 20; i++) {
        insertDList(l1, i);
    }
    for (int i = 20; i < 30; i++) {
        insertDList(l2, i);
    }

    printf("Lista l1 przed scaleniem: ");
    printDList(l1);
    printf("Lista l2 przed scaleniem: ");
    printDList(l2);

    //Scalanie list
    mergeDList(l1, l2);

    printf("Lista l1 po scaleniu z l2: ");
    printDList(l1);
    printf("Lista l2 po scaleniu (powinna być pusta): ");
    printDList(l2);

    // Eksperyment z wyszukiwaniem
    int T[10000];
    fillArrayWithRandomNumbers(T, 10000, 100000);
    DList* L = createDList();
    for (int i = 0; i < 10000; i++) {
        insertDList(L, T[i]);
    }

    // Wyszukiwanie
    int foundComparisons = 0, notFoundComparisons = 0;
    for (int i = 0; i < 1000; i++) {
        int index = rand() % 10000; // Losowy indeks z tablicy T
        foundComparisons += searchDList(L, T[index]);

        int randomValue = rand() % 100001; // Losowa wartośc z przedziału [0, 100000]
        int result = searchDList(L, randomValue);
        notFoundComparisons += (result == -1) ? L->size : result;
    }

    printf("Średni koszt wyszukiwania istniejącej liczby: %.2f\n", (double)foundComparisons / 1000);
    printf("Sredni koszt wyszukiwania losowej liczby: %.2f\n", (double)notFoundComparisons / 1000);

    return 0;
}