#ifndef LIST_H
#define LIST_H

#include <initializer_list>
#include <stdexcept>
#include <cstddef>

namespace ds {

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(const T& value, Node* p = nullptr, Node* n = nullptr)
            : data(value), prev(p), next(n) {}
        Node(T&& value, Node* p = nullptr, Node* n = nullptr)
            : data(std::move(value)), prev(p), next(n) {}
    };

    Node* head_;
    Node* tail_;
    size_t size_;

public:
    class iterator {
    private:
        Node* current_;
    public:
        iterator(Node* node = nullptr) : current_(node) {}

        T& operator*() { return current_->data; }
        T* operator->() { return &current_->data; }

        iterator& operator++() { current_ = current_->next; return *this; }
        iterator operator++(int) { iterator tmp(*this); ++(*this); return tmp; }
        iterator& operator--() { current_ = current_->prev; return *this; }
        iterator operator--(int) { iterator tmp(*this); --(*this); return tmp; }

        bool operator==(const iterator& other) const { return current_ == other.current_; }
        bool operator!=(const iterator& other) const { return current_ != other.current_; }

        Node* node() const { return current_; }
    };

    class const_iterator {
    private:
        const Node* current_;
    public:
        const_iterator(const Node* node = nullptr) : current_(node) {}

        const T& operator*() const { return current_->data; }
        const T* operator->() const { return &current_->data; }

        const_iterator& operator++() { current_ = current_->next; return *this; }
        const_iterator operator++(int) { const_iterator tmp(*this); ++(*this); return tmp; }
        const_iterator& operator--() { current_ = current_->prev; return *this; }
        const_iterator operator--(int) { const_iterator tmp(*this); --(*this); return tmp; }

        bool operator==(const const_iterator& other) const { return current_ == other.current_; }
        bool operator!=(const const_iterator& other) const { return current_ != other.current_; }
    };

    List();
    List(std::initializer_list<T> init);
    List(const List& other);
    List(List&& other) noexcept;
    List& operator=(const List& other);
    List& operator=(List&& other) noexcept;
    ~List();

    size_t size() const noexcept;
    bool empty() const noexcept;

    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    void push_front(const T& value);
    void push_front(T&& value);
    void push_back(const T& value);
    void push_back(T&& value);

    void pop_front();
    void pop_back();

    iterator insert(iterator pos, const T& value);
    iterator insert(iterator pos, T&& value);

    void clear();

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

}

#include "List.tpp"

#endif // LIST_H
