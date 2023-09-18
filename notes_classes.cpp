/** CLASS BASICS:
     * Similar to Python classes with different syntax and functionalities.
     * Classes are essentially objects in code which contain data, attributes, and functions.
     * Use for class includes encapsulation of data and functionalities.
     * Separate public interface with private information and functionalities.
     * Instantiate class creates copies of that class with all data and functionalities.
     * Each instance is unique, i.e. separate characters who all have a name, age, etc.
 *
 * Class Constructor: called once when class is initiated, can have multiple to customize.
     * ONE (or none) default class constructor with no passed in parameters.
     * As many parameterized constructors (with different constructor shells).
     * Each time a class is initiated, a constructor is called.
     *
     * format to define in class: ClassName(parameter(s)) {set values of initiated class variables to parameters;}
     * format outside class: ClassName::ClassName(parameter(s)) {set values of initiated class variables to parameters;}
 *
 * Class Destructors: class member function is automatically invoked when an object falls out of scope.
     * Last function an object evokes, used to clean up that object.
     * Many times a class doesn't need a destructor. If one not defined, then implicit destructor created.
     * CRITICAL WHEN DYNAMIC MEMORY INVOLVED.
     * An object call fall out of scope when: a function ends, a program ends, a block ends (ex: ifs/loops), or
     * delete keyword called on dynamically allocated pointer.
     *
     * format to define in class: ~ClassName() {functions;}
     * format outside of class: ClassName::~ClassName() {functions;}
 *
 * STRUCTURE BASICS:
     * Structure, using struct keyword, is just like a class.
     * However, all attributes and functions default to public.
     * Good for simple objects, like collections of data w/out complex functionality.
 *
 */

/**
#pragma once  // avoids conflicts due to files being passed in twice
#include <iostream>
#include <cstdlib>
#include "person.h"  // #include header file
#include <string>
#include <cmath>  // for round function
using namespace std;

// STRUCTURE EXAMPLE: DATA STORAGE
struct RandomData {
    int data1 = 567;
    string data2 = "Catherine S Wu";
    double data3 = 4.5600;

    double Rounded() const {return round(data3);}
};

// CLASS EXAMPLE: SIMPLE GUESSING GAME
class Score {
private:  // attributes stored privately (not directly retrievable/editable from outside function)
    // default Constructor initializes variables with these values when class instance created
    double score = 0.00;
    int correct_guesses = 0;
    int wrong_guesses = 0;

public:  // public access to functions used to modify attributes
    void PrintScore() const {
        cout << "Score: " << score << " | Correct: " << correct_guesses;
        cout << " | Wrong: " << wrong_guesses << endl;}
    void CorrectGuess() {
        correct_guesses++;
        score += 1.00;}
    void WrongGuess() {
        wrong_guesses++;
        score -= 0.50;}
    void ResetGame() {
        score = 0.00;
        correct_guesses = 0;
        wrong_guesses = 0;
        cout << "Game has been reset.\n" << endl;}
};

// CLASS CONSTRUCTORS: DEFINING CONSTRUCTORS FOR PERSON
Person::Person() {  // default Constructor, no parameters passed in
    this->name = "Janice";
    _age = 54;
    _occupation = "Janitor";
}
Person::Person(string name) {
    this->name = std::move(name);  // using this-> to assign initial variables method
    _age = 0;  // this-> assignment not needed when class variable specified with _
    _occupation = "Unemployed";
}
Person::Person(string name, int age, string occupation) {  // full custom Constructors
    this->name = std::move(name);  // using this-> to assign initial variables method
    _age = age;  // this-> assignment not needed when class variable specified with _
    _occupation = std::move(occupation);
}

// COMPLEX CLASS EXAMPLE W/HEADER FILE: PERSON
int Person::GetAge() const {return _age;}
string Person::GetJob() {return _occupation;}
void Person::Birthday() {_age += 1;}
void Person::ChangeJobs(string new_job) {_occupation = std::move(new_job);}
void Person::Display() {cout << name << " the " << _occupation << ", Age: " << _age << endl;}

int main() {
    int program;
    RandomData data;
    cout << "Printing random data: " << data.data1 << " " << data.data2 << " " << data.Rounded() << "\n" << endl;
    cout << "Pick program option:\n\t(1) Guessing Game (simple class ex)\n\t";
    cout << "(2) Person Class, Header, Structure\n" << endl;
    cin >> program;
    if (program==1) {  // (1) Guessing Game, simple class ex contained on main.cpp file
        bool running = true;
        int menu_option;
        int guess;
        Score game;  // creates class instance with default Constructor
        while (running) {
            cout << "MENU:\n\t1. Next Guess\n\t2. New Game\n\t3. Quit\n" << endl;
            cin >> menu_option;
            if (menu_option==1) {
                int correct_guess = rand() % 2;  // Random number from 0 to 1 (2-1) generated.
                cout << "Guess 0 or 1: ";
                cin >> guess;
                if (guess == correct_guess) {game.CorrectGuess();}
                else {game.WrongGuess();}
                game.PrintScore();}
            else if (menu_option==2) {game.ResetGame();}
            else if (menu_option==3) {game.PrintScore();
                running = false;}
            else {continue;}
        }
    }
    else if (program==2) {  // Complex Person class and Person structure, using separate person.h header file
        Person janice;
        Person arnold ("Arnold", 19, "Armor");
        Person trevor ("Trevor", 15, "Trust Fund Baby");
        Person katey ("Katey");
        Person janice_army[4];  // creates array of 4 Person class objects with default constructor

        cout << "Arnold was " << arnold.GetAge() << ". It is Arnold's birthday!" << endl;
        arnold.Birthday();
        cout << "Arnold just turned " << arnold.GetAge() << "!! He no longer wants to be an " << arnold.GetJob() << "." << endl;
        cout << "Arnold wants to be a " << trevor.GetJob() << " like Trevor." << endl;
        arnold.ChangeJobs("Trust Fund Baby");
        cout << "Now, this is Arnold's profile:" << endl;
        arnold.Display();
        cout << "Janice and Katey's profiles:" << endl;
        janice.Display();
        katey.Display();
    }
    return 0;
}
  */
