#include <string>
using namespace std;

class FruitListing {  // Declare class

private:  // Declaring private class attributes
    string type;
    double weight;
    string fresh_or_frozen;
    double price;
    string origin;

public:
    FruitListing();  // Declaring default constructor
    // Declaring parameterized constructor
    FruitListing(string type, double weight, string fresh_or_frozen, double price, string origin);

    // Declare Functions
    string GetName();
    double PricePerPound(double price, double weight);
    void Display();

};

#ifndef TEST_FRUIT_SALE_H
#define TEST_FRUIT_SALE_H

#endif //TEST_FRUIT_SALE_H
