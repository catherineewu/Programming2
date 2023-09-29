#include <iostream>
using namespace std;

/** EXAMPLE: MOVEMENT/PATHFINDING OF CHARACTER OBJECT
Player Movement Algorithm:
 * If destination is not null and player not at destination, take step toward destination.
 * Then, if player is at destination (destination = destination->next)
 *
 * In case of roadblock (EX: pointer from one Node to next broken)
 * Insert new waypoint b/w 2 existing waypoints
 */
class Waypoint {
public:
    float xCoord;
    float yCoord;
    Waypoint* next;
    Waypoint(int x, int y) {xCoord = x;
    yCoord = y;}
};
class Character {
    Waypoint* destination;
};


/** Algorithm that accounts for edge cases of first and last node
void RemoveNode(Waypoint* target) {
    if (target == head) {// edge case to remove first node;}
    else if (target == tail) {// edge case to remove last node;}
    else {// code for any middle nodes}
}*/

int main_llo() {
    Waypoint* head = new Waypoint(40, 60);  // create head Node
    head->next = new Waypoint(10, 10);  // create next Node
    Waypoint* currentPoint = head;  // variable currentPoint to iterate through Nodes, copy constructed from head Node

    while (currentPoint->next != nullptr) {
        // with 2 Nodes, only prints from first since when while loop reaches second, next = nullptr
        cout << currentPoint->xCoord << ", " << currentPoint->yCoord << endl;
        currentPoint = currentPoint->next;  // set currentPoint variable to next node forward
    }
    currentPoint->next = new Waypoint(80, 80);  // create new Node at end



    return 0;
}

/** LINKED LIST OPERATIONS:
 * Algorithms similar for doubly-linked lists, with additional features for previous pointer and bidirectional traversing.
 *
 * Insert Node into end of existing list
 * 1) Create new Node  2) Set prior last node's next pointer to new Node  3) Set new Node's pointer to nullptr
 *
 * Adding Node to front of existing list
 * 1) Create new Node  2) Set its next node to start of list  3) Set current head pointer to new Node
 *
 * Insert Node between 2 nodes
 * 1) Create new Node  2) Set its next pointer to node that will follow  3) Set previous node's next pointer to new Node
 *
 * Removing Head Node
 * 1) Create pointer to node after head  2) Delete head node  3) Set head node to created pinter
 *
 * Removing Node (prior Node > Node to be deleted > following Node)
 * 1) Get pointer to prior Node  2) Set prior Node's next pointer to following Node  3) Delete Node
 *
 * Checking for Node Validity: check each node one at a time, make sure have valid pointer, then do the operation
 *
 * EDGE CASES: special circumstances that need specific code
 * Many algorithms' code works in almost all cases, except edge cases
 * EX: empty or full list, operation on first or last node, if value is at some min (like 0) or max, or nullptr
 *
 * OTHER OPERATION EXAMPLES: can utilize existing/basic linked list functionality
     * Combine two lists of nodes
     * Split a node list to multiple parts
     * Remove every other node
     * Insert <X> nodes after/before existing nodes
 *
 */