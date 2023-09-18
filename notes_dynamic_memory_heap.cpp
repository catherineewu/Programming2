/**
#include <iostream>  // cin and cout
using namespace std;

// C++ dynamic memory allocation: new, delete

int main() {
    // NEW OPERATOR: returns memory address for where storage is allocated for an object in the heap.
         // Dynamically allocate int variable and store heap memory address in int pointer created:
         // At compile time: static storage allocated (stack) for pointer.
         // At run time: dynamic (heap) storage allocated for int variable, memory address returned by new and stored in the pointer.
         // Two variables created: (1) unnamed int variable holds int value (2) pointer variable holds memory address.

    // DYNAMICALLY ALLOCATE INTEGERS
    int* int_heap_pointer = new int;

    *int_heap_pointer = 8;  // dereferenced memory address with *pointer, goes to memory address of int stored in heap
    // places int value of 8 in allocated heap storage space

    int* o;
    o = new int;  // same as above with pointer o
    *o = 5;  // 5 is stored in int variable in heap, whose address is stored in o pointer

    // ACCESSING variable stored in heap by dereferencing pointer (*pointer_name)
    int sum = *int_heap_pointer + *o;  // sum variable statically allocated to stack during runtime
    cout << "The sum of " << *int_heap_pointer << " and " << *o << " is " << sum << "." << endl;

    // DELETE OPERATOR: free the memory in heap taken up by the variable whose memory address is stored in pointer
    // Does NOT delete the pointer variables, which are still statically allocated
    delete int_heap_pointer;
    delete o;


    // DYNAMICALLY ALLOCATE ARRAY
    int size;  // statically allocated size variable determined by user input
    int* array_pointer;  // array pointer statically allocated
    cout << "Enter size of array: ";
    cin >> size;

    array_pointer = new int[size];  // create array with dynamic memory allocation, memory address stored in pointer

    for (int i=0; i<size; i++) {  // user input populates values of array
        cout << "Enter value for position " << i << " in array: ";
        cin >> array_pointer[i];  // ARRAY NOTATION to edit specific array element using pointer (no dereferencing) from input
    }

    for (int i=0; i<size; i++) {
        if (i/2==0) {cout << array_pointer[i] << " ";}  // Array Notation
        else {cout << *(array_pointer + i) << " ";}  // Pointer Notation - same thing as above
        // *pointer gives memory address of first object in array, so *(pointer + i) gives address of subsequent objects
    }
    cout << endl;

    // DELETE an entire array, use [] with delete to tell C++ that a collection of data vs. one variable to be deleted
    delete[] array_pointer;


    // pause program, doesn't automatically finish when done running through commands
    cin.ignore();
    cin.get();

    return 0;
}
 */