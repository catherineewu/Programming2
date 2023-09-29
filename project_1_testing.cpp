/**#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
using namespace std;

int main() {
    // INT TYPE TESTING
    LinkedList<int> intList;
    intList.AddTail(3);
    intList.AddHead(2);
    intList.AddTail(4);

    int intArray[] = {5, 6, 7};
    intList.AddNodesTail(intArray, 3);

    int intArray2[] = {0, 1};
    intList.AddNodesHead(intArray2, 2);

    cout << "Number of Nodes: " << intList.NodeCount() << endl;
    cout << "Print Forward: " << endl;
    intList.PrintForward();
    cout << "Print Reverse: " << endl;
    intList.PrintReverse();

    // STRING TYPE TESTING
    LinkedList<string> strList;
    string strArray[] = {"Eight", "Nine", "Ten", "Eleven"};
    strList.AddNodesHead(strArray, 4);
    strList.AddTail("Twelve");

    cout << "Number of Nodes: " << strList.NodeCount() << endl;
    cout << "Print Forward: " << endl;
    strList.PrintForward();
    cout << "Print Reverse: " << endl;
    strList.PrintReverse();

    cout << "end" << endl;
    return 0;
}
*/