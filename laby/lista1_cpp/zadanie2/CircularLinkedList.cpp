#include "CircularLinkedList.hpp"

void CircularLinkedList::insert(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    size++;
}

CircularLinkedList CircularLinkedList::merge(CircularLinkedList& l1, CircularLinkedList& l2) {
    if (!l1.head) return l2;
    if (!l2.head) return l1;

    Node* temp = l1.head;
    while (temp->next != l1.head) {
        temp = temp->next;
    }
    temp->next = l2.head;
    temp = l2.head;
    while (temp->next != l2.head) {
        temp = temp->next;
    }
    temp->next = l1.head;
    l1.size += l2.size;
    l2.head = nullptr;
    l2.size = 0;
    return l1;
}

int CircularLinkedList::search(int value) {
    int comparisons = 0;
    if (!head) return comparisons;

    Node* temp = head;
    do {
        comparisons++;
        if (temp->value == value) break;
        temp = temp->next;
    } while (temp != head);

    return comparisons;
}