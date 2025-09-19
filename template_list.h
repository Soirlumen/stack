#ifndef TEMPLATE_LIST_H
#define TEMPLATE_LIST_H

#include <iostream>
#include <exception>

template <typename T>
class Node {
private:
    T data;
    Node* next;


public:
    Node(T _d, Node* _n = nullptr) : data(_d), next(_n) {
    }
    T getData() const {
        return data;
    }

    Node* getNext() const {
        return next;
    }

    void setNext(Node* _n) {
        next = _n;
    }
};

template <typename T>
class SingleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* actual;
    size_t number_of_things;

public:
    SingleLinkedList() : head(nullptr), tail(nullptr), actual(nullptr),number_of_things(0) {
    }
    //kopírovací konstruktor
    SingleLinkedList(const SingleLinkedList<T> &other):head(nullptr), tail(nullptr), actual(nullptr),number_of_things(0) {
        Node<T>* curr = other.head;
        while (curr != nullptr) {
            pushBack(curr->getData());
            curr = curr->getNext();
        }
    }

    ~SingleLinkedList() {
        blowUpSLL();
    }
    size_t getNumberOfThings()const{
        return number_of_things;
    }
    void blowUpSLL() {
        Node<T>* pom = head;
        while (pom != nullptr) {
            Node<T>* dalsi = pom->getNext();
            delete pom;
            pom = dalsi;
        }
        head = tail = actual = nullptr;
        number_of_things=0;
    }

    bool isEmpty()const {
        return head == nullptr;
    }

    void pushBack(T _d) {
        Node<T>* pom = new Node<T>(_d, nullptr);
        if (isEmpty()) {
            head = tail = actual = pom;
        } else {
            tail->setNext(pom);
            tail = pom;
        }
        number_of_things++;
    }

    void pushFront(T _d) {
        Node<T>* pom = new Node<T>(_d, head);
        head = pom;
        if (tail == nullptr) {
            tail = pom; }
        number_of_things++;
    }

    T popFront() {
        if (isEmpty()) {
            throw std::out_of_range("Seznam je prazdny");
        }
        Node<T>* pom = head;
        T hodnota = pom->getData();
        head = head->getNext();
        if (head == nullptr) {
            tail = nullptr;
        }
        delete pom;
        number_of_things--;
        return hodnota;
    }

    T popBack() {
        if (isEmpty()) {
            throw std::out_of_range("Seznam je prazdny");
        }
        if (head == tail) {
            T hodnota = head->getData();
            delete head;
            head = tail = nullptr;
            number_of_things--;
            return hodnota;
        }
        // najde předposlední
        Node<T>* pom = head;
        while (pom->getNext() != tail) {
            pom = pom->getNext();
        }
        T hodnota = tail->getData();
        delete tail;
        tail = pom;
        tail->setNext(nullptr);
        number_of_things--;
        return hodnota;
    }


    Node<T>* firstNode() const {
        return head;
    }

    Node<T>* lastNode() const {
        return tail;
    }

    bool find(T _d) {
        for (Node<T>* pom = head; pom != nullptr; pom = pom->getNext()) {
            if (pom->getData() == _d) {
                actual = pom;
                return true;
            }
        }
        return false;
    }

    T getActualValue() const {
        if (isEmpty() || actual == nullptr) {
            throw std::out_of_range("seznam je prazden");
        }
        return actual->getData();
    }

    void printy() const {
        Node<T>* pom = head;
        std::cout << "[ ";
        while (pom != nullptr) {
            std::cout << pom->getData();
            if (pom->getNext() != nullptr) {
                std::cout << " -> ";
            }
            pom = pom->getNext();
        }
        std::cout << " ]" << std::endl;
    }

    bool remove(const T& x) {
        if (isEmpty()) return false;

        if (head->getData() == x) {
            Node<T>* pom = head;
            head = head->getNext();
            if (pom == tail) {
                tail = nullptr;
            }
            delete pom;
            number_of_things--;
            return true;
        }

        Node<T>* pred = head;
        Node<T>* pom = head->getNext();

        while (pom != nullptr) {
            if (pom->getData() == x) {
                pred->setNext(pom->getNext());
                if (pom == tail) {
                    tail = pred;
                }
                delete pom;
                number_of_things--;
                return true;
            }
            pred = pom;
            pom = pom->getNext();
        }

        return false;
    }
};

#endif // TEMPLATE_LIST_H
