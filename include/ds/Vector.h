#ifndef DS_VECTOR_H
#define DS_VECTOR_H

#include <stdexcept>
#include <initializer_list>
#include <algorithm>

namespace ds {

template <typename T>
class Vector {
public:
    Vector();
    explicit Vector(size_t count, const T& value = T());
    Vector(std::initializer_list<T> init);
    Vector(const Vector& other);
    Vector(Vector&& other) noexcept;
    Vector& operator=(const Vector& other);
    Vector& operator=(Vector&& other) noexcept;
    ~Vector();

    size_t size() const noexcept;
    size_t capacity() const noexcept;
    bool empty() const noexcept;
    void reserve(size_t new_cap);
    void resize(size_t new_size, const T& value = T());

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T& at(size_t index);
    const T& at(size_t index) const;
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    void clear();


    class iterator {
    private:
        T* ptr_;
    public:
        explicit iterator(T* ptr) : ptr_(ptr) {}
        iterator& operator++() { ++ptr_; return *this; }
        iterator operator++(int) { iterator tmp = *this; ++ptr_; return tmp; }
        bool operator==(const iterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const iterator& other) const { return ptr_ != other.ptr_; }
        T& operator*() const { return *ptr_; }
    };

    iterator begin();
    iterator end();

    class const_iterator {
    private:
        const T* ptr_;
    public:
        explicit const_iterator(const T* ptr) : ptr_(ptr) {}
        const_iterator& operator++() { ++ptr_; return *this; }
        const_iterator operator++(int) { const_iterator tmp = *this; ++ptr_; return tmp; }
        bool operator==(const const_iterator& other) const { return ptr_ == other.ptr_; }
        bool operator!=(const const_iterator& other) const { return ptr_ != other.ptr_; }
        const T& operator*() const { return *ptr_; }
    };
    const_iterator begin() const;
    const_iterator end() const;

private:
    T* data_;
    size_t size_;
    size_t capacity_;

    void reallocate(size_t new_cap);
};

}

#include "Vector.tpp"

#endif // DS_VECTOR_H
