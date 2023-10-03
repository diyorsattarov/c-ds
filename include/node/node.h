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
    T getData();
};

#endif // NODE_H