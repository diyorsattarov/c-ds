#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <node/node.h>
#include <mutex>

template <class T>
class LinkedList {
private:
    mutable std::mutex listMutex;
public:
    Node<T> *head, *tail; 
    LinkedList();
    LinkedList(const LinkedList& source);
    virtual ~LinkedList() {}

    bool Push(T obj);
    int Size() const;

    virtual bool Empty() const { return 0; }
    virtual bool Pop() { return 0; }
    virtual bool Clear() { return 0; }
};

#endif //LINKEDLIST_H