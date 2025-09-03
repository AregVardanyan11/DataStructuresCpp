#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "../List.h"
#include <stdexcept>
#include <iostream>

template <typename T>
class DoublyLinkedList : public List<T> {
private:
    template <typename E>
    struct Node {
        E value;
        Node* next;
        Node* prev;
        Node(const E& val) : value(val), next(nullptr), prev(nullptr) {}
    };

    Node<T>* head;
    Node<T>* tail;
    int count{0};

public:
    DoublyLinkedList();
    ~DoublyLinkedList() override;

    void push_front(const T& value) override;
    void push_back(const T& value) override;
    void insert(int index, const T& value) override;

    void pop_front() override;
    void pop_back() override;
    void remove(int index) override;

    // Accessors
    T& get(int index) override;
    const T& get(int index) const override;


    int size() const override;
    bool isEmpty() const override;

    void print() const override;
    void clear() override;
};

#include "DoublyLinkedList.tpp"

#endif // DOUBLYLINKEDLIST_H
