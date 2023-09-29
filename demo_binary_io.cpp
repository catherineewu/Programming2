#include <fstream>
#include <iostream>
#include "Personn.h"
using namespace std;

// In binary file, strings represented as char pointers
/**About bytes: 1 byte = 8 bits
 * 1 int = 4 bytes
 * 1 char = 1 byte
 * 2 hex-digits = 1 byte */

int main_demo_binary_io() {

    const char *name = "Esperanza";
    int age = 50;

    //(1) Create a binary file using ofstream
    // CREATE FILE: ofstream fileVarName("fileName.type", ios_base::binary);
    ofstream file0("person.gt", ios_base::binary);

    //(2) Write data to the file (name and age)
    // WRITE TO FILE: fileVarName.write(data, int: size_of_stream);
    file0.write(name, 9+1);
    file0.write((char*) &age, sizeof(age));

    //(3) CLOSE FILE: fileVarName.close();
    file0.close();

    //(4) Open the new file using ifstream
    // OPEN FILE: ifstream fileVarName("fileName.type", ios_base::binary);
    ifstream fileI("person.gt", ios_base::binary);

    //(5)Check that the file opened
    if (fileI.is_open()) {
        cout << "open!" << endl;
    } else {cout << "is not open :(" << endl;}

    string inName;  // declare 2 objects
    int inAge;

    //(6) Read the binary data stored in the file (inName and inAge);
    char* buffer = new char[10];  // buffer is pointer to char array of size 10
    // read 10 bytes in data stream into buffer pointer
    // the buffer pointer places data read from file into the char array
    fileI.read(buffer, 10);
    inName = buffer;  // store data in char array into object inName
    delete[] buffer;  // delete data stored in char array from its pointer

    // read next 4 bytes (size of int data type) from file into inAge
    // (char*) &inAge   typecasting binary data to int FIXME
    fileI.read((char*) &inAge, sizeof(inAge));

    //(7) Display name and age of person
    cout << "Name: " << inName << endl;
    cout << "Age: " << inAge << endl;

    /*------------------------------Part 2------------------------------*/

    /** File format of people.gt
     * 4 Bytes: count of # of people in file
     * For each person in file:
     *      4 Bytes: LENGTH of name including null terminator
     *      "Length" Bytes: string data of person's name, including null terminator
     *              (LENGTH + 1) Bytes
     *      4 Bytes: person's age
     * Total Bytes of people.gt = 4 + [(# of people) * (8 + LENGTH(dif for each name) + 1)]
     */
    //(1) Open the people.gt binary file
    ifstream fileIn("people.gt", ios_base::binary);

    //(2) Check if file opened successfully

    if (fileIn.is_open()) {
        cout << "open!" << endl;
    } else {cout << "is not open :(" << endl;}

    int numPeople; //number of people in binary file
    int lengthOfName;
    int personAge;
    string personName;

    //(3) Read how many people are stored in the binary file
    fileIn.read((char*) &numPeople, sizeof(numPeople));

    //(4) Create a for-loop to read all the people data stored in the binary file
    for (int i = 0; i < numPeople; i++) {

        //(5) Read the length of the person name
        fileIn.read((char*) &lengthOfName, sizeof(lengthOfName));

        //(6) Using the length, read the person name
        char* bufferName = new char[lengthOfName];  // creates array to store characters
        fileIn.read(bufferName, lengthOfName);  // reads file data into buffer array
        personName = bufferName;  // buffer array data stored in personName object
        delete[] bufferName;  // delete data from buffer pointer

        //(7) Read the person's age
        fileIn.read((char*) &personAge, sizeof(personAge));

        //(8) Create a person object, Person.h is already written for you
        Person person(personName, personAge);  // create person object instance

        //(9) Display the person using .Display()
        person.Display();  // display data using person object instance
    }
    return 0;
}