#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

// Definicja struktury dla węzła
// Definuje strukturę StackNode, która reprezentuje pojedynczy węzeł (element) stosu
// Każdy węzeł zawiera dane (data) typu int oraz wskaźnik (nezt) na następny węzeł w stosie

struct StackNode {
    int data;
    struct StackNode* next;
};

// Funkcja do tworzenia nowego węzła stosu
// Alokuje pamięć dla nowego węzła stosu, inicjalizuje jego dane wartością k oraz
// ustawia wskaźnik next na NULL, co oznacza, że jest to na razie ostatni (lub jednyny) element stosu
// Funkcja zwraca wskaźnik do nowo utworzonego węzła

struct StackNode* newStackNode(int k) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = k;
    stackNode->next = NULL;
    return stackNode;
}

// Funkcja do dodawania elementu do stosu
// Tworzy nowy węzeł stosu z danymi k i umieszcza go na szczycie stosu
// Nowy węzeł wskazuje na poprzedni wierzchołek stosu (*root), a wskaźnik root jest aktualizowany,
// aby wskazywał na nowy wierzchołek. Operacja ta zachowuje właściwość LIFO stosu

void push(struct StackNode** root, int k) {
    printf("Dodawanie do stosu LIFO: %d\n", k);
    struct StackNode* stackNode = newStackNode(k);
    stackNode->next = *root;
    *root = stackNode;
}

// Funkcja do usuwania elementu ze stosu
// Usuwa element ze szczytu stosu. Jeśli stos jest pusty, zwraca INT_MIN jako sygnał błędu
// W przeciwnym razie, zapisuje dane z węzła szczytowego do zmiennej popped,
// aktualizuje wskaźnik root na następny węzeł w stosie, zwalnia pamięć usuniętego węzła i zwraca jego wartość

int pop(struct StackNode** root) {
    if (*root == NULL)
        return INT_MIN;
    struct StackNode* temp = *root;
    // int data = temp->data;
    // printf("Usuwanie ze stosu LIFO: %d\n", data);
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

// Funkcja do sprawdzania, czy stos jest pusty
// Zwraca 1, jeśli root jest NULL (czyli nie ma elementów)
// W przeciwnym razie zwraca 0

int isEmptyStack(struct StackNode* root) {
    return !root;
}