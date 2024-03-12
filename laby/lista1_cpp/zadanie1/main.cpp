#include "node.hpp"
#include <stdexcept>
#include <iostream>

int main() {
    Queue queue;
    Stack stack;

    std::cout << "Dodawanie do kolejki: ";
    for (int i = 1; i <= 50; ++i) {
        queue.enqueue(i);
        std::cout << i << " ";
    }
    std::cout << "\nDodawanie do stosu: ";
    for (int i = 1; i <= 50; ++i) {
        stack.push(i);
        std::cout << i << " ";
    }

    std::cout << "\nUsuwanie z kolejki: ";
    while (!queue.isEmpty()) {
        std::cout << queue.getFront() << " ";
        queue.dequeue();
    }

    std::cout << "\nUsuwanie ze stosu: ";
    while (!stack.isEmpty()) {
        std::cout << stack.peek() << " ";
        stack.pop();
    }

    std::cout << "\n";

    return 0;
}
