#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#pragma once
using namespace std;

template <class T>
class LinkedList {
public:
    class Node {
    public:
        T _data;
        Node* _next = nullptr;
        Node* _previous = nullptr;
        Node() {
            // cout << "node default constructor" << endl;
        }

        explicit Node(T data) {
            _data = data;
            // cout << "node param constructor" << endl;
        }
    };

    int _size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;

    // CONSTRUCTORS
    // Default Constructor
    LinkedList() {
    }
    // Destructor
    ~LinkedList() {
        Node* currentNode = this->head;  // currentNode is temp. variable that iterates through nodes
        Node* nextNode = currentNode;
        for (int i=0;i<_size;i++) {
            currentNode = nextNode;
            nextNode = currentNode->_next;
            // cout << "deleting node with value " << currentNode->_data << endl;
            delete[] currentNode;
        }
    }

    // INSERTION OPERATIONS
    // Create new Node at front of list to store the passed in parameter
    void AddHead(T data) {
        if (_size == 0) {
            // Create first node
            this->head = new Node(data);
            this->tail = this->head;
            // cout << "first node added with data " << this->head->_data << endl;
        } else {
            this->head->_previous = new Node(data);
            this->head->_previous->_next = this->head;
            this->head = this->head->_previous;
            // cout << "new head added with data " << this->head->_data << endl;
        }
        _size += 1;
    }

    // Create new Node at end of list to store the passed in parameter
    void AddTail(T data) {
        if (_size == 0) {
            // Create first node
            this->head = new Node(data);
            this->tail = this->head;
            // cout << "first node added with data " << this->head->_data << endl;
        } else {
            this->tail->_next = new Node(data);
            this->tail->_next->_previous = this->tail;
            this->tail = this->tail->_next;
            // cout << "add tail of position " << _size + 1 << " with value " << data << endl;
        }
        _size += 1;
    }

    // Given an array of values, insert a node for each
    // of those at the beginning list in original order.
    void AddNodesHead(T ptr[], int size) {
        for (int i=(size-1); i>=0; i--) {
            this->AddHead(ptr[i]);
        }
        // cout << "finished adding array to head" << endl;
    }
    // Same as for AddNodesHead, but at end of list
    void AddNodesTail(T ptr[], int size) {
        for (int i=0; i<size; i++) {
            this->AddTail(ptr[i]);
        }
        // cout << "finished adding array to tail" << endl;
    }

    // GET INFORMATION ABOUT CONTAINER
    int NodeCount() {
        return _size;
    }

    // SEE DATA IN CONTAINER
    // Iterate through all nodes and print values in order
    void PrintForward() {
        Node* currentNode = this->head;  // currentNode is temp. variable that iterates through nodes
        for (int i=0;i<_size;i++) {
            cout << currentNode->_data << endl;
            currentNode = currentNode->_next;
        }
    }
    // Iterate backwards through nodes and print values in reverse order
    void PrintReverse() {
        Node* currentNode = this->tail;  // currentNode is temp. variable that iterates through nodes
        for (int i=0; i<_size; i++) {
            cout << currentNode->_data << endl;
            currentNode = currentNode->_previous;
        }
    }

};

template <>
class LinkedList<string> {
public:
    class Node {
    public:
        char* _data;
        int _length;
        Node* _next;
        Node* _previous;
        Node() {
            _next = nullptr;
            _previous = nullptr;
            // cout << "node default constructor" << endl;
        }

        explicit Node(string data) {
            _length = data.length();
            _data = new char[_length];
            for (int i=0;i<_length;i++) {
                _data[i] = data[i];
            }
            _next = nullptr;
            _previous = nullptr;
            // cout << "node param constructor" << endl;
        }
    };

    int _size;
    Node* head;
    Node* tail;

    // CONSTRUCTORS
    // Default Constructor
    LinkedList() {
        _size = 0;
    }
    // Destructor
    ~LinkedList() {
        Node* currentNode = this->head;  // currentNode is temp. variable that iterates through nodes
        Node* nextNode = currentNode;
        for (int i=0;i<_size;i++) {
            currentNode = nextNode;
            nextNode = currentNode->_next;
            // cout << "deleting node with value " << currentNode->_data << endl;
            delete[] currentNode->_data;
            delete[] currentNode;
        }
    }

    // INSERTION OPERATIONS
    // Create new Node at front of list to store the passed in parameter
    void AddHead(string data) {
        if (_size == 0) {
            // Create first node
            this->head = new Node(data);
            this->head->_previous = nullptr;
            this->head->_next = nullptr;
            this->tail = this->head;
            // cout << "first node added with data " << this->head->_data << endl;
        } else {
            this->head->_previous = new Node(data);
            this->head->_previous->_previous = nullptr;
            this->head->_previous->_next = this->head;
            this->head = this->head->_previous;
            // cout << "new head added with data " << this->head->_data << endl;
        }
        _size += 1;
    }

    // Create new Node at end of list to store the passed in parameter
    void AddTail(string data) {
        if (_size == 0) {
            // Create first node
            this->head = new Node(data);
            this->head->_previous = nullptr;
            this->head->_next = nullptr;
            this->tail = this->head;
            // cout << "first node added with data " << this->head->_data << endl;
        } else {
            this->tail->_next = new Node(data);
            this->tail->_next->_previous = this->tail;
            this->tail->_next->_next = nullptr;
            this->tail = this->tail->_next;
            // cout << "add tail of position " << _size + 1 << " with value " << data << endl;
        }
        _size += 1;
    }

    // Given an array of values, insert a node for each
    // of those at the beginning list in original order.
    void AddNodesHead(string ptr[], int size) {
        for (int i=(size-1); i>=0; i--) {
            this->AddHead(ptr[i]);
        }
        // cout << "finished adding array to head" << endl;
    }
    // Same as for AddNodesHead, but at end of list
    void AddNodesTail(string ptr[], int size) {
        for (int i=0; i<size; i++) {
            this->AddTail(ptr[i]);
        }
        // cout << "finished adding array to tail" << endl;
    }

    // GET INFORMATION ABOUT CONTAINER
    int NodeCount() {
        return _size;
    }

    // SEE DATA IN CONTAINER
    // Iterate through all nodes and print values in order
    void PrintForward() {
        Node* currentNode = this->head;  // currentNode is temp. variable that iterates through nodes
        while (currentNode != nullptr) {
            cout << currentNode->_data << endl;
            currentNode = currentNode->_next;
        }
    }
    // Iterate backwards through nodes and print values in reverse order
    void PrintReverse() {
        Node* currentNode = this->tail;  // currentNode is temp. variable that iterates through nodes
        while (currentNode != nullptr) {
            cout << currentNode->_data << endl;
            currentNode = currentNode->_previous;
        }
    }

};