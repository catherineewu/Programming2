#include <iostream>
#include <vector>
#include <string>

/** POINTER BASICS:
    * Pointer: data type that stores memory address of another piece of data
    * Has own memory address
    * "key to locker"
    * Memory addresses stay the same while program is running (changes b/w runs)
    * Can be reassigned, can initialize an empty (null) pointer
    * Many pointers can point to one address
    *
    * When used to pass parameter to function, must dereference
    * ex: if p is a pointer, then p->GetName() is how object pointed by p is passed to function
*
* REFERENCE BASICS:
    * Allows you to access the original variable using a different name
    * Doesn't create a new copy of the variable - any reference changes change the original variable
    * Used to pass variables to functions via reference
    * Can't be reassigned, MUST be initialized (no null reference)
    * Shares memory address with original variable
*
    * Use of references: as parameters, return types (for class member variables)
    * Recommended way of passing class objects around a program
    * Pass parameter to function with reference: no need to dereference
    * ex: if r is a reference, then r.GetName() is how object is passed to function
*
*
* USAGE - Pointers vs. References: use pointers when needed, references for all other cases
    * If need to reassign targets (ex: change player), use pointers
    * Can't create array of references
    * Use pointers when dynamically creating new data
*
*/


// Class for class reference
class Dino {
public:
    std::string type = "T-Rex";
    int weight = 60000;
    std::string roar = "RAWR!";

    void Rawr() const {
        std::cout << roar << std::endl;
    }
};

int main_pointers () {
    std::string name = "Ally";
    int number = 10;

    // DECLARE POINTER: type* pointer_name; or type *pointer_name;
    int *example_pointer = nullptr;  // nullptr explicitly points to nothing (0) vs. random memory data

    // ASSIGN POINTER: use reference operator, AMPERSAND & to assign pointer to object
    // Pointer type and data type must match
    // type* pointer = &object_name
    std::string *name_location = &name;
    int *number_location = &number;
    *number_location = 12;  // de-referenced pointer can be used to edit value of reference object
    std::cout << "Number's address: " << &number << std::endl;  // Use & to refer to object's address, not value

    // ACCESS OBJECT of pointer's memory address
    // Use DEFERENCE OPERATOR *pointer
    // only first element of array is returned
    std::cout << *number_location << std::endl;  // prints 10
    std::cout << number_location << std::endl;  // prints pointer's memory address

    // Pointer to another pointer, stores memory address of other pointer
    int **pointer_pointer = &example_pointer;
    std::cout << *pointer_pointer << std::endl;  // prints example_pointer's memory address
    std::cout << **pointer_pointer << std::endl;  // prints example_pointer's data

    // Pointer used for character arrays to only put aside needed storage
    // const KEYWORD needed for pointers pointing to characters in arrays
    const char* names[] = {"Alex", "Deedee", "Kieran"};
    for (int i=0;i<sizeof(names)/sizeof(names[0]);i++) {
        std::cout << names[i] << std::endl;
    }

    // DECLARE REFERENCE: type& ref_name = object; or type &ref_name = object;
    int object = 2;
    int& alias = object;
    alias = 4;  // editing reference edits both ref and original object, so object = 4 too

    // Class references, ex: Dino class (defined above)
    Dino dinosaur;
    Dino& dinosaur_ref = dinosaur;
    std::cout << dinosaur_ref.type << std::endl;  // Access public attributes of dinosaur object with reference
    // Indirect membership operator: -> vs .
    dinosaur.Rawr();  // typical call to function with class instance object
    Dino *dino_key = &dinosaur;  // class pointer dino_key made to dinosaur instance
    dino_key->Rawr();  // indirect call to function with pointer

    return 0;
}