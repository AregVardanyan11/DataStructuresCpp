#ifndef EXAMPLE_DOUBLYLINKEDLIST_TPP
#define EXAMPLE_DOUBLYLINKEDLIST_TPP

#include "DoublyLinkedList.h"

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {

}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    clear();
}

template<typename T>
void DoublyLinkedList<T>::push_front(const T &value) {
    Node<T>* newNode = new Node<T>(value);
    if (!tail) {
        head = tail = newNode;
    }else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T &value) {
    Node<T>* newNode = new Node<T>(value);
    if (!tail) {
        tail = head = newNode;
    }else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    count++;
}

template<typename T>
void DoublyLinkedList<T>::insert(int index, const T &value) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Invalid index");
    }
    if (index == 0) {push_front(value);return;}
    if (index == count) {push_back(value); return;}

    Node<T>* prev = head;
    for (int i = 0; i < index-1; i++) prev = prev->next;

    Node<T> *current = new Node(value);
    Node<T>* next = prev->next;

    current->next = prev->next;
    current->prev = prev;
    prev->next = current;
    next->prev = current;

    count++;
}

template<typename T>
void DoublyLinkedList<T>::pop_front() {
    if (isEmpty()) {
        throw std::out_of_range("Empty list");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        count--;
        return;
    }
    Node<T> *prev = head;
    head = head->next;
    head->prev = nullptr;
    delete prev;
    count--;
}

template<typename T>
void DoublyLinkedList<T>::pop_back() {
    if (isEmpty()) {
        throw std::out_of_range("Empty list");
    }
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        count--;
        return;
    }
    Node<T> *next = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete next;
    count--;
}

template<typename T>
void DoublyLinkedList<T>::remove(int index) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Invalid index");
    }
    if (index == 0){ pop_front();return;}
    if (index == count-1){ pop_back();return;}

    Node<T> *prev = head;
    for (int i = 0; i < index-1; i++) prev = prev->next;
    Node<T>* temp = prev->next;
    temp->next->prev = prev;
    prev->next = temp->next;
    delete temp;
    temp = nullptr;
    count--;
}

template<typename T>
T & DoublyLinkedList<T>::get(int index) {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Invalid index");
    }
    Node<T> *curr = head;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->value;
}

template<typename T>
const T & DoublyLinkedList<T>::get(int index) const {
    if (index < 0 || index >= count) {
        throw std::out_of_range("Invalid index");
    }
    Node<T> *curr = head;
    for (int i = 0; i < index; i++) curr = curr->next;
    return curr->value;
}

template<typename T>
int DoublyLinkedList<T>::size() const {
    return count;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return count == 0;
}

template<typename T>
void DoublyLinkedList<T>::print() const {
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
void DoublyLinkedList<T>::clear() {
    while (!isEmpty()) {
        pop_front();
    }
}

#endif //EXAMPLE_DOUBLYLINKEDLIST_TPP
