using namespace std;

struct Node {  // Singly-linked Node class
    int data;
    Node* next;
    Node() {data = 0;};
    Node(int value) {data = value;
    next = nullptr;}};
class SinglyLinkedList {  // Unidirectional List
    Node* head;};

struct DNode {  // Doubly-Linked Node Class
    int data;
    DNode* next;
    DNode* previous;};
template <typename T>  // Template (many data structures are, don't have to be)
class DoublyLinkedList {  // Bidirectional List
    T data;
    Node* head;
    Node* tail;
public:  // function examples to go along with class
    void AddNode(T newData);
    void RemoveNode();
    void ClearList();
    ~DoublyLinkedList();  // etc...
private:
    Node* _head;
    Node* _tail;};


int linked_list_main() {
    Node* head = nullptr;  // initiate null pointer named 'head' to type of object from Node class
    head = new Node;  // dynamically allocate memory to Node class object
    head->data = 1;  // store data into node
    head->next = nullptr;  // store pointer to next Node

    // For every new piece of data: 1) new Node must be allocated, 2) must be connected to 1+ other Nodes
    Node* secondNode = new Node(2);  // parameterized constructor
    // Connecting 2 nodes together
    head->next = secondNode;

    // Moving from variables to unnamed nodes, same concept as  arrays to avoid loose variables
    // Don't need unique variable names, but store access to next node in variable in previous
    // first->next is "the node that comes after first", a new Node
    Node* first = new Node;
    first->next = new Node;  // 2nd Node
    first->next->data = 2;  // data in 2nd Node
    first->next->next = new Node;  // 3rd Node
    first->next->next->data = 3;  // data in 3rd Node
    // Tedious & bad method with many Nodes
    // Getting to end of list options:
    // 1) Traverse over all nodes until reach node with next pointer pointing to nullptr
    // 2) Tail Pointer: store & update pointer to last node (better choice)

    // FOR LOOP to reach certain Node
    Node* currentNode = head;
    for (int i=0;i<3;i++) {
        // Move forward 1 Node
        currentNode = currentNode->next;}
    // WHILE LOOP to reach certain node
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;}
    // Now, ADD Node to END OF LIST:
    currentNode->next = new Node(100);

    return 0;
}

/** LINKED LISTS
 * Non-contiguous data structure storing NODES, data storage fragmented
 * NODES:
     * Generic term for some unit of data in data structure
     * Implemented as a class or structure
     * Usually contains some data and pointer to 1+ other nodes
     *
     * All linked list operations involve using Node pointers to create, delete, or access existing nodes
     * (Nodes dynamically allocated adn deallocated)
 * No random access to any element (unlike arrays)
 * Data accessed LINEARLY, one node at a type, iterating from 1st>2nd>3rd>...>last node
 * Pointers stored to locations of data, each node has POINTER TO NEXT NODE
 * Ex: each object "knows" only the next object
 * Last object knows is last object, has nullptr pointer
 *
 * Using Linked List > Get to data in list > Use data in list
 * GENERAL ALGORITHM TO TRAVERSE LIST:
     * 1) Create pointer to first node (Always create pointer to something that already exists)
     * 2) If we're pointing to valid node (or some other condition)
     * 3) Use node and/or move to next node (pointer = pointer->next)
     * 4) Go to Step 2, repeat
 *
 * SINGLY-LINKED VS. DOUBLY-LINKED LIST
 * SINGLY LINKED: Unidirectional access
     * Nodes have 1 connection to NEXT pointer
     * Pointers: HEAD, TAIL (optional)
     * Start from beginning, traverse through in 1 direction
 *
 * DOUBLY LINKED: Bidirectional access
     * Nodes have 2 connections, to NEXT and PREVIOUS pointers
     * Pointers: HEAD, TAIL
     * Start at either end, traverse in either direction
 *
 * Optional (either): make CIRCULAR
     * Last node's next points to first instead of nullptr
     * For doubly-linked: First node's previous points to last
     *
 * Compared to arrays: faster to add/remove elements, use more memory, slower to access elements
 */