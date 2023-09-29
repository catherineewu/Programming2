#include <string>
#include <iostream>
using namespace std;

class Person{
private:
    string name;
    int age;
public:
    Person();
    Person(string name, int age);
    void Display();
};

Person::Person() {
    this->name = "Gabby";
    this->age = 20;
}

Person::Person(string name, int age) {
    this->name = name;
    this->age = age;
}

void Person::Display() {
    cout << "\nName: " << name << endl;
    cout << "Age: " << age << endl;
}
