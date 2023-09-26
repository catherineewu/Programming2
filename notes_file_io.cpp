#include <fstream>  // for files
#include <iostream>  // for user input/print output
#include <string>
#include <vector>
#include <sstream>
using std::istringstream;  // or using namespace std;
using std::ofstream;
using std::ifstream;
using std::fstream;
using namespace std;


class Vehicle {
    std::string _make;
    std::string _model;
    int _miles;
    double _price;
public:
    Vehicle(std::string make, std::string model, int miles, double price) {
        _make = make;
        _model = model;
        _miles = miles;
        _price = price;
    }
};

int file_main() {
    // pass string to parameterized constructor to open file
    ofstream someFile("SomeFile.txt");  // initiates ofstream class and stores data of file in variable someFile
    // EX: absolute path - "C:/ThisFolder/SubFolder/someFile.txt" vs. relative path - "someFile.txt"

    // opening files w/ specific IO modes (all modes in notes below)
    // EX: open this file in output mode, binary mode, and preserve the file contents
    fstream aFile("file.ext", std::ios_base::out | std::ios_base::binary | std::ios_base::app);

    // Or use the open() function
    // The constructor just calls open() if you pass it a string
    ofstream otherFile;  // initiate ofstream class object
    otherFile.open("data/file1.xyz");  // store file data in that class object

    // Verify the file is actually open (optional... but IMPORTANT! Do this typically.)
    if (someFile.is_open())
    {cout << "File opened successfully!" << endl;
        // Example of what you could do to confirm, now do stuff with file

        // Writing to files with ofstream
        // Insertion operator << (like printing something with cout)
        const float pi = 3.14115f;
        someFile << "Hello World!\n";
        someFile << "pi Value: " << pi << std::endl;

        // Closing file - MUST close if you want to open another file with SAME stream object
        someFile.close();

        someFile.open("Numbers2.txt");  // open new file with someFile stream object
        someFile.close();
    }
    else
    {cout << "Error! File not opened!" << endl;
        // Throw an exception, return an error code, etc
    }

    // Reading files with IFSTREAM
    ifstream carFile("VehicleData.txt");
    // Initiate objects to store incoming data
    string make;
    string model;
    int miles;
    double price;

    if (carFile.is_open()) {
        // Reads data in order of text file
        getline(carFile, make);  // getline() takes whole line of data
        getline(carFile, model);
        carFile >> miles;  // >> takes one object (word, number, etc.) in order
        carFile >> price;

        // Use data, can assemble more complex objects from individual data pieces
        Vehicle car(make, model, miles, price);
        // Store car object for later in vector object
        vector<Vehicle> VectorOfVehicles;
        VectorOfVehicles.push_back(car);
    }

    // ISTRINGSTREAM: Class for reading files with Delimiters
    // 1. SETUP with #include <sstream>  // using std::istringstream;
    // DELIMITER: character separating pieces of data (ex: , / % //)
    ifstream csvFile("Vehicles.csv");
    string singleLine;
    getline(csvFile, singleLine);
    // 2. CONVERT LINE OF STRING TO STREAM
    // getline(STREAM: file read from, TOKEN: object to store piece of data, 'DELIMITER' - optional 3rd parameter)
    istringstream stream(singleLine);
    string token;
    // Read stream until comma is reached
    getline(stream, token, ',');
    // Loop istringstream
    while(getline(stream, token, ',')) {  // while condition F when no more data
        cout << "Token: " << token << endl;
    } // Gets us tokens as std::strings, to convert to numbers EX:
    getline(stream, token, ',');  // get token
    int miles_driven = stoi(token);  // convert to a format needed when stored

    return 0;
}


/** FILE IO:
 * Virtually all data in computer apps read from/stored in files
 * Even cloud data stored on some computer/"server" in a file
 * All files made up of collections of basic data types (ints, floats, etc.)
 * Specific file types (ex: Word) are just collections of data
 * Data can be represented in text or binary

 * FILE STRUCTURE:
 * All files have some structure/order to data (even if you don't know)
 * Understanding structure allows operations for file (reading, editing, new files of type, etc.)
 * 3 things all files have (combined make full path to file):
     * 1. Directory (folder/where is file located?)
     * 2. File Name
     * 3. Extension (type of file, tells file structure and data, ex: .png, .jpg)
     * ex: D:\Documents\PG2\Lecture\File_10.pptx
         * If using backslashes, may need to use escape sequence "\\"
         * (use \\ instead of \ between folders)

     * ESCAPE SEQUENCES:
     * \n   Newline character
     * \t   Tab character
     * \e   NUL-terminator (terminates a string)
     * \\   Escape sequence when \ used

 * BACKSLASH \ VS FORWARD SLASH /
     * LINUX/MACOS: use forward slashes
     * WINDOWS: use back slashes, however forward tends to work well everywhere
     * Certain programs/OS may only take one

 * USING FILES FOR DATA:
 * Simple apps can have all their data HARD-CODED
     * Data (variables, functions, code, etc.) stored in source code and code written by programmer
 * Most apps are data-driven, using external sources of information to define behavior
 *
 * ABSOLUTE VS RELATIVE PATHS: 2 ways paths can be written
 * ABSOLUTE PATH: fixed, unchanging path (should be avoided unless you know the location will be there,
 * like a program running only on your computer)
     * EX: "C:/ThisFolder/SubFolder/someFile.txt"
     * Will only work on creator's computer unless user makes those specific folders along path
 *
 * RELATIVE PATH: relative to some other location
 * Relative to the executable (default) or from some other starting point. Program 'fills gaps', often files in same
 * directory in same folder level as executable.
     * Ex: "someFile.txt" or "data/results.xyz"
     * data is folder within relative folder
 *
 * IDE READ/WRITE FILES: Depends on IDE
 * VISUAL STUDIO: looks in same folder as source code (right click on project in Solution Explorer, select "Open Folder
 * in File Explorer"), executable not in same folder as other files
 * CLION: external files read from cmake-build-debug directory, executable in same folder with external files
 *
 * Code should work in as many situations as possible, don't change code to adapt to IDE
 *
 *
 */

/** FILE IO IN C++
 * C++ uses 3 classes for file io:  #include <fstream>
     * OFSTRING     output file stream, for writing data to a file
     * IFSTREAM     input file stream, for reading data from a file
     * FSTREAM      file stream (input AND/OR output depending on needs)
 * Steps:
     * 1. Open file
     * 2. Verify file was opened  EX: if (inFile.is_open())
     * 3. Use the file
     * 4. Close file (usually optional)

 * REASONS FILE MIGHT NOT OPEN:
     * Path incorrect, ofstream objects will create file if it doesn't exist (can produce a file still, though wrong)
     * File may be opened by something else in program, OS may not allow more than one "thing" to access a file at the same time
     * Might be trying to access protected directory

 * OPENING FILES W/ SPECIFIC IO MODES
 *  ios_base::in     input(ifstream uses this automatically)
 *  ios_base::out    output(ofstream uses this automatically)
 *  ios_base::trunc  truncate(delete) contents (ofstream default)
 *  ios_base::app    append to file's contents
 *  ios_base::ate    seek to end after opening
 *  ios_base::binary perform operations in binary mode
 *  ios_base::in     input(ifstream uses this automatically)

 * EX: combine multiple options using bitwise OR operator
     * open this file in output mode, binary mode, and preserve the file contents
     * fstream someFile("file.ext", ios_base::out | ios_base::binary | ios_base::app);

 * WRITING FILES WITH OFSTREAM
     * Use insertion operator: <<
     * Just like printing something to screen with cout

 * CALLING CLOSE():
     * Destructors usually automatically delete
     * RAII Resource Acquisition Is Initialization
     * Depends on language, C# requires file to be closed
 *
 * WRITING COMPLEX OBJECTS:
 * Write them same as would print them to screen

 * READING FILES WITH IFSTREAM
     * Depends on format of data
     * Don't read objects from file, but small data pieces one at a time
     * To read an object from file, read all the parts, then construct the object from parts and store it

 * Unknown quantities of data
     * Code that reads as long as their is data in while loop
     * if (inFile.is_open()) {while (inFile >> numberFromFile) { }}

 * Files can contain data about its data, which is read before other data and determines how rest of data is read,
 * organized, and stored.

 * Data can be structured in many ways, including format one line, one model in pieces with different delimiters
 * Delimiter: stopping point/boundary between items, EX: commas, pipes, symbols like $%, letters or spaces (not good usually)
 * COMMA-SEPARATED VALUES (CSV) File: info stored w/ comma as delimiter, "generic" format for spreadsheets
     * EX: (Jake,45,9102,Yes,well)
 * READING MULTIPLE VALUES FROM ONE LINE
     * 1. Read line from file, using getline()
     * 2. Break string into multiple parts (break into TOKENS/TOKENIZE) based on delimiter
     * Hard way: lots of calls with find_first/last_of() and substr()
     * Easier way: use class istringstream and getline() function

 * Using ISTRINGSTREAM, often with Loop
     * Convert string to "stream" of data that ca nbe read with getline()
     * Read stream until reach a comma/delimiter

 */
