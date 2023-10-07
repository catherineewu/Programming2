#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Weapon {
public:
    string name;
    int power;
    float power_consumption;
    Weapon(string name, int power, float power_consumption) {
        this->name = name;
        this->power = power;
        this->power_consumption = power_consumption;
    }
};

class Spaceship {
public:
    string name;
    string ship_class;
    short length;
    int shield;
    float warp;
    int total_power;
    vector<Weapon> weapons;
    Spaceship(string name, string ship_class, short length, int shield, float warp, vector<Weapon> weapons) {
        this->name = name;
        this->ship_class = ship_class;
        this->length = length;
        this->shield = shield;
        this->warp = warp;
        this->weapons = weapons;

        for (int i=0;i<weapons.size();i++) {
            total_power += weapons[i].power;
        }
    }
    void PrintShip() const;
};

void OpenShipFile(string file_name, vector<Spaceship>& ship_store) {
    file_name = "C:\\" + file_name;
    ifstream ship;
    ship.open(file_name, ios_base::binary);  // open binary file storing ships

    int ships;  // count of # of ships in file
    int name_length;  // length of name, including null terminator
    string name;  // string data for name, including null terminator
    int class_length;  // length of ship's class name, including null terminator
    string ship_class;  // string data for class, inc. null terminator
    short length;  // ship's length (in m)
    int shield;  // shield capacity (in teraJoules)
    int warp;  // max warp speed of ship
    int weapons;  // count of # of weapons equipped on ship
    vector<Weapon> weapon_store;  // vector of Vector objects

    if (ship.is_open()) {
        ship.read((char*) &ships, 4);  // SHIPS
        for (int i=0;i<ships;i++) {  // Loops through for each ship

            /** Reading Name*/
            ship.read((char*) &name_length, 4);  // NAME_LENGTH
            char* name_array = new char[name_length];  // Array to store characters
            for (int i=0;i<name_length;i++) {  // Read into array
                ship.read((char*) &name_array[i], 4);
            }
            for (int i=0;i<name_length;i++) {  // Convert array to string
                name += name_array[i];
            }
            delete[] name_array;
            name_array = nullptr;

            /** Reading Class */
            ship.read((char*) &class_length, 4);  // CLASS_LENGTH
            char* class_array = new char[class_length];  // Array to store characters
            for (int i=0;i<class_length;i++) {  // Read into array
                ship.read((char*) &class_array[i], 4);
            }
            for (int i=0;i<class_length;i++) {  // Convert array to string
                ship_class += class_array[i];
            }
            delete[] class_array;
            class_array = nullptr;

            /** Reading Values */
            ship.read((char*) &length, 2);
            ship.read((char*) &shield, 4);
            ship.read((char*) &warp, 4);
            ship.read((char*) &weapons, 4);

            /** Reading Weapon Files */
            if (weapons != 0) {
                int weapon_name_length;
                string weapon_name;
                int power;
                float power_consumption;
                for (int i=0;i<weapons;i++) {
                    /** Reading weapon name */
                    ship.read((char*) &weapon_name_length, 4);
                    char* wn_array = new char[weapon_name_length];  // Array to store characters
                    for (int i=0;i<weapon_name_length;i++) {  // Read into array
                        ship.read((char*) &wn_array[i], 4);
                    }
                    for (int i=0;i<weapon_name_length;i++) {  // Convert array to string
                        weapon_name += wn_array[i];
                    }
                    delete[] wn_array;
                    wn_array = nullptr;

                    /** Reading Values */
                    ship.read((char*) &power, 4);
                    ship.read((char*) &power_consumption, 4);

                    Weapon current_weapon(weapon_name, power, power_consumption);
                    weapon_store.push_back(current_weapon);
                }
            }
            Spaceship current_ship(name, ship_class, length, shield, warp, weapon_store);
            ship_store.push_back(current_ship);
        }
    }
}

void Spaceship::PrintShip () const {
    cout << "Name: " << name << endl;
    cout << "Class: " << ship_class << endl;
    cout << "Length: " << length << endl;
    cout << "Shield capacity: " << shield << endl;
    cout << "Maximum warp: " << warp << endl;
    cout << "Armaments:" << endl;
    if (weapons.empty()) {
        cout << "Unarmed" << endl;
    } else {
        for (int f = 0; f < weapons.size(); f++) {
            cout << weapons[f].name;
            cout << ", " << weapons[f].power;
            cout << ", " << weapons[f].power_consumption;
            cout << endl;
        }
        cout << "Total firepower: " << total_power << endl;
    }
    cout << endl;
}
void PrintShips (const vector<Spaceship>& ships) {
    for (int i=0;i<ships.size();i++) {
        ships[i].PrintShip();
    }
};

int main_lab_4()
{
	cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;
	int option;
	cin >> option;

    vector<Spaceship> ships;

    if (option == 1) {
        OpenShipFile("friendlyships.shp", ships);
    } else if (option == 2) {
        OpenShipFile("enemyships.shp", ships);
    } else if (option == 3) {
        OpenShipFile("friendlyships.shp", ships);
        OpenShipFile("enemyships.shp", ships);
    }

	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;
	
	cin >> option;

    if (option == 1) {
        PrintShips(ships);
    } else if (option == 2) {

    }
	
	/* Work your magic here */
	
   return 0;
}