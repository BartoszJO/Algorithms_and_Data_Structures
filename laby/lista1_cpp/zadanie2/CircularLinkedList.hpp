#pragma once
#include "Node.hpp"

class CircularLinkedList {
    public:
        Node* head;
        int size;

        CircularLinkedList() : head(nullptr), size(0) {}
        void insert(int value);
        static CircularLinkedList merge(CircularLinkedList& l1, CircularLinkedList& l2);
        int search(int value);
};