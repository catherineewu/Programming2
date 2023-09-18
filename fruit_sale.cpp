/**

#include "fruit_sale.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Define default constructor:
FruitListing::FruitListing() {
    type = "Strawberries";
    weight = 2.3;
    fresh_or_frozen = "Fresh";
    price = 4.99;
    origin = "Guatemala";
}

// Define parameterized constructor:
FruitListing::FruitListing(string type, double weight, string fresh_or_frozen, double price,
                           string origin) {
    this->type = type;
    this->weight = weight;
    this->fresh_or_frozen = fresh_or_frozen;
    this->price = price;
    this->origin = origin;
}

string FruitListing::GetName() {
    return fresh_or_frozen + " " + type;
}

double FruitListing::PricePerPound(double price, double weight) {
    return price / weight;
}

void FruitListing::Display() {
    cout << fixed << setprecision(2) << "FRUIT LISTING: " << GetName() <<"\n\tPrice/Lb: $" << PricePerPound(price, weight) << endl;
}

int main() {
    cout << "Default FruitListing: " << endl;
    FruitListing defaultfruit;
    defaultfruit.Display();

    FruitListing raspberries("Raspberries", 1.65, "Fresh", 4.99, "Mexico");
    FruitListing pears("Pears", 4.20, "Frozen", 1.29, "Canada");

    raspberries.Display();
    pears.Display();

    return 0;
}

 */