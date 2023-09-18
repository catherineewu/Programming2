#include <iostream>  // for testing purposes
using namespace std;  // for testing purposes
#pragma once

/**
 * Notes:
 * Since array capacity doesn't change with every addition and deletion of data elements, size is used to keep track of
 * number of 'used' and non-empty elements of the stack. 'Empty' elements aren't actually empty, but have default value of 0.
*/

template <class T>
class ABS
{
private:
    bool copy = false;  // tracks whether instance is a copy, avoids destructor being called twice on same data
public:
    /// INITIALIZE ATTRIBUTES
    T* list;  // pointer to list
    int capacity{};  // capacity size of array (cannot be changed, must make new array to grow or shrink)
    int size{};  // use to keep track of data entering and leaving array (+1 for push, -1 for pop)
    float scale = 2.0f;  // factor to grow or shrink new array

    /// CONSTRUCTORS & BIG THREE
    ABS() {  // default constructor
        this->capacity = 1;
        this->size = 0;
        this->list = new T[capacity];
    }
    explicit ABS(int capacity) {  // parameterized constructor
        this->capacity = capacity;
        this->size = 0;
        this->list = new T[capacity];
    }
    ABS(const ABS &d) {  // copy constructor
        this->copy = true;
        this->capacity = d.capacity;
        this->size = d.size;
        this->list = d.list;  // shallow copy: pointer of new instance points to same address and data
    }
    ABS& operator=(const ABS &d) {  // copy assignment operator
        capacity = d.capacity;
        size = d.size;
        *list = *d.list;  // deep copy: pointer of new instance points to new memory address
        return *this;
    }
    ~ABS() {  // destructor
        if (!copy) {  // FIXME: This implementation may cause issues later (shallow copies cause twice deletion of same pointer).
            delete[] list;
        }
    }

    /// CHANGING CAPACITY: DoubleCapacity and HalfCapacity
private:
    void DoubleCapacity() {
        T data[size];  // create temporary array of data store in stack w/ size & capacity of old array
        for (int i=0; i<size; i++) {  // adds data in order from old array to temp. array
            data[i] = *(list + i);
        }
        delete[] list;  // deletes data in old array
        capacity *= scale;  // grows capacity to scale of 2.0f
        list = new T[capacity];  // allocates memory in same address as old array for new array with larger capacity
        for (int i=0; i<size; i++) {  // adds data from temp. array to new array
            *(list + i) = data[i];
        }
    }
    void HalfCapacity() {
        T data[size];  // create temporary array of data store in stack w/ size & capacity of old array
        for (int i=0; i<size; i++) {  // adds data in order from old array to temp. array
            data[i] = *(list + i);
        }
        delete[] list;  // deletes data in old array
        capacity /= scale;  // divides capacity to scale of 2.0f
        list = new T[capacity];  // allocates memory in same address as old array for new array with less capacity
        for (int i=0; i<size; i++) {  // adds data from temp. array to new array
            *(list + i) = data[i];
        }
    }

    /// DATA RETRIEVAL/GETTER FUNCTIONS: getSize, getMaxCapacity, getData
public:
    unsigned int getSize() {  // returns current number of items in ABS
        return size;
    }
    unsigned int getMaxCapacity() {  // returns max capacity of ABS
        return capacity;
    }
    T* getData() {  // returns array representing the stack (pointer address)
        return list;
    }

    /// PUSH, POP, AND PEEK STACK FUNCTIONS
    void push(T data) {
        if (size==capacity) {  // if stack already at capacity, doubles capacity
            DoubleCapacity();
        }
        *(list + size) = data;  // adds data to top of stack
        size += 1;  // adjusts size variable to reflect new size
    }
    T pop() {
        if (size==0) {  // throw runtime error if stack is empty when pop() called
            throw runtime_error("Stack is empty.");
        }
        T data = *(list + (size - 1));  // store data at top of stack in temp. variable data
        *(list + (size - 1)) = 0;  // "delete" data at top by setting value to 0 (default array value)
        size -= 1;  // adjusts size variable to reflect new size
        if (size<(capacity/scale)) {
            HalfCapacity();
        }
        return data;
    }
    T peek() {
        if (size==0) {
            throw runtime_error("Stack is empty.");
        }
        T data = *(list + (size - 1));
        return data;
    }

    /// TESTING FUNCTIONS: stored in lab3_testing_code.cpp (bottom of file)
};