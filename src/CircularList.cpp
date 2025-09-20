#include "CircularList.hpp"
#include <string>

template<typename T>
CircularList<T>::CircularList() : head(nullptr), current(nullptr), count(0) {}

template<typename T>
CircularList<T>::~CircularList() {
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

template<typename T>
bool CircularList<T>::isEmpty() const {
    return count == 0;
}

template<typename T>
int CircularList<T>::size() const {
    return count;
}

template<typename T>
void CircularList<T>::append(T value) {
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

template<typename T>
T CircularList<T>::getCurrent() {
    if (current == nullptr) {
        throw "List is empty";
    }
    return current->data;
}

template<typename T>
void CircularList<T>::step() {
    if (current != nullptr) {
        current = current->next;
    }
}

template<typename T>
void CircularList<T>::reset() {
    current = head;
}

template class CircularList<int>;
template class CircularList<std::string>;
template class CircularList<double>;
template class CircularList<float>;
template class CircularList<char>;
