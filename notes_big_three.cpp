#include <iostream>
#include <string>
using namespace std;


/** COPY CONSTRUCTORS, ASSIGNMENT OPERATORS, AND DESTRUCTORS: THE BIG THREE
 *
 * WHEN TO USE: WHEN USING DYNAMIC MEMORY, USING ONE MEANS USING THREE
 *
 * Three class member functions: allow further use of classes and use of classes with heap memory.
 * If not declared, these functions are IMPLICITLY CREATED for you by the compiler.
 * Purpose: dynamically allocated data must be copied differently due to pointers.
 * Programs copy lots of objects and the data they contain.
 *
 * COPY CONSTRUCTOR:
     * Used to construct an object from another existing object.
     * Special constructor called only when a class object is initialized with another instance of the same class.
     * No return type.
     * Purpose: construct a new object as a copy of another object
     *
     * ClassName a;  // Constructor
     * ClassName b(a);  // Copy Constructor - makes object b as copy of object a
     * ClassName c = a;  // Copy Constructor, different syntax
     *
     * Similarly:
     * int x = 5;  // Construct an integer
     * int y = x;  // Construct y as a copy of x
     *
     * Copy Constructor for CLASS:
         * ClassName(const ClassName& otherObject);  // class Copy Constructor, public function within a class
         * Parameters: object of same class type (const ClassName&) and template prior object (otherObject)
         * "const" keyword makes it so object passed in as a constant and won't be changed
         * & means PASS-BY REFERENCE: instead of making copy of object in function, the object itself is passed in
         *
         * All of attributes/functions of prior class object can be copied into new class object
         *
 * COPY ASSIGNMENT OPERATOR:
     * Used to copy one object into another object. Similar to copy constructors.
     * Differences:
         * Overwrites existing values (copy constructors have no 'old' values to overwrite)
         * Can be invoked more than once on an object (copy constructors can only be called once)
     * Copy assignment operator is called when existing object is assigned to another existing object.
     * For dynamic memory, copy doesn't just copy pointer, but copies object at pointer's memory address.
     *
     * Parameter: constant reference
     * Return: reference to an object: return *this;
     *
     * "this" is a pointer to an object, not an object.
     * By dereferencing "this" we get an object which we can bind to a reference.
     * Reason: Help copy constructor and copy assignment
     * Operator assigns "that" into "this"
     *
 * DESTRUCTOR:
     * Automatically called when object is destroyed - when it falls out of scope.
     * Or called when delete is called on pointer to object.
     * Purpose: clean up, shuts down object, clears allocated memory. Can display a destructed message/function.
     *
     * Syntax (within a class): ~ClassName() {functions};
     * Syntax (outside class): ClassName::~ClassName() {functions};
     *
 * DEEP COPY VS. SHALLOW COPY:
     * Copying pointers is a SHALLOW COPY, only copying location the pointer stores (same data stored in same place)
     * DEEP COPY: copying data itself, needs to allocate more space for copy of data, stored at new address
 *
 * RULE OF THREE:
     * If one of Big Three functions written, OTHER TWO should also be written.
     * If you write a destructor to clean up dynamic memory, deep copy support is needed from other two functions.
     *
 * PASS-BY REFERENCE FORMAT: object itself passed in instead of a copy being made for the function
     * Syntax: type FunctionName (const type& ObjectName) {function body;}
     * CONST keyword used to maintain that passed in object isn't modified
 *
 */

/**
// EXAMPLE CLASS WITH ALL OF BIG THREE
class ExampleClass {
    string _name;
    int _quantity;
    float _price;

public:
    ExampleClass(const ExampleClass& otherObject);  // Copy Constructor
    ExampleClass& operator=(const ExampleClass& otherObject);  // Copy Assignment Operator
    // Essentially overloading the function = with operator

    // CLASS DESTRUCTOR
    ~ExampleClass() {
        cout << "Destructor for ExampleClass initiated." << endl;
    };
};

// Copy Constructor: creates shallow copy of class
ExampleClass::ExampleClass(const ExampleClass& otherObject) {
    // const ExampleClass& is a fast pass-by reference, which can't be modified
    // Copy EVERYTHING from "otherObject" into "this"
    this->_name = otherObject._name;
    this->_quantity = otherObject._quantity;
    this->_price = otherObject._price;
}

// Copy Assignment Operator
ExampleClass& ExampleClass::operator=(const ExampleClass& otherObject) {
    // Copy EVERYTHING from "otherObject" into "this"
    _name = otherObject._name;
    _quantity = otherObject._quantity;
    _price = otherObject._price;

    return *this;  // ALWAYS the last line of program
}

int main() {

    // SHALLOW COPY EXAMPLE: Simple Array
    int* ptr = new int[5];  // creates pointer to allocated memory for array of 5 integers
    for (int i=0;i<5;i++) {
        ptr[i] = i*2;  // sets values to 0,2,4,6,8
    }
    // Why not dereference the pointer? Brackets for pointers to array dereference for us.
    int* copy = ptr;  // Creates shallow copy of the array address to new pointer "copy".
    // Still only the one array of 5 integers stored in the heap address.

    // DEEP COPY EXAMPLE: Two steps -
    // (1) Allocate space for duplicate data, new data stored in pointer "deep"
    int* deep = new int[5];  // syntax: type* deep_copy_pointer = new value;
    // (2) Copy the data values from the original location
    for (int i=0;i<5;i++) {
        deep[i] = ptr[i];
    }
    // Deep copy made, so all data is duplicated into more allocated storage space in heap (new address).

    // Delete heap data, cleanup
    delete[] ptr;
    delete[] deep;

    return 0;
}
 */