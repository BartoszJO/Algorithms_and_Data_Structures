#include "CircularLinkedList.hpp"
#include <iostream>

void displayList(CircularLinkedList& list) {
    if (list.head == nullptr) {
        std::cout << "Lista jest pusta" << std::endl;
        return;
    }
    Node* temp = list.head;
    do {
        std::cout << temp->value << " ";
        temp = temp->next;
    } while (temp != list.head);
    std::cout << std::endl;
}

int main() {
    CircularLinkedList list1, list2;

    for (int i = 10; i < 20; i++) {
        list1.insert(i);
    }

    for (int i = 20; i < 30; i++) {
        list2.insert(i);
    }

    std::cout << "List 1 before merge: ";
    displayList(list1);
    std::cout << "List 2 before merge: ";
    displayList(list2);

    CircularLinkedList mergedList = CircularLinkedList::merge(list1, list2);

    std::cout << "Merged list: ";
    displayList(mergedList);

    return 0;
}