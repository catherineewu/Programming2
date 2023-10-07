#include <string>
#include <fstream>
using namespace std;
/**
SERIALIZATION
  - Taking a complex object and "flattening" it.
  - Condenses memory footprint for storage in a file or sharing w/another system.
  - On "receiving" end, must be DESERIALIZED (unflattened, assembled, constructed, etc.)
  - Deserialization converts to some appropriate file for use.
  EX: downloading large files in a .zip directory and expanding it to use

  No one way to serialize data, every object and program is different
  ALL objects ultimately boil down to primitive data (ints, chars, etc.)

SERIALIZE A CLASS
  - Writing essential data of class (ex: write each variable)
  - DESERIALIZE: read the data and store in class variables in same order
SERIALIZE A DYNAMIC ARRAY
  - Serialize class attributes for size, existing data
  - NOT _data pointer, but data in pointer, so _data[0], _data[1], etc...
  - Capacity likely not needed
SERIALIZE A LINKED LIST
  - Count variable, head and tail pointers, and data in each node (ignore previous/next pointers)

CONSIDERATIONS FOR SERIALIZING
  - Private class attributes - Serialize Class Function
  - Info in structures like dynamic arrays can be serialized to be stored in:
        - Vectors (vectorName.push_back(data));
        - Stack (stackName.push(thing));
        - Queue (queueName.enqueue(thing));
        - Linked List (linkedListName.AddTail(thing));
  */

/** EX: Serializing Class Objects*/
class Engine {
    double _power = 4.55;
public:
    void Serialize(ofstream& file) {
        file << _power;
    }
};
class Vehicle { // private class attributes:
    string _make;
    int _miles;
    Engine _engine;  // complex class contained
public:
    void Serialize(ofstream& file) {
        file << _make;
        file << _miles;
        _engine.Serialize(file);  // object serialized itself
    };
};

int main_serialization() {
    Vehicle aCar;
    ofstream outputFile("SomeFile.txt");
    aCar.Serialize(outputFile);  // objects serialize themselves
}