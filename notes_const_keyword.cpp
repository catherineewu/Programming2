#include <iostream>
#include <vector>
using namespace std;

/** CONST KEYWORD
 * Keyword to protect data - marks a variable as constant, or 'read-only' variable.
 * 3 ways to use with Pointers:
 *      1. Protect the data the pointer points to.
 *      2. Protect pointer itself (don't want address to be modified).
 *      3. Use to protect both data and pointer at same time.
 * Issues and considerations known as: const correctness
 * When to use? Accessor/retrieve info, function NOT meant to change variables/object
 * Parameters and return types? Unless there are reasons otherwise,
 * default to PASSING ALL CLASS OBJECTS by CONST REFERENCE or CONST POINTER
 *
 * All function statements involving a const parameter must also be const, even if no changes are made,
 * compiler will still flag.
 *
 * this: What is 'this'?
 *      - this is a pointer to the instance of a function (is an object), EX: function of copy constructor using this->
 *      - const member functions protects this from changes, no code in function can change the this pointer
 *      - makes this read-only for the function
 *      - EX: class Point {public: float FunctionName; float Point::FunctionName(const Points& p) CONST {return ...}};
 * Make a constant class, EX:
 *      void Example::Foo() const {
 *          this->someValue -= 5;
 *          Bar();}  // calls non-const value, results in compiler error
 *      void Example::Bar() {  // Bar is a non-const function, changes attributes in 'this'
 *          this->someValue -= 5;}
 * Solution? (1) Don't call Bar() from within Foo(), (2) Change Bar() to const member function, remove any code that
 * changes *this.
 *
 * Common to write both const and non-const versions of a function, EX:
 *      vector<int> someData;
 *      vector<int>& Get Data();
 *      const vector<in><& GetData() const;
 * Compiler calls the right version based on the "const-ness" of the invoking object.
 */

/// EX: CONST FOR PASS-BY REFERENCE OR REFERENCE BY POINTER
void PrintVar(const int& param) {  // PASS-BY REFERENCE for parameter that is an integer, marked const IN function
    /// param += 1;  // error: can't modify const pass-by reference
    cout << param << endl;
}
class Container {
    int *dynamicArray;  // Declare pointer of int type, pointer variable name is dynamicArray
public:
    // 1st const: catch returned pointer in const variable, MUST do this - compiler will enforce
    // 2nd const: makes function const (after parameters declared), so pointer can't be edited
    const int* GetData() const {
        /// dynamicArray += 1;  // error: constant function, can't reassign
        return dynamicArray;
    }
};

/// EX: CONST FOR CLASS FUNCTIONS
// Const protects safety of 'this' inside class functions (explanation for 'this' above)
// Const keyword AFTER function's parameter list marks it as a const member function
class Example {
    int variable = 1;
public:
    void Foo() const;  // function Foo1 declared as constant member function

    /// void Foo(Example* this);  // compiler passes this for us
    /// void Foo(const Example* this) const;  // const member functions use a const pointer for this
};

/// PASS-BY REFERENCE
class PBRExample {
    vector<int> someData;
public:
    vector<int>& GetData();  // Non-const GetData function
    const vector<int>& GetData() const;  // const GetData function

    /// TO CHANGE DATA: Function CHANGES object, uses NON-CONST GetData() function
    // Gets user input and stores in object's data list
    void InputToValues1(PBRExample& tempClass) {
        vector<int>& values = tempClass.GetData();  // modify data, reference Non-const version of GetData()
        for (int i=0;i<5;i++) {
            int someNumber;
            cin >> someNumber;
            values.push_back(someNumber);
        }
    }  // Second method, same result
    void InputToValues2(PBRExample& tempClass) {
        for (int i=0;i<5;i++) {
            int someNumber;
            cin >> someNumber;
            tempClass.GetData().push_back(someNumber);  // using the returned reference directly
        }
    }
    /// TO PREVENT CHANGES TO DATA: Function DOES NOT CHANGE object, uses CONST GetData() function
    // Returns # of even integers in data
    int CountEvens(const PBRExample& tempClass) {
        const vector<int>& values = tempClass.GetData();  // Const version of GetData protects values from change
        int count = 0;
        for (int value : values) {
            if (value % 2 == 0) {
                count++;
            }
        }
        return count;
    }

};
vector<int>& PBRExample::GetData() {
    return someData;}
const vector<int>& PBRExample::GetData() const {
    return someData;}

int main_const_keyword() {
    /// CONST VARIABLES
    const float pi = 3.14159f;  // establish const variable, cannot be changed
    /// pi = 12.4f;  // attempt to change const variable value - will result in compiler error
    cout << pi << " " << &pi << " " << endl;

    /// CONST FOR PASS-BY REFERENCE OR REFERENCE BY POINTER
    // ex: Print function doesn't need to change variable values, so using const for parameters prevents function from
    // being able to modify object within function.
    /// void Print(const type& param);
    /// void Print(const type* param);

    // Also used when returning references and pointers (ex above)

    Container example;
    const int* data = example.GetData();
    // Error, myPointer2 use be const
    /// int* error = example.GetData();

    /// CONST POINTER
    int someValue = 52;
    const int* pointerToConst = &someValue;  // declare pointer and assign to const value
    /// *pointer += 18;  // compiler error: can't change data being pointed to
    int valA = 52, valB = 24;
    int* const constPointer = &valA;  // const pointer, can also use syntax: const type* const PointerName;
    *constPointer = -6;  // data being pointed to CAN be changed
    /// constPointer = &valB;  // compiler error, can't change pointer address (can't reassign pointer)

    return 0;
}