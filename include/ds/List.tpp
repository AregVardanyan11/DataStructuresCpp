#ifndef LIST_TPP
#define LIST_TPP

#include "List.h"

template<typename T>
ds::List<T>::List(): head_(nullptr), tail_(nullptr), size_(0) {
}

template<typename T>
ds::List<T>::List(std::initializer_list<T> init): List(){
    for (const T& val : init) {
        push_back(val);
    }
}

template<typename T>
ds::List<T>::List(const List &other): List() {
    for (const T& val : other) {
        push_back(val);
    }
}

template<typename T>
ds::List<T>::List(List &&other) noexcept: head_(other.head_), tail_(other.tail_), size_(other.size_) {
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
}

template<typename T>
ds::List<T> & ds::List<T>::operator=(const List &other) {
    if (this != &other) {
        clear();
        for (const T& val : other) {
            push_back(val);
        }
    }
    return *this;
}

template<typename T>
ds::List<T> & ds::List<T>::operator=(List &&other) noexcept {
    if (this != &other) {
        clear();
        head_ = other.head_;
        tail_ = other.tail_;
        size_ = other.size_;
        other.head_ = nullptr;
        other.tail_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

template<typename T>
ds::List<T>::~List() {clear();}

template<typename T>
size_t ds::List<T>::size() const noexcept {return size_;}

template<typename T>
bool ds::List<T>::empty() const noexcept {return size_ == 0;}

template<typename T>
T & ds::List<T>::front() {return head_ -> data;}

template<typename T>
const T & ds::List<T>::front() const {return head_ -> data;}

template<typename T>
T & ds::List<T>::back() {return tail_ -> data;}

template<typename T>
const T & ds::List<T>::back() const {return tail_ -> data;}

template<typename T>
void ds::List<T>::push_front(const T &value) {
    Node *new_node = new Node(value, nullptr, head_);
    if (head_ == nullptr) head_->prev = new_node;
    head_ = new_node;
    if (tail_ == nullptr) tail_ = head_;
    ++size_;
}

template<typename T>
void ds::List<T>::push_front(T &&value) {
    Node *new_node = new Node(std::move(value), nullptr, head_);
    if (head_ == nullptr) head_->prev = new_node;
    head_ = new_node;
    if (tail_ == nullptr) tail_ = head_;
    ++size_;

}

template<typename T>
void ds::List<T>::push_back(const T &value) {
    Node *new_node = new Node(value, tail_, nullptr);
    if (tail_ == nullptr) tail_->next = new_node;
    tail_ = new_node;
    if (head_ == nullptr) head_ = tail_;
    ++size_;
}

template<typename T>
void ds::List<T>::push_back(T &&value) {
    Node *new_node = new Node(std::move(value), tail_, nullptr);
    if (tail_ == nullptr) tail_->next = new_node;
    tail_ = new_node;
    if (head_ == nullptr) head_ = tail_;
    ++size_;
}

template<typename T>
void ds::List<T>::pop_front() {
    if (!head_) throw std::out_of_range("ds::List<T>::pop_front");
    Node *old_head = head_;
    head_ = head_->next;
    if (head_) head_->prev = nullptr;
    else head_ = nullptr;
    delete old_head;
    --size_;
}

template<typename T>
void ds::List<T>::pop_back() {
    if (!tail_) throw std::out_of_range("ds::List<T>::pop_back");
    Node *old_tail = tail_;
    tail_ = tail_->prev;
    if (tail_) tail_->next = nullptr;
    else tail_ = nullptr;
    delete old_tail;
    --size_;
}

template<typename T>
typename ds::List<T>::iterator ds::List<T>::insert(iterator pos, const T &value) {
    if (pos == begin()) {
        push_front(value);
        return begin();
    }
    if (pos == end()) {
        push_back(value);
        return end();
    }
    Node *new_node = new Node(value, pos.node()->prev, pos.node());
    pos.node()->prev->next = new_node;
    pos.node()->prev = new_node;
    ++size_;
    return iterator(new_node);

}

template<typename T>
typename ds::List<T>::iterator ds::List<T>::insert(iterator pos, T &&value) {
    if (pos == begin()) {
        push_front(value);
        return begin();
    }
    if (pos == end()) {
        push_back(value);
        return end();
    }
    Node *new_node = new Node(std::move(value), pos.node()->prev, pos.node());
    pos.node()->prev->next = new_node;
    pos.node()->prev = new_node;
    ++size_;
    return iterator(new_node);
}


template<typename T>
void ds::List<T>::clear() {
    Node *cur = head_;
    while (cur) {
        Node *tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
}

template<typename T>
typename ds::List<T>::iterator ds::List<T>::begin() {
    return iterator(head_);
}

template<typename T>
typename ds::List<T>::iterator ds::List<T>::end() {
    return iterator(nullptr);
}

template<typename T>
typename ds::List<T>::const_iterator ds::List<T>::begin() const {
    return const_iterator(head_);
}

template<typename T>
typename ds::List<T>::const_iterator ds::List<T>::end() const {
    return const_iterator(nullptr);
}

#endif //EXAMPLE_LIST_TPP