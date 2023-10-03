#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <node/node.h>

template <class T>
class LinkedList {
private:
    Node<T> *head, *tail;
public:
    LinkedList();
    LinkedList(const LinkedList& source);
    virtual ~LinkedList() {}

    virtual int Size() const { return 0; }
    virtual bool Empty() const { return 0; }
    virtual bool Push(T obj) { return 0; }
    virtual bool Pop() { return 0; }
    virtual bool Clear() { return 0; }
};

#endif //LINKEDLIST_H