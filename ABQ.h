#include <iostream>  // for testing purposes
using namespace std;  // for testing purposes
#pragma once

/**Notes:
 * Since array capacity doesn't change with every addition and deletion of data elements, size is used to keep track of
 * number of 'used' and non-empty elements of the queue. 'Empty' elements aren't actually empty, but have default value of 0.*/
template <class T>
class ABQ
{private:
    bool copy = false;  // tracks whether instance is a copy, avoids destructor being called twice on same data
public:
    /// INITIALIZE ATTRIBUTES
    T* list;  // pointer to list
    int capacity{};  // capacity size of array (cannot be changed, must make new array to grow or shrink)
    int size{};  // use to keep track of data entering and leaving array (+1 for push, -1 for pop)
    float scale = 2.0f;  // factor to grow or shrink new array

    /// CONSTRUCTORS & BIG THREE
    ABQ() {  // default constructor
        this->capacity = 1;
        this->size = 0;
        this->list = new T[capacity];
    }
    explicit ABQ(int cap) {  // parameterized constructor
        this->capacity = cap;
        this->size = 0;
        this->list = new T[capacity];
    }
    ABQ(const ABQ &d) {  // copy constructor
        this->copy = true;
        this->capacity = d.capacity;
        this->size = d.size;
        this->list = d.list;  // shallow copy: pointer of new instance points to same address and data
    }
    ABQ& operator=(const ABQ &d) {  // copy assignment operator
        capacity = d.capacity;
        size = d.size;
        *list = *d.list;  // deep copy: pointer of new instance points to new memory address
        return *this;
    }
    ~ABQ() {  // destructor
        if (!copy) {  // FIXME: This implementation may cause issues later (shallow copies cause twice deletion of same pointer).
            delete[] list;
        }
    }
    /// CHANGING CAPACITY: DoubleCapacity and HalfCapacity
private:
    void DoubleCapacity() {
        T data[size];  // create temporary array of data store in queue w/ size & capacity of old array
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
        T data[size];  // create temporary array of data store in queue w/ size & capacity of old array
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
    unsigned int getSize() {  // returns current number of items in ABQ
        return size;
    }
    unsigned int getMaxCapacity() {  // returns max capacity of ABQ
        return capacity;
    }
    T* getData() {  // returns array representing the queue (pointer address)
        return list;
    }

    /// ENQUEUE, DEQUEUE, AND PEEK QUEUE FUNCTIONS
    void enqueue(T data) {
        if (size==capacity) {  // if queue already at capacity, doubles capacity
            DoubleCapacity();
        }
        *(list + size) = data;  // adds data to end of queue
        size += 1;  // adjusts size variable to reflect new size
    }
    T dequeue() {
        if (size==0) {
            throw runtime_error("Queue is empty.");
        }
        T data = *list;  // store data at front of queue in temp. variable data
        for (int i=1;i<size;i++) {  // move each data element 'up' one spot in the queue (memory)
            *(list + i - 1) = *(list + i);
        }
        *(list + size - 1) = 0;
        size -= 1;  // adjusts size variable to reflect new size
        if (size<(capacity/scale)) {
            HalfCapacity();
        }
        return data;
    }
    T peek() {
        if (size==0) {
            throw runtime_error("Queue is empty.");
        }
        T data = *list;
        return data;
    }

    /// TESTING FUNCTIONS: stored in lab3_testing_code.cpp (bottom of file)

};
