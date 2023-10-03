#include <linkedlist/linkedlist.h>

template <class T> LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& source) : head(nullptr), tail(nullptr) {
    Node<T>* current = source.head;
    Node<T>* node = new Node<T>(current->getData());
    head = node;
    node->setPrev(nullptr);
    while (current != source.tail) {
        Node<T>* newNode = new Node<T>(current->getNext()->getData());
        node->setNext(newNode);
        newNode->setPrev(node);
        node = newNode;
        current = current->getNext();
    }
    tail = node;
    node->setNext(nullptr);
}

template <class T>
bool LinkedList<T>::Push(T obj) {
    std::lock_guard<std::mutex> lock(listMutex);  // Lock the list for thread safety

    Node<T>* newNode = new Node<T>(obj);
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->setNext(newNode);
        newNode->setPrev(tail);
        tail = newNode;
    }
    return true;

}

template <class T>
int LinkedList<T>::Size() const {
    std::lock_guard<std::mutex> lock(listMutex);  // Lock the list for thread safety

    int size = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        ++size;
        current = current->getNext();
    }
    return size;
}


template class LinkedList<int>;