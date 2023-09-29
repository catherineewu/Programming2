
/**#include <string>
#include <fstream>
#include <sstream>
using namespace std;*/

/** TYPECASTING: Converting & modifying data types
 *
 * C-Style Typecasts - not recommended by class for use
 * EX: int x = 10; // int x = 10; // float result = (float)x;
 * Some C++ casts perform compile-time checks, to make sure typecast is feasible
 * Problem examples: 1 byte char attempt to typecast to 4 byte int pointer
 *
 * Static_cast FIXME: take notes
 *
 * Reinterpret_cast make intention clear
 * EX: char = smallValue = 20; // int* ptr = reinterpret_cast<int*>(&smallValue);
 *
 * Const_cast allows to cast away const-ness of a pointer, niche and uncommon operation
 * Dynamic_cast used when working with inheritance and polymorphism, not learned yet
 */

/**
 * // Typecasting EX: Converting to char* for write()
ofstream file('Nonexistent_File.txt');

int someNum = 10;
file.write(reinterpret_cast<char*>(&someNum), 4);  // &someNum == int*

short speed = 200;
file.write(reinterpret_cast<char*>(&speed), 2);  // &speed == short*

int arrayofInts[3] = {2, 4, 6};
file.write(reinterpret_cast<char*>(arrayOfInts), 12);  // arrayOfInts == int*
// 4 bytes x 3 ints = 12 bytes

char bling = '$';
file.write(&bling, 1);  // bling already char*, casting not needed

// function return values must be stored in variable to be typecasted/written

/** Writing Complex Object
 * Size of string: (bytes x #chars in string) + 1 byte (character defining string type)
 * Should not write instance of class as a single operation, because objects made of pointers, dynamic memory,
 * other complex objects. DO NOT attempt to write complex objects as single block of memory. Write multiple operations
 * for relevant member data. */
/**SomeObject obj("Bob", 115, 1.732f);
file.write(reinterpret_cast<char*>(&obj), sizeof(obj));  // &obj == SomeObject*

// WRITING SOME BINARY DATA WITH o/fstream
float pi = 3.14;
double biggerPi = 3.14159;
int notPie = 3;
string pie = "Apple";

fstream file("BinaryFile.bin", ios_base::out | ios_base::binary);
if (file.is_open()) {
    file.write(reinterpret_cast<char*>(&pi), sizeof(pi));
    file.write(reinterpret_cast<char*>(&biggerPi), sizeof(biggerPi));
    file.write(reinterpret_cast<char*>(&notPi), sizeof(notPi));

    // Writing string: 2-step process
    // 1) Write length of string
    unsigned int length = pie.size() + 1;  // +1 for null-terminator '\0'
    file.write(reinterpret_cast<char*>(&length), sizeof(length));

    // 2) Write string data itself
    // c_str() returns 'real' string data as a char*
    file.write(pie.c_str(), length);
}

/** What happens when wrong amount read?
 * Lead to unexpected, difficult to figure out results.
 * sizeof() function returns size, in bytes, of specific variable or type.
 * All pointers 4 bytes typically.
 * Difference in sizes between different languages, cross-language programs should use program-specific 'get type'
 * function when passing data between languages.
 *
 * sizeof() for CLASS OBJECTS
 * Classes are containers, often w/ pointers and dynamic memory allocation.
 * sizeof() gives size of CONTAINER, but not necessarily size of CONTENTS.
 * Often doesn't take dynamic memory allocation into account.
 *
 * sizeof() for STL CONTAINERS
 * STL (standard type library) containers include vectors FIXME: finish notes*/

/** READING BINARY DATA WITH i/fstream
 * Dynamic memory needed, unknown file size until first count type read.
 * Calculate total size of any arrays.
 *
 * Advanced (not in class): READING ENTIRE FILES
 */
/**
char byte;
file.read(&byte, 1);  // &byte determines where data is read into, here, the char data type 'byte'
 */