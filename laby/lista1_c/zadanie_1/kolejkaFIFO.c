#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // nagłówek definiujący INT_MIN

// Definicja struktury Node, która jest węzłem listy jednokierunkowej
// Każdy węzeł zawiera dane (data) typu int i wskaźnik (next) na następny węzeł w kolejce

struct Node {
    int data;
    struct Node* next;
};

// Definicja struktury dla kolejki
// Zawiera dwa wskaźniki: front(przód kolejki) i rear(tył kolejki)

struct Queue {
    struct Node *front, *rear;
};

// Funkcja do tworzenia nowego węzła
// Tworzy nowy węzeł z daną wartością k
// Przydziela pamięć dla nowego węzła (malloc), inicjalizuje jego dane (data) wartością k,
// ustawia wskanik next na NULL (oznaczający koniec listy) i zwraca wskaźnik do tego nowego węzła

struct Node* newNode(int k) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

// Funkcja do tworzenia pustej kolejki
// Inicjalizuje pustą kolejkę. Przydziela pamięć dla struktury kolejki,
// ustawia wskaźniki front i rear na NULL (oznaczając pustą kolejkę) i zwraca wskaźnik do tej kolejki

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Funkcja do dodawania elementu do kolejki
// Dodaje element k do kolejki q. Tworzy nowe węzeł dla k.
// Jeśli kolejka jest pusta, ustawia zarówno front jak i reak na nowy węzeł
// W przeciwnym razie, dodaje nowy węzeł na koniec kolejki i aktualizuje wskaźnik rear

void enqueue(struct Queue* q, int k) {
    printf("Dodawanie do kolejki FIFO: %d\n", k);
    struct Node* temp = newNode(k);
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

// Funkcja do usuwania elementu z kolejki
// Usuwa element z przodu kolejki i zwraca jego wartość
// Jeśli kolejka jest pusta, zwraca INT_MIN. Przechowuje wartość węzła,
// aktualizuje front do następnego węzła, zwalnia pamięć usuniętego węzła i zwraca przechowaną wartość
// Jeśli po usunięciu kolejka jest pusta, ustawia również rear na NULL

int dequeue(struct Queue* q) {
    if (q->front == NULL)
        return INT_MIN;
    struct Node* temp = q->front;
    int data = temp->data;
    // printf("Usuwanie z kolejki FIFO: %d\n", data);
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    free(temp);
    return data;    
}

// Funkcja do sprawdzania, czy kolejka jest pusta
// Sprawdza, czy kolejka jest pusta, poprzez sprawdzenie, czy front jest NULL
// Zwraca 1 (prawda), jeśli kolejka jest pusta, w przeciwnym razie 0 (fałsz)

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}