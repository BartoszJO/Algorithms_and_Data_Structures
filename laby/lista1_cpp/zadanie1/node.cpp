#include "node.hpp"
#include <exception>
#include <stdexcept>

Node::Node(int data) : data(data), next(nullptr) {}

Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

// Dodaje element na koniec kolejki
void Queue::enqueue(int data) {
    Node* newNode = new Node(data); // Tworzy nowy węzeł z danymi
    if (rear == nullptr) {
        // Jeśli kolejka jest pusta, nowy węzeł staje się front i rear jednocześnie
        front = rear = newNode;
    } else {
        // Jeśli nie, dodaje nowy węzeł na koniec i aktualizuje rear
        rear->next = newNode; // Ustawiamy next ostatniego elementu w kolejce na newNode
        rear = newNode;
        // Oznacza to, że nowy węzeł staje się następnikiem ostatniego elementu w kolejce
        // newNode jest teraz nowym ostatnim elementem w kolejce
    }
    size++;
}

// Usuwa element z początku kolejki
void Queue::dequeue() {
    if (front == nullptr) {
        // Wyjątek jeśli kolejka jest pusta
        throw std::out_of_range("Queue is empty");
    }
    Node* temp = front; // Zapamiętuje obecny front
    front = front->next; // Przesuwa front na następny węzeł
    if (front == nullptr) {
        // Jeśli kolejka jest teraz pusta, to rear = nullptr
        rear = nullptr;
    }
    delete temp; // Usuwa stary front
    size--; // Zmniejsza rozmiar kolejki
}

int Queue::getFront() {
    if (front == nullptr) {
        throw std::out_of_range("Queue is empty");
    }
    return front->data; // Zwraca dane z front kolejki
}

bool Queue::isEmpty() const {
    return size == 0;
}

int Queue::getSize() const {
    return size;
}

Stack::Stack() : top(nullptr), size(0) {}

// Dodaje element na szczyt stosu
void Stack::push(int data) {
    Node* newNode = new Node(data);
    newNode->next = top; // Nowy węzeł wskazuje na obecny szczyt stosu
    top = newNode; // Nowy węzeł staje się nowym szczytem stosu
    size++;
}

void Stack::pop() {
    if (top == nullptr) {
        // Jeśli stos jest pusty
        throw std::out_of_range("Stack is empty");
    }
    Node* temp = top; // Zapamiętuje obecny top
    top = top->next; // Przesuwa top na następny węzeł
    delete temp; // Usuwa stary top
    size--;
}

// Zwraca wartość elementu na szczycie stosu
int Stack::peek() {
    if (top == nullptr) {
        throw std::out_of_range("Stack is empty");
    }
    return top->data; // Zwraca dane ze szczytu stosu
}

bool Stack::isEmpty() const {
    return size == 0;
}

int Stack::getSize() const {
    return size;
}
