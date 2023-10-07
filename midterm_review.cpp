#include <iostream>
#include <vector>
#include <string>
using namespace std;

/** THIS IS A PRACTICE PROGRAM WITH ALL CONCEPTS FOR MIDTERM
 * Creating functions: return types, templates, comparisons
 * Algebraic and comparison operators
 * Operator overloading
 * Pointers, references, dereferencing, addresses
 * Pass-by references and constant functions/references
 * Vector operations
 * Array operations
 * Constructors, copy constructor, copy assignment operator, destructor
 * Define big three for dynamic array
 * Dynamic memory
 * Linked list operations
 */
template<class T>
class Vector {
public:
    vector<T> _vec;  // vector can change size, no need to specify max capacity
    int _size;
    Vector() {throw runtime_error("Can't initiate an empty vector.");}  // default constructor
    Vector(int size, T* array) {  // pointer parameter type
        for (int i=0;i<size;i++) {
            _vec.push_back(array[i]);}
        _size = _vec.size();}
    void PrintVector();
    T GetValue(int index);
    void RemoveTwoValues(int index1, int index2);
    bool operator==(const Vector<T>& compare);  // overload of == operator
};
template<class T>  // define template function outside of class
void Vector<T>::PrintVector() {
    cout << "Printing vector..." << endl;
    for (int i=0;i<this->_vec.size();i++) {
        cout << this->_vec[i] << " ";}
    cout << endl;}
template<class T> T Vector<T>::GetValue(int index) {
    return _vec.at(index);}
template<class T> void Vector<T>::RemoveTwoValues(int index1, int index2) {
    if (index1 < index2) {index2 -= 1;}
    _vec.erase(_vec.begin() + index1);
    _vec.erase(_vec.begin() + index2);}//, (_vec.begin() + (index2-1)));}  // another way to access data at index
template<class T> bool Vector<T>::operator==(const Vector<T>& compare) {
    if (this->_size != compare._size) {
        return false;}
    for (int i=0;i<this->_size;i++) {
        if (this->_vec[i] != compare._vec[i]) {
            return false;}}
    return true;}

class IntAr {  // Static array w/max storage of 10
public:
    int _size;  // define class attributes (default these and constructors are private)
    int* _size_address = &_size;  // create pointer to stack variable
    int* _array = new int[10];  // _array is pointer to first array data, new designates heap data
    IntAr(int _size = 0);  // alternate way of writing default constructor
    IntAr(string data) {  // parameterized constructor
        if (data.length() <= 10) {  // can't throw/catch/except in constructor
            cout << "Making array of size " << data.size() << endl;
            for (int i = 0; i < data.size(); i++) {
                _array[i] = int(data[i] - 48);  // 0 stored in ascii as 48
                cout << _array[i] << endl;}
            _size = data.size();
        }
    }
    // BIG THREE: define one = define all!
    IntAr(const IntAr& existing) {  // COPY CONSTRUCTOR (not function, no return)
        // 'constructor' when called with parameter of an existing class object
        // creates deep copy of data in existing class object into new class object
        if (this != &existing) {  // must make sure
            this->_size = existing._size;  // this-> to point to object being constructed
            this->_array = new int[10];  // make new data, not just pointer to same data
            cout << "Copying array of size " << existing._size << endl;
            for (int i = 0; i < existing._size; i++) {
                this->_array[i] = existing._array[i];  // copy data from old to new array
                cout << this->_array[i] << " ";
                cout << "\nArray successfully copied." << endl;  // /n one of escape characters
            }
        }
    }
    IntAr& operator=(const IntAr& existing) {  // COPY ASSIGNMENT OPERATOR(=)
        // parameters are already constructed class object and existing is class object called to copy from
        // variables from class being copied to directly defined
        _size = existing._size;
        _array = new int[10];
        for (int i=0; i<existing._size; i++) {
            _array[i] = existing._array[i];
        }
        return *this;  // ALWAYS return *this for copy assignment operator (pointer to class object copied into)
    }
    ~IntAr() {  // DESTRUCTOR
        delete[] _array;  // delete[] will delete all data in array, not just at immediate address
        _size_address = nullptr;
    }
    void PrintArray() const;  // declare functions defined outside of class
};
void IntAr::PrintArray() const {  // const function (no variables modified)
    // embedded iteration - only use with stack array, so not this class
    // for (int data : data_array) {cout << data << endl;}
    cout << "Printing array..." << endl;
    for (int i=0;i<_size;i++) {
        cout << this->_array[i];
    } cout << endl; }

int main_review() {
    string data = "1234";
    IntAr array1(data);  // enter array is numeric string
    try {  // can throw without try and catch, but if try used, MUST be caught
        int length = data.length();
        if (length > 10) {throw (length);}}
    catch (int length) {  // alternate way: throw runtime_error("Message."), catch (runtime_error& e), cout << e.what()
        cout << "String of " << length << " characters exceeds 10 item limit for array." << endl;}
    array1.PrintArray();

    Vector vector1(4, array1._array);  // can't pass array itself to function, use pointer to array
    vector1.PrintVector();
    cout << "Comparisons" << endl;
    IntAr array2("01234");
    Vector vector2(5, array2._array);
    cout << boolalpha << (vector1 == vector2) << endl;
    // boolalpha makes following bool values string "true"/"false" vs 1/0
    // noboolalpha cancels it
    Vector<int>* original = &vector1;  // create pointer to first vector object (need to specify <Type>)

    Vector vector3 = *original;  // dereference to pass in object at pointer's address
    cout << noboolalpha << (*original == vector3) << endl;
    vector2 = vector1;
    cout << boolalpha << (*original == vector2) << endl;
    cout << "Original vector: ";
    (*original).PrintVector();
    cout << "Removing values at index 1 and 2..." << endl;
    (*original).RemoveTwoValues(2, 0);
    cout << "New vector: " << (*original).GetValue(0) << " " << (*original).GetValue(1) << endl;

    return 0;
}