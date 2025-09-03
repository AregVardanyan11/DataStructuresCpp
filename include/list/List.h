#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
public:
    virtual ~List() = default;

    virtual void push_front(const T& value) = 0;
    virtual void push_back(const T& value) = 0;
    virtual void insert(int index, const T& value) = 0;

    virtual void pop_front() = 0;
    virtual void pop_back() = 0;
    virtual void remove(int index) = 0;

    virtual T& get(int index) = 0;
    virtual const T& get(int index) const = 0;

    virtual int size() const = 0;
    virtual bool isEmpty() const = 0;

    virtual void print() const = 0;

    virtual void clear() = 0;
};

#endif // LIST_H
