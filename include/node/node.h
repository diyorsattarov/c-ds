#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
private:
    T* Data;
    Node* next, * prev;
public:
    Node();
    ~Node();
    Node(T obj);
    void setData(int i) {
        *Data = i;
    }
    T getData();
    Node* getNext() const { return next; }
    Node* getPrev() const { return prev; }

    void setNext(Node* newNode) {
        next = newNode;
    }

    void setPrev(Node* newNode) {
        prev = newNode;
    }
};

#endif // NODE_H