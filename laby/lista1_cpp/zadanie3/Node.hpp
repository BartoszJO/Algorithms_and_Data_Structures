#pragma once

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

        Node(int value) : value(value), next(nullptr), prev(nullptr) {}
};