/**#include <iostream>
#include <string>
using namespace std;

class example {
    // assign "nice" names to parameters vs. attributes, since parameters are in UI
    string _name;
    int* _ptr;
public:
    example();  // default constructor
    example(const string& name, const int& value);  // parameterized constructor
    example(const example& otherObject);  // copy constructor
    example& operator=(const example& otherObject);  // copy assignment operator
    ~example();  // destructor

    void printData();
};

example::example() {  // definition for default constructor
    _name = "default";
    _ptr = new int;  // assign printer to allocated storage for int in heap
    *_ptr = 0;  // dereference pointer to assign value for int in storage
    cout << "(default constructor called)" << endl;
}
example::example(const string& name, const int& value) {  // definition for parameterized constructor
    _name = name;
    _ptr = new int;  // still need to create memory allocation in heap for int for parameterized constructor
    *_ptr = value;
    cout << "(parameterized constructor called)" << endl;
}
example::~example() {
    delete _ptr;  // pointer created and stored in stack, deleting pointer clears storage for data in pointer location
    // pointer deletion handled automatically
    cout << "(destructor called)" << endl;

}
example::example(const example &otherObject) {  // definition for copy constructor
    // constructs a new object from existing object
    this->_name = otherObject._name + "!";
    this->_ptr = otherObject._ptr;
    cout << "(copy constructor called)" << endl;
}
example& example::operator=(const example& otherObject) {  // definition for copy assignment operator
    // takes values from one object and assigns them to another object
    _name = otherObject._name + "!!";
    *_ptr = *otherObject._ptr;  // makes POINTER DEEP COPY
    // _ptr = otherObject._ptr;  // this method makes both pointers access the same address and object, MAKES POINTER SHALLOW COPY
    cout << "(copy assignment operator called)" << endl;
    return *this;
}
void example::printData() {
    cout << "Name: " << _name << ", Value: " << *_ptr << endl;
}

int main() {
    example one;
    one.printData();

    example two("new", 6);
    two.printData();

    example three = one;  // calls copy constructor
    three.printData();

    example four;
    four = two;  // calls copy assignment operator
    four.printData();

    return 0;
}

/** OUTPUT OF PROGRAM:
Test(12176,0x1032e4580) malloc: *** error for object 0x600002130020: pointer being freed was not allocated
Test(12176,0x1032e4580) malloc: *** set a breakpoint in malloc_error_break to debug
(default constructor called)
Name: default, Value: 0
(parameterized constructor called)
Name: new, Value: 6
(copy constructor called)
Name: default!, Value: 0
(default constructor called)
(copy assignment operator called)
Name: new!!, Value: 6
(destructor called)
(destructor called)
(destructor called)
 */