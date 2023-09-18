#include <string>
#include <iostream>
#include <utility>
using namespace std;
#ifndef TEST_PERSON_H
#define TEST_PERSON_H

#endif //TEST_PERSON_H

class Person {
    string name;
    int _age;
    string _occupation;

public:
    [[nodiscard]] int GetAge() const;
    string GetJob();
    void Birthday();
    void ChangeJobs(string new_job);
    void Display();

    Person();
    explicit Person(string name);
    Person(string name, int age, string occupation);
};
