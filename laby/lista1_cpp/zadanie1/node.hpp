#ifndef NODE_HPP
#define NODE_HPP

class Node {
public:
    int data;
    Node* next;
    Node(int data);
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
public:
    Queue();
    void enqueue(int data);
    void dequeue();
    int getFront();
    bool isEmpty() const;
    int getSize() const;
};

class Stack {
private:
    Node* top;
    int size;
public:
    Stack();
    void push(int data);
    void pop();
    int peek();
    bool isEmpty() const;
    int getSize() const;
};

#endif
