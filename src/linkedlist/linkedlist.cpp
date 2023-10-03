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


template class LinkedList<int>;