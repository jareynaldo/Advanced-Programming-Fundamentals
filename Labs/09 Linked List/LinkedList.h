//
// Created by Jose Reynaldo and Isabella Katz   978 727 3803
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H


template<typename T>
class LinkedList{

    struct Node{
        T data;
        Node *next;
        Node *previous;
        Node(T _data, Node* _previous = nullptr, Node* _next = nullptr) : data(_data), previous(_previous), next(_next) {}
    };


    class Iterator{

        friend class LinkedList<T>;

    private:
        Node *current;
    public:

        // constructor
        Iterator(Node *node): current(node) {}

        // Pre-increment
        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        // Pre-decrement
        Iterator& operator--() {
            if (current) current = current->previous;
            return *this;
        }

        // Dereference operator
        T& operator*() const { return current->data; }

        // Equality check
        bool operator==(const Iterator& other) const { return current == other.current; }

        // Inequality check
        bool operator!=(const Iterator& other) const { return current != other.current; }





    };


private:
    Node* head;
   Node *tail_end;

public:
    LinkedList() : head(nullptr), tail_end(nullptr) {}

    ~LinkedList() {
        clear();
    }


    Iterator begin() const { return Iterator(head); }

    Iterator tail() const { return Iterator(tail_end); }

    Iterator end() const { return nullptr; }

    bool isEmpty() const {
        if (head == nullptr) { return true; }
        return false;
    }

    T getFront() const {
        if(head == nullptr) throw std::runtime_error("List is empty");
        return head->data;
    }
    T getBack() const {   if(tail_end == nullptr) throw std::runtime_error("List is empty");
        return tail_end->data;
    }

    bool contains(T element) const{
        Node* current = head;
        while (current != nullptr) {
            if (current->data == element) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void enqueue(T element) {
        Node* node = new Node(element, tail_end, nullptr);
        if (tail_end) tail_end->next = node;
        tail_end = node;
        if (!head) head = node;
    }

    void dequeue() {
        if (!isEmpty()){
            Node *temp = head;
            head = head->next;
            if (head) head->previous = nullptr;
            else tail_end = nullptr;
            delete temp;
        }
    }


    void pop() {
        if (isEmpty()) {
            return;
        }
        else{
            Node* temp = tail_end;
            tail_end = tail_end->previous;
            if (tail_end) tail_end->next = nullptr;
            else head = nullptr;
            delete temp;
        }

    }

    void clear() {
        while (!isEmpty()) dequeue();
    }

    void remove(T element) {
        for (Node* temp = head; temp != nullptr; temp = temp->next) {
            if (temp->data == element) {
                if (temp->previous) temp->previous->next = temp->next;
                if (temp->next) temp->next->previous = temp->previous;
                if (temp == head) head = temp->next;
                if (temp == tail_end) tail_end = temp->previous;
                delete temp;
                return;
            }
        }
    }
};



#endif //LINKEDLIST_LINKEDLIST_H
