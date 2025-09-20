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
    CircularList() : head(nullptr), current(nullptr), count(0) {}

    ~CircularList() {
        if (head == nullptr) return;
        
        Node* temp = head->next;
        while (temp != head) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        delete head;
        head = nullptr;
        current = nullptr;
        count = 0;
    }

    bool isEmpty() const {
        return count == 0;
    }

    int size() const {
        return count;
    }

    void append(T value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            current = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        count++;
    }

    T getCurrent() {
        if (current == nullptr) {
            throw "List is empty";
        }
        return current->data;
    }

    void step() {
        if (current != nullptr) {
            current = current->next;
        }
    }

    void reset() {
        current = head;
    }
};

#endif
