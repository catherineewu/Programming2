#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
using namespace std;

/** PART 1 TESTING:
 *     // INT TYPE TESTING
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
 *
 */

int main() {
    // Testing Basics
    LinkedList<int> LLI;
    int IA[] = {0,2,4,2,0};
    LLI.AddNodesHead(IA, 5);
    LLI.AddTail(0);
    LLI.PrintForward();
    cout << "nodes: " << LLI.NodeCount() << endl;

    // Testing Head and Tail
    LinkedList<int>::Node* LLI_head = LLI.Head();
    cout << "Head is " << (*LLI_head)._data << " at " << LLI_head << endl;
    LinkedList<int>::Node* LLI_tail = LLI.Tail();
    cout << "Tail is " << (*LLI_tail)._data << " at " << LLI_tail << endl;

    // Testing FindAll
    cout << "Testing FindAll" << endl;
    vector<LinkedList<int>::Node*> zeros;
    LLI.FindAll(zeros, 0);
    cout << "1st " << (*zeros[0])._data << ": " << zeros[0] << endl;
    cout << "2nd " << (*zeros[1])._data << ": " << zeros[1] << endl;
    cout << "3rd " << (*zeros[2])._data << ": " << zeros[2] << endl;

    // Testing Find
    cout << "Testing Find" << endl;
    LinkedList<int>::Node* first_zero = LLI.Find(0);
    cout << "1st " << (*first_zero)._data << ": " << first_zero << endl;
    LinkedList<int>::Node* first_four = LLI.Find(4);
    cout << "1st " << (*first_four)._data << ": " << first_four << endl;

    // Testing GetNode
    cout << "Testing GetNode" << endl;
    LinkedList<int>::Node* index_2_value = LLI.GetNode(2);
    cout << "Value at index 2: " << (*index_2_value)._data << endl;
    LinkedList<int>::Node* index_5_value = LLI.GetNode(5);
    cout << "Value at index 5: " << (*index_5_value)._data << endl;
    // out_of_range Error Generator
    /**LinkedList<int>::Node* index_6_value = LLI.GetNode(6);
    cout << "Value at index 6: " << (*index_6_value)._data << endl;*/

    // Testing copy constructor
    LinkedList<int> LLI_copy = LLI;

    // Testing copy assignment operator
    LinkedList<int> LLI_deep_copy;
    LLI_deep_copy = LLI;

    cout << "end" << endl;
    return 0;
}