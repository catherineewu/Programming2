#include <iostream>
using namespace std;

// Function to Print Arguments
// in Terminal, 1) go to directory for this class, 2) Compile: >g++ notes_command_line_arguments.cpp, 3) Execute with
// arguments > ./a.out arg1 arg2 arg3
int main_cla(int argc, const char** argv) {
    if (argc > 1) {  // first argument always program itself
        for (int i=1;i<argc;i++) {
            cout << "Argument #" << i << ": " << argv[i] << endl;
        }
    }
    return 0;
}