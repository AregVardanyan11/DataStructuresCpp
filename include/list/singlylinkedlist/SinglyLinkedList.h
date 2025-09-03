#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "../List.h"

template <typename T>
class SinglyLinkedList : public List<T> {
private:
    template <typename E>
    struct Node {
        E value;
        Node* next;
        Node(const E& value) : value(value), next(nullptr) {}
    };

    Node<T>* head;
    Node<T>* tail;
    int count{0};

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

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
};

#include "SinglyLinkedList.tpp"

#endif // SINGLY_LINKED_LIST_H
