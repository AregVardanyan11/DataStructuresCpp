//
// Created by areg on 9/3/25.
//

#ifndef EXAMPLE_CIRCULARLINKEDLIST_H
#define EXAMPLE_CIRCULARLINKEDLIST_H

#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include "../List.h"
#include <iostream>
#include <stdexcept>

template <typename T>
class CircularLinkedList : public List<T> {
private:
    template <typename E>
    struct Node {
        E value;
        Node* next;
        Node(const E& value) : value(value), next(nullptr) {}
    };

    Node<T>* tail;
    int count{0};

public:
    CircularLinkedList();
    ~CircularLinkedList() override;

    // List interface
    void push_front(const T& value) override;
    void push_back(const T& value) override;
    void insert(int index, const T& value) override;

    void pop_front() override;
    void pop_back() override;
    void remove(int index) override;

    T& get(int index) override;
    const T& get(int index) const override;

    int size() const override;
    bool isEmpty() const override;

    void print() const override;
    void clear() override;

    void rotate();
};

#include "CircularLinkedList.tpp" // include template implementation

#endif // CIRCULAR_LINKED_LIST_H


#endif //EXAMPLE_CIRCULARLINKEDLIST_H