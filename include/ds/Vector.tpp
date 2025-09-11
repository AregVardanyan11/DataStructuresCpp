#ifndef VECTOR_TPP
#define VECTOR_TPP

#include "Vector.h"

template<typename T>
ds::Vector<T>::Vector(): data_(nullptr), size_(0), capacity_(0) {}

template<typename T>
ds::Vector<T>::Vector(size_t count, const T &value): size_(count), capacity_(count) {
    data_ = new T[count];
    for (size_t i = 0; i < count; i++) {
        data_[i] = value;
    }
}

template<typename T>
ds::Vector<T>::Vector(std::initializer_list<T> init): size_(init.size()), capacity_(init.size()) {
    data_ = new T[init.size()];
    size_t i = 0;
    for (const T& val : init)
        data_[i++] = val;
}

template<typename T>
ds::Vector<T>::Vector(const Vector &other): size_(other.size_), capacity_(other.capacity_) {
    data_ = new T[other.capacity_];
    for (size_t i = 0; i < other.size_; i++) {
        data_[i] = other.data_[i];
    }
}

template<typename T>
ds::Vector<T>::Vector(Vector &&other) noexcept: size_(other.size_), capacity_(other.capacity_) {
    other.capacity_ = 0;
    other.size_ = 0;
    other.data_ = nullptr;

}

template<typename T>
ds::Vector<T> & ds::Vector<T>::operator=(const Vector &other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[other.size_];
        for (size_t i = 0; i < other.size_; i++) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template<typename T>
ds::Vector<T> & ds::Vector<T>::operator=(Vector &&other) noexcept {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = other.data_;
        other.capacity_ = 0;
        other.data_ = nullptr;
        other.size_ = 0;
    }
}

template<typename T>
ds::Vector<T>::~Vector() {delete[] data_;}

template<typename T>
size_t ds::Vector<T>::size() const noexcept {return size_;}

template<typename T>
size_t ds::Vector<T>::capacity() const noexcept {return capacity_;}

template<typename T>
bool ds::Vector<T>::empty() const noexcept {return size_ == 0;}

template<typename T>
void ds::Vector<T>::reserve(size_t new_cap) {
    if (capacity_ < new_cap) {reallocate(new_cap);}
}

template<typename T>
void ds::Vector<T>::resize(size_t new_size, const T &value) {
    if (new_size > capacity_) {reallocate(new_size);}
    if (new_size > size_) {reallocate(new_size);}
    for (size_t i = size_; i < new_size; i++) {
        data_[i] = value;
    }
    size_ = new_size;
}

template<typename T>
T & ds::Vector<T>::operator[](size_t index) {
    return data_[index];
}

template<typename T>
const T & ds::Vector<T>::operator[](size_t index) const {
    return data_[index];
}

template<typename T>
T & ds::Vector<T>::at(size_t index) {
    if (index >= size_) throw std::out_of_range("Index out of range");
    return data_[index];
}

template<typename T>
const T & ds::Vector<T>::at(size_t index) const {
    if (index >= size_) throw std::out_of_range("Index out of range");
    return data_[index];
}

template<typename T>
T & ds::Vector<T>::front() {return data_[0];}

template<typename T>
const T & ds::Vector<T>::front() const {return data_[0];}

template<typename T>
T & ds::Vector<T>::back() {return data_[size_ - 1];}

template<typename T>
const T & ds::Vector<T>::back() const {return data_[size_ - 1];}

template<typename T>
void ds::Vector<T>::push_back(const T &value) {
    if (size_ == capacity_) {reallocate(capacity_ == 0 ? 1 : capacity_ * 2);}
    data_[size_++] = value;
}

template<typename T>
void ds::Vector<T>::push_back(T &&value) {
    if (size_ == capacity_) {reallocate(capacity_ == 0 ? 1 : capacity_ * 2);}
    data_[size_++] = std::move(value);
}

template<typename T>
void ds::Vector<T>::pop_back() {
    if (size_ == 0) {
        throw std::out_of_range("Vector is empty");
    }
    size_--;
}

template<typename T>
void ds::Vector<T>::clear() {size_ = 0;}

template<typename T>
typename ds::Vector<T>::iterator ds::Vector<T>::begin() {
    return iterator(data_);
}

template<typename T>
typename ds::Vector<T>::iterator ds::Vector<T>::end() {
    return iterator(data_ + size_);
}

template<typename T>
typename ds::Vector<T>::const_iterator ds::Vector<T>::begin() const {
    return const_iterator(data_);
}

template<typename T>
typename ds::Vector<T>::const_iterator ds::Vector<T>::end() const {
    return const_iterator(data_ + size_);
}

template<typename T>
void ds::Vector<T>::reallocate(size_t new_cap) {
    T* new_data = new T[new_cap];
    for (size_t i = 0; i < size_; i++) {
        new_data[i] = data_[i];
    }
    delete[] data_;
    data_ = new_data;
    capacity_ = new_cap;
}

#endif VECTOR_TPP
