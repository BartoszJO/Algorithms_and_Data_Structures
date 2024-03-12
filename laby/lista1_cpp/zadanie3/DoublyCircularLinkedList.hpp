#pragma once
#include "Node.hpp"

class DoublyCircularLinkedList {
    public:
        Node* head;
        int size;

        DoublyCircularLinkedList() : head(nullptr), size(0) {}

        void insert(int value);
        static DoublyCircularLinkedList merge(DoublyCircularLinkedList& l1, DoublyCircularLinkedList& l2);
        int search(int value);
};