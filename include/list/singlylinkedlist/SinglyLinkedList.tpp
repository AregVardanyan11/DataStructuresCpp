#include "SinglyLinkedList.h"
#include "stdexcept"
#include "iostream"

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    while (!isEmpty()) {
        pop_front();
    }
}

template<typename T>
void SinglyLinkedList<T>::push_front(const T &value) {
    Node<T> *newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) {
        tail = newNode;
    }
    count++;
}

template<typename T>
void SinglyLinkedList<T>::push_back(const T &value) {
    Node<T> *newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
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
    if (head == tail) {
        delete head;
        head = tail = nullptr;
        count--;
        return;
    }
    Node<T> *prev = head;
    head = head->next;
    delete prev;
    count--;
}

template<typename T>
void SinglyLinkedList<T>::pop_back() {
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
    while (prev->next != tail) prev = prev->next;
    delete tail;
    tail = prev;
    tail->next = nullptr;
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
    Node<T>* temp = prev->next;
    prev->next = temp->next;
    delete temp;
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
    std::cout << "null\n";
}

template<typename T>
void SinglyLinkedList<T>::clear() {
    while (!isEmpty()) pop_front();
}

