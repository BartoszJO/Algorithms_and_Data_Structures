#include "DoublyCircularLinkedList.hpp"
#include <cstdlib> // Dla funkcji rand()
#include <ctime>   // Dla funkcji time()

void DoublyCircularLinkedList::insert(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
    size++;
}

DoublyCircularLinkedList DoublyCircularLinkedList::merge(DoublyCircularLinkedList& l1, DoublyCircularLinkedList& l2) {
    if (!l1.head) return l2;
    if (!l2.head) return l1;

    Node* l1Last = l1.head->prev;
    Node* l2Last = l2.head->prev;

    l1Last->next = l2.head;
    l2.head->prev = l1Last;

    l2Last->next = l1.head;
    l1.head->prev = l2Last;

    l1.size += l2.size;
    l2.head = nullptr;
    l2.size = 0;

    return l1;
}

int DoublyCircularLinkedList::search(int value) {
    int comparisons = 0;
    if (!head) return comparisons; // Lista jest pusta.

    bool direction = std::rand() % 2; // Losowo wybieramy kierunek: 0 dla przód, 1 dla tył.

    Node* temp = head;
    do {
        comparisons++;
        if (temp->value == value) break;
        temp = direction ? temp->prev : temp->next;
    } while (temp != head);

    return comparisons; // Zwraca ilość porównań.
}
