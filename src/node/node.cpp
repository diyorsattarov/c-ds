#include <iostream>
#include <node/node.h>

template <class T> Node<T>::~Node() { delete Data; }

template <class T> Node<T>::Node() : Data(nullptr), next(nullptr), prev(nullptr) {}

template <class T> Node<T>::Node(T obj) : Data(new T(obj)), next(nullptr), prev(nullptr) {}

template <class T>
T Node<T>::getData() {
    if (Data == nullptr) {
        throw std::runtime_error("Data is nullptr");
    }
    return *Data;
}

template class Node<int>;