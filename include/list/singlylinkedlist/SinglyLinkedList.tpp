#ifndef EXAMPLE_SINGLYLINKEDLIST_TPP
#define EXAMPLE_SINGLYLINKEDLIST_TPP


#include "SinglyLinkedList.h"
#include "stdexcept"
#include "iostream"

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr){}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    clear();
}

template<typename T>
void SinglyLinkedList<T>::push_front(const T &value) {
    Node<T>* newNode = new Node<T>(value);
    if (!head) {
        head = newNode;
    }else {
        newNode->next = head;
        head = newNode;
    }
    count++;
}

template<typename T>
void SinglyLinkedList<T>::push_back(const T &value) {
    Node<T> *newNode = new Node(value);
    if (!head) {
        head = newNode;
    }
    else {
        Node<T> *prev = head;
        while (prev->next) prev = prev->next;
        prev->next = newNode;
    }
    count++;
}

template<typename T>
void SinglyLinkedList<T>::insert(int index, const T &value) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Invalid index");
    }
    if (index == 0) {push_front(value);return;}
    if (index == count) {push_back(value); return;}

    Node<T>* prev = head;
    for (int i = 0; i < index-1; i++) prev = prev->next;

    Node<T> *newNode = new Node(value);
    newNode->next = prev->next;
    prev->next = newNode;
    count++;
}

template<typename T>
void SinglyLinkedList<T>::pop_front() {
    if (isEmpty()) {
        throw std::out_of_range("Empty list");
    }
    Node<T> *current = head;
    head = head->next;
    delete current;
    current = nullptr;
    count--;
}

template<typename T>
void SinglyLinkedList<T>::pop_back() {
    if (count == 0) {
        throw std::out_of_range("Empty list");
    }
    if (count == 0) pop_front();
    Node<T> *prev = head;
    while (prev->next->next) prev = prev->next;
    delete prev->next;
    prev->next = nullptr;
    count--;
}

template<typename T>
void SinglyLinkedList<T>::remove(int index) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Invalid index");
    }
    if (index == 0){ pop_front();return;}
    if (index == count-1){ pop_back();return;}

    Node<T> *prev = head;
    for (int i = 0; i < index-1; i++) prev = prev->next;
    Node<T>* current = prev->next;
    prev->next = current->next;
    delete current;
    current = nullptr;
    count--;
}

template<typename T>
T & SinglyLinkedList<T>::get(int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Invalid index");
    }
    Node<T> *curr = head;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->value;
}

template<typename T>
const T & SinglyLinkedList<T>::get(int index) const {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Invalid index");
    }
    Node<T> *curr = head;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->value;
}

template<typename T>
int SinglyLinkedList<T>::size() const {
    return this->count;
}

template<typename T>
bool SinglyLinkedList<T>::isEmpty() const {
    return this->count == 0;
}

template <typename T>
void SinglyLinkedList<T>::print() const {
    Node<T>* curr = head;
    while (true) {
        std::cout << curr->value;
        if (curr->next == nullptr) {
            break;
        }
        std::cout << " " << " -> ";
        curr = curr->next;
    }
    std::cout << "\n";
}

template<typename T>
void SinglyLinkedList<T>::clear() {
    while (!isEmpty()) pop_front();
}

#endif //EXAMPLE_SINGLYLINKEDLIST_TPP