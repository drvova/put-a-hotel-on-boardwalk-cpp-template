#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

template<typename T>
class CircularList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };
    Node* head;
    Node* current;
    int count;

public:
    CircularList();
    ~CircularList();
    
    bool isEmpty() const;
    int size() const;
    
    void append(T value);
    T getCurrent();
    void step();
    void reset();
};

#endif
