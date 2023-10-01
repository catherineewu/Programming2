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

    unsigned int _size = 0;
    Node* head = nullptr;
    Node* tail = nullptr;
    bool _copy;

    /** CONSTRUCTORS / DESTRUCTOR */
    LinkedList() {
        // Default Constructor
        _copy = false;
        // cout << "default constructor called" << endl;
    }
    LinkedList(const LinkedList<T>& rhs) {
        // Copy constructor
        // cout << "copy constructor called" << endl;
        this->_copy = true;
        this->_size = rhs._size;
        this->head = rhs.head;
        this->tail = rhs.tail;

        Node* currentNode = head;
        Node* copyNode = this->head;
        while (currentNode->_next != nullptr) {
            copyNode->_next = currentNode->_next;
            copyNode->_previous = currentNode->_previous;
            currentNode = currentNode->_next;
            copyNode = copyNode->_next;
        }
    }
    LinkedList<T>& operator=(const LinkedList<T>& rhs) {
        // Copy assignment operator
        // cout << "copy assignment operator called" << endl;
        _size = 0;

        head = nullptr;
        tail = nullptr;

        Node* currentNode = rhs.head;
        while (currentNode != nullptr) {
            this->AddTail(currentNode->_data);
            currentNode = currentNode->_next;
        }
        return *this;
    }
    ~LinkedList() {
        // Destructor
        // cout << "destructor called" << endl;
        if (this->_copy == true) {
            // cout << "constructed copy - destructor skipped" << endl;
            head = nullptr;
            tail = nullptr;
        } else {
            Node* currentNode = this->head;  // currentNode is temp. variable that iterates through nodes
            while (currentNode != nullptr) {
                if (currentNode->_next != nullptr) {
                    currentNode = currentNode->_next;
                    delete currentNode->_previous;
                } else {
                    delete currentNode;
                    currentNode = nullptr;
                    head = nullptr;
                    tail = nullptr;
                }
            }
        }
    }  // FIXME (not checked for memory leak)

    /** OPERATORS */ /**
    const T& LinkedList::operator[]=(unsigned int index) const {
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
        return currentNode->_data;
    }  // FIXME
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
        return currentNode->_data;
    }  // FIXME

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
            currentNode = currentNode->_next;
            compareNode = compareNode->_next;
        }
        return true;
    }  // FIXME
 */

    /** BEHAVIORS */
    void PrintForward() const {
        // PRINTFORWARD: Iterate through all nodes and print values in order
        Node* currentNode = this->head;  // currentNode is temp. variable that iterates through nodes
        while (currentNode != nullptr) {
            cout << currentNode->_data << endl;
            currentNode = currentNode->_next;
        }
    }
    void PrintReverse() const {
        // PRINTREVERSE: Iterate backwards through nodes and print values in reverse order
        Node* currentNode = this->tail;  // currentNode is temp. variable that iterates through nodes
        while (currentNode != nullptr) {
            cout << currentNode->_data << endl;
            currentNode = currentNode->_previous;
        }
    }

    /**
    void PrintForwardRecursive(const Node* node) const {
        // Parameter is pointer to any starting node
        // From starting node, recursively visit every following node
        // Forward order, print values of nodes
        if (node->_next == nullptr) {
            cout << node->_data << endl;
        }
        else {
            cout << node->_data << endl;
            return const PrintForwardRecursive(const node->_next);
        }
    }  // FIXME
    void PrintReverseRecursive(const Node* node) const {
        // Parameter is pointer to any starting node
        // From starting node, recursively visit every previous node
        // Reverse order, print values of nodes
        if (node->_previous == nullptr) {
            cout << node->_data << endl;
        }
        else {
            cout << node->_data << endl;
            return const PrintReverseRecursive(const node->_previous);
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
            if (currentNode->_data == value) {
                outData.push_back(currentNode);
            }
        currentNode = currentNode->_next;
        }
    }

    const Node* Find(const T& data) const {
        // Find 1st node with data value matching passed in parameter
        // Return pointer to that node, or nullptr if none matching found
        Node* currentNode = this->head;
        while (currentNode != nullptr) {
            if (currentNode->_data == data) {
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
            if (currentNode->_data == data) {
                return currentNode;
            }
            currentNode = currentNode->_next;
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
            currentNode = currentNode->_next;
        }
        return currentNode;
    }
    const Node* GetNode(const unsigned int index) const {  // const version
        if (index >= _size) {
            throw out_of_range("Index out of range.");
        }
        Node* currentNode = this->head;
        for (unsigned int i=0; i<index; i++) {
            currentNode = currentNode->_next;
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
            // cout << "first node added with data " << this->head->_data << endl;
        } else {
            this->head->_previous = new Node(data);
            this->head->_previous->_next = this->head;
            this->head = this->head->_previous;
            // cout << "new head added with data " << this->head->_data << endl;
        }
        _size += 1;
    }
    void AddTail(const T& data) {
        // Create new Node at end of list to store the passed in parameter
        if (_size == 0) {
            // Create first node
            this->head = new Node(data);
            this->tail = this->head;
            // cout << "first node added with data " << this->head->_data << endl;
        } else {
            this->tail->_next = new Node(data);
            this->tail->_next->_previous = this->tail;
            this->tail = this->tail->_next;
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