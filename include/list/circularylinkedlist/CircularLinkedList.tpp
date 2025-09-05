#ifndef EXAMPLE_CIRCULARLINKEDLIST_TPP
#define EXAMPLE_CIRCULARLINKEDLIST_TPP

#include "CircularLinkedList.h"


template<typename T>
CircularLinkedList<T>::CircularLinkedList() : tail(nullptr){
}

template<typename T>
CircularLinkedList<T>::~CircularLinkedList() {
    CircularLinkedList::clear();
}

template<typename T>
void CircularLinkedList<T>::push_front(const T &value) {
    Node<T>* newNode = new Node<T>(value);
    if (!tail) {
        tail = newNode;
        tail->next = tail;
    } else {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    ++count;
}

template<typename T>
void CircularLinkedList<T>::push_back(const T &value) {
    push_front(value);
    tail = tail->next;
}

template<typename T>
void CircularLinkedList<T>::insert(int index, const T &value) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Invalid index");
    }
    if (index == 0) {push_front(value);return;}
    if (index == count) {push_back(value); return;}

    Node<T>* prev = tail;
    for (int i = 0; i < index; i++) prev = prev->next;

    Node<T> *newNode = new Node(value);
    newNode->next = prev->next;
    prev->next = newNode;
    count++;
}

template<typename T>
void CircularLinkedList<T>::pop_front() {
    if (isEmpty()) {
        throw std::out_of_range("Empty list");
    }
    Node<T> *next = tail->next->next;
    delete tail->next;
    tail->next = next;
    count--;
}

template<typename T>
void CircularLinkedList<T>::pop_back() {
    if (isEmpty()) {
        throw std::out_of_range("Empty list");
    }
    Node<T>* current = tail;
    tail = tail->next;
    delete current;
    count--;
}

template<typename T>
void CircularLinkedList<T>::remove(int index) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Invalid index");
    }
    if (index == 0){ pop_front();return;}
    if (index == count-1){ pop_back();return;}

    Node<T> *prev = tail;
    for (int i = 0; i < index; i++) prev = prev->next;
    Node<T>* current = prev->next;
    prev->next = current->next;
    delete current;
    current = nullptr;
    count--;
}

template<typename T>
T & CircularLinkedList<T>::get(int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Invalid index");
    }
    Node<T> *curr = tail->next;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->value;
}

template<typename T>
const T & CircularLinkedList<T>::get(int index) const {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Invalid index");
    }
    Node<T> *curr = tail->next;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->value;
}

template<typename T>
int CircularLinkedList<T>::size() const {
    return count;
}

template<typename T>
bool CircularLinkedList<T>::isEmpty() const {
    return count == 0;
}

template<typename T>
void CircularLinkedList<T>::print() const {
    Node<T>* curr = tail->next;
    while (true) {
        std::cout << curr->value;
        if (curr == tail) {
            break;
        }
        std::cout << " " << " -> ";
        curr = curr->next;
    }
    std::cout << "\n";
}

template<typename T>
void CircularLinkedList<T>::clear() {
    while (!isEmpty()) pop_front();

}

template<typename T>
void CircularLinkedList<T>::rotate() {
}
#endif //EXAMPLE_CIRCULARLINKEDLIST_TPP
