#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <cstddef>

template <typename T>
class MyVector {
private:
    T* data_;
    std::size_t size_;
    std::size_t capacity_;

    void grow();

public:
    MyVector();
    ~MyVector();

    void push_back(const T& value);
    void pop_back();

    T& operator[](std::size_t index);

    std::size_t size() const;
};

#include "../src/MyVector.cpp"

#endif