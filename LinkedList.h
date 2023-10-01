#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#pragma once
using namespace std;

template <class T>
class LinkedList {
public:
    class Node {
    public:
        T data;
        Node* next = nullptr;
        Node* prev = nullptr;
        Node() {
            // cout << "node default constructor" << endl;
        }

        explicit Node(T data) {
            this->data = data;
            // cout << "node param constructor" << endl;
        }
    };

    unsigned int _size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    bool _copy = false;

    /** CONSTRUCTORS / DESTRUCTOR */
    LinkedList() {
        // Default Constructor
        _copy = false;
        // cout << "default constructor called" << endl;
    }
    /** SHALLOW COPY: LinkedList(const LinkedList<T>& rhs) {
        // Copy constructor
        // cout << "copy constructor called" << endl;
        this->_copy = true;
        this->_size = rhs._size;
        this->head = rhs.head;
        this->tail = rhs.tail;

        Node* currentNode = rhs.head;
        Node* copyNode = this->head;
        while (currentNode->next != nullptr) {
            copyNode->next = currentNode->next;
            copyNode->prev = currentNode->prev;
            currentNode = currentNode->next;
            copyNode = copyNode->next;
        }
    }*/
    LinkedList(const LinkedList<T>& rhs) {
        // Copy constructor
        // cout << "copy constructor called" << endl;
        this->_size = 0;
        this->_copy = true;
        this->head = nullptr;
        this->tail = nullptr;

        Node* currentNode = rhs.head;
        while (currentNode != nullptr) {
            this->AddTail(currentNode->data);
            currentNode = currentNode->next;
        }
    }
    LinkedList<T>& operator=(const LinkedList<T>& rhs) {
        // Copy assignment operator
        // cout << "copy assignment operator called" << endl;
        _size = 0;
        _copy = false;

        head = nullptr;
        tail = nullptr;

        Node* currentNode = rhs.head;
        while (currentNode != nullptr) {
            this->AddTail(currentNode->data);
            currentNode = currentNode->next;
        }
        delete currentNode;
        return *this;
    }
    ~LinkedList() {
        // Destructor
        // cout << "destructor called" << endl;
        /**if (this->_copy == true) {
            // cout << "constructed copy - destructor skipped" << endl;
            Node* currentNode = this->head;
            while (currentNode != nullptr) {
                if (currentNode->prev != nullptr) {
                    currentNode = currentNode->prev;
                    delete currentNode->next;
                } else {
                    delete currentNode;
                    currentNode = nullptr;
                    head = nullptr;
                    tail = nullptr;
                }
            }
        } else {
            Node* currentNode = this->head;  // currentNode is temp. variable that iterates through nodes
            while (currentNode != nullptr) {
                if (currentNode->next != nullptr) {
                    currentNode = currentNode->next;
                    delete currentNode->prev;
                } else {
                    delete currentNode;
                    currentNode = nullptr;
                    head = nullptr;
                    tail = nullptr;
                }
            }
        }*/
        Node* currentNode = this->head;  // currentNode is temp. variable that iterates through nodes
        while (currentNode != nullptr) {
            if (currentNode->next != nullptr) {
                currentNode = currentNode->next;
                delete currentNode->prev;
            } else {
                delete currentNode;
                currentNode = nullptr;
                head = nullptr;
                tail = nullptr;
            }
        }
    }  // FIXME (not checked for memory leak)

    /** OPERATORS */
    const T& operator[](unsigned int index) const {
        // Const version: Overload subscript operator, returns data from index-th node
        // Throws out_of_range exception for invalid index
        cout << "const operator[] called" << endl;
        if (index >= _size) {
            throw out_of_range("Index out of range.");
        }
        Node* currentNode = this->head;
        for (unsigned int i=0; i<index; i++) {
            currentNode = currentNode->next;
        }
        return currentNode->data;
    }  // FIXME (using const)
    T& operator[](unsigned int index) {
        // Overload subscript operator, returns data from index-th node
        // Throws out_of_range exception for invalid index
        cout << "operator[] called" << endl;
        if (index >= _size) {
            throw out_of_range("Index out of range.");
        }
        Node* currentNode = this->head;
        for (unsigned int i=0; i<index; i++) {
            currentNode = currentNode->next;
        }
        return currentNode->data;
    }

/**
    bool operator==(const LinkedList<T>& rhs) const {
        // Overloaded equality operator
        // Is listA equal to listB (each node == to corresponding node of other)?
        cout << "bool operator called" << endl;
        if (this->_size != rhs._size) {
            return false;
        }
        Node* currentNode = this->head;
        Node* compareNode = rhs.head;
        while (currentNode != nullptr) {
            if (currentNode->_data != compareNode->_data) {
                return false;
            }
            currentNode = currentNode->next;
            compareNode = compareNode->next;
        }
        return true;
    }  // FIXME
 */

    /** BEHAVIORS */
    void PrintForward() const {
        // PRINTFORWARD: Iterate through all nodes and print values in order
        Node* currentNode = this->head;  // currentNode is temp. variable that iterates through nodes
        while (currentNode != nullptr) {
            cout << currentNode->data << endl;
            currentNode = currentNode->next;
        }
    }
    void PrintReverse() const {
        // PRINTREVERSE: Iterate backwards through nodes and print values in reverse order
        Node* currentNode = this->tail;  // currentNode is temp. variable that iterates through nodes
        while (currentNode != nullptr) {
            cout << currentNode->data << endl;
            currentNode = currentNode->prev;
        }
    }

    /**
    void PrintForwardRecursive(const Node* node) const {
        // Parameter is pointer to any starting node
        // From starting node, recursively visit every following node
        // Forward order, print values of nodes
        if (node->next == nullptr) {
            cout << node->_data << endl;
        }
        else {
            cout << node->_data << endl;
            return const PrintForwardRecursive(const node->next);
        }
    }  // FIXME
    void PrintReverseRecursive(const Node* node) const {
        // Parameter is pointer to any starting node
        // From starting node, recursively visit every previous node
        // Reverse order, print values of nodes
        if (node->prev == nullptr) {
            cout << node->_data << endl;
        }
        else {
            cout << node->_data << endl;
            return const PrintReverseRecursive(const node->prev);
        }
    }  // FIXME */

    /** ACCESSOR FUNCTIONS */
    unsigned int NodeCount() const {
        // Returns number of nodes in list
        return _size;}

    void FindAll(vector<Node*>& outData, const T& value) const {
        // Find all noes matching parameter
        // Store pointer to node in passed in vector (output parameter)
        Node* currentNode = this->head;
        while (currentNode != nullptr) {
            if (currentNode->data == value) {
                outData.push_back(currentNode);
            }
        currentNode = currentNode->next;
        }
    }

    const Node* Find(const T& data) const {
        // Find 1st node with data value matching passed in parameter
        // Return pointer to that node, or nullptr if none matching found
        Node* currentNode = this->head;
        while (currentNode != nullptr) {
            if (currentNode->data == data) {
                return currentNode;
            }
            currentNode = currentNode->next;
        }
        return nullptr;
    }  // FIXME (using const)
    Node* Find(const T& data) {
        // Const version
        // Find 1st node with data value matching passed in parameter
        // Return pointer to that node, or nullptr if none matching found
        Node* currentNode = this->head;
        while (currentNode != nullptr) {
            if (currentNode->data == data) {
                return currentNode;
            }
            currentNode = currentNode->next;
        }
        return nullptr;
    }

    Node* GetNode(unsigned int index) {
        // Return pointer to node at passed in index
        if (index >= _size) {
            throw out_of_range("Index out of range.");  // FIXME (message?)
        }
        Node* currentNode = this->head;
        for (unsigned int i=0; i<index; i++) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }
    const Node* GetNode(const unsigned int index) const {  // const version
        if (index >= _size) {
            throw out_of_range("Index out of range.");
        }
        Node* currentNode = this->head;
        for (unsigned int i=0; i<index; i++) {
            currentNode = currentNode->next;
        }
        return currentNode;
    }  // FIXME (using const)

    Node* Head() {
        // Returns head pointer
        // cout << "head" << endl;
        return head;
    }
    Node* Tail() {
        // Returns tail pointer
        // cout << "tail" << endl;
        return tail;
    }

    const Node* Head() const {
        // cout << "const head" << endl;
        return head;
    }  // FIXME (using const)
    const Node* Tail() const {
        // cout << "const tail" << endl;
        return tail;
    }  // FIXME (using const)


    /** INSERTION OPERATIONS */
    void AddHead(const T& data) {
        // Create new Node at front of list to store the passed in parameter
        if (_size == 0) {
            // Create first node
            this->head = new Node(data);
            this->tail = this->head;
            // cout << "first node added with data " << this->head->data << endl;
        } else {
            this->head->prev = new Node(data);
            this->head->prev->next = this->head;
            this->head = this->head->prev;
            // cout << "new head added with data " << this->head->data << endl;
        }
        _size += 1;
    }
    void AddTail(const T& data) {
        // Create new Node at end of list to store the passed in parameter
        if (_size == 0) {
            // Create first node
            this->head = new Node(data);
            this->tail = this->head;
            // cout << "first node added with data " << this->head->data << endl;
        } else {
            this->tail->next = new Node(data);
            this->tail->next->prev = this->tail;
            this->tail = this->tail->next;
        }
        _size += 1;
    }

    void AddNodesHead(T ptr[], unsigned int size) {
        // Given an array of values, insert a node for each
        // of those at the beginning list in original order.
        for (int i=(size-1); i>=0; i--) {
            this->AddHead(ptr[i]);
        }
    }
    void AddNodesTail(T ptr[], unsigned int size) {
        // Same as for AddNodesHead, but at end of list
        for (int i=0; i<size; i++) {
            this->AddTail(ptr[i]);
        }
    }

};