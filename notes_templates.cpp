/**
#include <string>
#include <iostream>
using namespace std;

// TEMPLATES & FUNCTIONS

// EX | Regular function that accepts one data type: int
int AddIntegers (int int1, int int2) {
    cout << "Regular function used." << endl;
    return int1 + int2;
}

// EX | Template function that accepts any data type
// T is the variable where data type is stored, which here is also the function's return type and the parameters' data type
template <typename T> T AddTogether(const T &dataX, const T &dataY) {
    cout << "Default template used." << endl;
    return dataX + dataY;
}

// EX | SPECIALIZATION for first template function for adding two strings (adds " " space character between)
template<> string AddTogether(const string &dataX, const string &dataY) {
    cout << "String specialization template used." << endl;
    return dataX + " " + dataY;
}

// EX | Template function with some parameters of set type
template <typename T> int AddLetterToNumber(const char &letter, const T &number) {
    if (letter>=65 && letter<=90) {  // function restricted to capital letters A-Z (ascii code#)
        cout << letter << " + " << number << " = " << letter + number << endl;
        return number + letter;  // function will work if number is either int, float, or double type
    }
    cout << "Letter is not a capital letter A-Z." << endl;
    return 0;
}

// TEMPLATES & CLASSES
template <class T>
class GenericClass {
private:
    T variable1;
    int aNumber;
public:
    GenericClass(T v, int n) : variable1(v), aNumber(n) {  // constructor
        T* pointer1;
        T arrayOfT[4];
    }
    void printValue();  // function declaration (defined outside class)
    void multiplyValue(T multiplyBy) {  // function declaration and definition within class (must be done together)
        cout << variable1 << " * " << multiplyBy << " = " << variable1 * multiplyBy << endl;
        variable1 *= multiplyBy;
    }
    T returnValue(const T &value);  // function does nothing but return parameter, T type MUST match that of class initialized
};

template <class T>  // function definition outside of class
void GenericClass<T>::printValue() {
    cout << variable1 << "!!!" << endl;
}
template <class T>  // getter function definition outside of class
T GenericClass<T>::returnValue(const T &value) {
    return value;
}

// SPECIALIZATION: CLASS TEMPLATES
template<>
class GenericClass<string> {
private:
    string variable1;  // specific type for template type from default class template
    int aNumber;
public:
    GenericClass(string v, int n) : variable1(v), aNumber(n) {}  // constructor
    void printValue() {cout << variable1 << "!!!" << endl;};
    void multiplyValue() {cout << variable1 << " is a string, can't multiply with " << aNumber << endl;}
};

// FIXME: Ask if possible to define function outside of specialized class template
// template <> // function definition outside of class
// void GenericClass<string>::printValue() {
//     cout << variable1 << "!!!" << endl;
// }

// Multi-Type Class Template, with Default Type Parameter V (doesn't need to have type specified when instantiating class)
template <class T, class U, class V = char>
class MultiTemplate {
private:
    T t;
    U u;
    V v;
public:
    MultiTemplate(T t1, U u1, V v1) : t(t1), u(u1), v(v1) {}  // constructor
    void PrintVariables() {cout << "t = " << t << ", u = " << u << ", v = " << v << endl;}
    U divideU(V divideBy) {u /= divideBy;  // Multi-Type Function ex in class
        return u;}

    T EditingIDK(T param1, U param2, V param3);
};

// Outside functions must be declared with ALL types in template(not all need to be used in function body)
template <class T, class U, class V>
T MultiTemplate<T,U,V>::EditingIDK(T param1, U param2, V param3) {
    cout << "Values In: " << param1 << param2 << param3 << endl;
    return param1 + param2 + param3;
}


int main() {
    // TEMPLATES & FUNCTIONS
    cout << "Template Function Examples:\n" << endl;

    int sumInt = AddIntegers(3, 5);  // call to regular function
    cout << sumInt << endl;

    double sumDouble = AddTogether(2.467, -1.005);  // call to default template
    cout << sumDouble << endl;

    float sumFloat = AddTogether(1.0f, 2.5f);  // call to default template
    cout << sumFloat << endl;

    string sumSpecString = AddTogether<string>("Hello", "World");  // call to string specialization template
    cout << sumSpecString << endl;

    int total = AddLetterToNumber('B', 5);  // call to template with first parameter specified as char
    cout << total << endl;

    // TEMPLATES & CLASSES
    cout << "\nTemplate Class Examples:\n" << endl;

    GenericClass classObject1(1.222, 9);
    classObject1.printValue();
    classObject1.multiplyValue(2.3);
    classObject1.multiplyValue('T');
    double d = classObject1.returnValue(3.458);  // type must match that of class instance for T
    cout << d << endl;
    // ex: string s = classObject1.returnValue("String"); will be invalid

    GenericClass<string> classSpecObject("Solo", 20);
    classSpecObject.printValue();
    classSpecObject.multiplyValue();

    MultiTemplate<string, int, double> multiObject1("Sir", 7, -23.4);
    multiObject1.PrintVariables();
    cout << multiObject1.divideU(-3.3) << endl;  // divide by double type, return int type

    MultiTemplate<int, int> multiObject2(1, 1, 'B');  // default type for 3rd parameter is char
    multiObject2.PrintVariables();

    multiObject2.EditingIDK(0, 0, 'U');  // parameters for instance functions must match initial types

    return 0;
}

/** TEMPLATES!
 *  Templates as data type - work the same as any other data type.
 *  Template classes MUST be in the same file, due to compiling to create specializations.

 * SYNTAX:
 * Template and function declaration can also be on one line.
 * Return value still must be specified, can match type T of parameters or a specified type.
 * Return type, some parameters, and functions can have specified data types within a template.

 * template <typename T>
 * T FunctionName(T parameter1, T parameter2) {
 *     // function body;}

 * Calling the function can use any data type that function body can handle, ex call syntax:
 *      type variableName = FunctionName(parameter1, parameter2);

 * SPECIALIZATIONS: Template functions differently when specified data type is parameter.
 * Supports 4 main data types (int, double, string, char)
 * Specializations are typically deduced by the compiler when called, based on parameter types.
 * Structure for parameters MUST match that of default template, for instance, if parameter1 is a pass-by value, it
 * must be pass-by value in the specialization, although it can be a specified data type.

 * To EXPLICITLY DECLARE SPECIALIZATION, ex format:
 *      // Declare general template first
 *      template<> returnType FunctionName(type parameter1, type parameter2) {
 *          // function body;}

 * To CALL SPECIALIZATION, ex format:
 *     FunctionName<specificType>(parameter1, parameter2);

 * TEMPLATES AND CLASSES:
 * Syntax in example above.
 * Template class and related definitions MUST be in the same file.
 * Can create specializations of class (syntax above ex).

 * MULTIPLE TYPE-TEMPLATE NAMES: Syntax in examples above.

 */