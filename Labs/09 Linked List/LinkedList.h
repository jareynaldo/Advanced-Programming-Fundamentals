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
        Node *first = T _data;
        Node(T _data,  Node *_next = nullptr): data(_data), next(_next){}
    };

    Node *last = nullptr;

    class Iterator{

        friend class LinkedList<T>;

        Node *current = nullptr;

        // helper methods
        Iterator& operator++(){ this = this -> next;
                                return &this;}
        Iterator& operator--(){ this = this -> previous;
                return &this;}
        bool operator==(Iterator const& rhs){return this = rhs;}
        bool operator!=(Iterator const& rhs){return !(this = rhs);}

        Node previous = this;

        public:
            inline T operator*(){return this-> data;}
            Iterator(Node *d){}


//        inline void reset(){current = current-> first;}
//
//        inline bool inEmpty(){return first == nullptr;}
//        inline bool isEnded(){return current == nullptr;}




    };


    Iterator begin(){return Iterator::first; };

public:
    LinkedList<T>();



};




#endif //LINKEDLIST_LINKEDLIST_H
