#include <iostream>
using namespace std;

/** OPERATOR OVERLOADING
 * Rational Operators: + - / *
 * Relational Operators: > < <= >= == !=
 * Assignment & Compound Operators: = += -= *= /=
 * Subscript Operator: []  // treat class like array
 * You can overload overloaded operators.
 * Try to keep overload functions relevant, and don't use unnecessarily.

 * SYNTAX: Functions with 'operator' keyword in name, ex:
 *      void operator*(double y);  // Name of function: operator*
 *      bool operator<(Vector3& rhs);  // Function name: operator<
 *      SomeObject& operator[](int index);  // Function name: operator[]
 *      Object& operator=(const Object& m);  // Function name: operator=

 * Used to customize use of classes (can also overload regular functions, not covered in class).
 * Similar to concept of overloading functions (multiple different constructors for different parameters).
 * Shorthand for functions.
*/

/**
// TRADITIONAL VS. OVERLOADED FUNCTION
class Values {
public:
    int a, b, c;
    Values(int a, int b, int c) : a(a), b(b), c(c) {}
};

// Traditional Function | Name = AddDigits
int AddDigits(int hundreds, int tens, int ones) {return (100 * hundreds) + (10 * tens) + ones;}
// to call: sum = AddDigits(valuesObject.a, ValuesObject.b, ValuesObject.c);

// Overloaded + Operator Function | Name = operator+
int operator+(Values valuesObject) {return (100 * valuesObject.a) + (10 * valuesObject.b) + valuesObject.c;}
// to call: sum = +valuesObject1;

// OVERLOAD OPERATOR WITHIN CLASS: MODIFYING ATTRIBUTES
class Floaties {
    float x, y, z;
public:
    Floaties() {x = y = z = 0;}
    void Display() {cout << x << " " << y << " " << z << endl;}
    Floaties& operator+=(Floaties) {
        x += 0.50;
        y += 0.50;
        z += 0.50;
        return *this;
    }
};

int main() {
    // TRADITIONAL VS. OVERLOADED FUNCTION
    Values set1(4, 8, 9);
    int sum;
    sum = AddDigits(set1.a, set1.b, set1.c);
    cout << sum << endl;
    sum = +set1;
    cout << sum << endl;

    // OVERLOAD OPERATOR WITHIN CLASS: MODIFYING ATTRIBUTES
    Floaties floaties;
    floaties.Display();
    floaties += floaties;
    floaties.Display();

    return 0;
}
 */