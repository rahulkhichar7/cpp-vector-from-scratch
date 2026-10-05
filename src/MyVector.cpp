#include "../include/MyVector.h"

template <typename T>
MyVector<T>::MyVector()
    : data_(nullptr), size_(0), capacity_(0) {}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] data_;
}

template <typename T>
void MyVector<T>::grow() {
    std::size_t new_capacity =
        (capacity_ == 0) ? 1 : capacity_ * 2;

    T* new_data = new T[new_capacity];

    for (std::size_t i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }

    delete[] data_;

    data_ = new_data;
    capacity_ = new_capacity;
}

template <typename T>
void MyVector<T>::push_back(const T& value) {
    if (size_ == capacity_) {
        grow();
    }

    data_[size_] = value;
    ++size_;
}

template <typename T>
void MyVector<T>::pop_back() {
    if (size_ > 0) {
        --size_;
    }
}

template <typename T>
T& MyVector<T>::operator[](std::size_t index) {
    return data_[index];
}

template <typename T>
std::size_t MyVector<T>::size() const {
    return size_;
}