#include <stdio.h>
#include <stdlib.h>

#include "kolejkaFIFO.h"
#include "stosLIFO.h"

int main() {
    struct Queue* queue = createQueue();
    struct StackNode* stack = NULL;

    // Dodawanie elementów
    for (int i = 1; i < 50; i++) {
        enqueue(queue, i);
        push(&stack, i);
    }

    // Usuwanie i wypisywanie elementów z kolejki
    printf("Kolejka (FIFO):\n");
    while (!isEmpty(queue)) {
        printf("%d ", dequeue(queue));
    }

    // Usuwanie i wypisywanie elementów ze stosu
    printf("\n\nStos (LIFO):\n");
    while (!isEmptyStack(stack)) {
        printf("%d ", pop(&stack));
    }
    
    return 0;
}