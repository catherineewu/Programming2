#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
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
    int total_power = 0;
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
void Spaceship::PrintShip () const {
    cout << "Name: " << name << endl;
    cout << "Class: " << ship_class << endl;
    cout << "Length: " << length << endl;
    cout << "Shield capacity: " << shield << endl;
    cout << "Maximum Warp: " << setprecision(2) << warp << endl;
    cout << "Armaments: " << endl;
    if (weapons.empty()) {
        cout << "Unarmed";
    } else {
        for (int f = 0; f < weapons.size(); f++) {
            cout << weapons[f].name;
            cout << ", " << weapons[f].power;
            cout << ", ";
            if (weapons[f].power_consumption > 10) {
                cout << setprecision(3) << weapons[f].power_consumption;
            } else {
                cout << setprecision(2) << weapons[f].power_consumption;
            }
            cout << endl;
        }
        cout << "Total firepower: " << total_power;
    }
}
void PrintShips(vector<Spaceship>& ship_vector) {
    for (int i=0;i<ship_vector.size();i++) {
        ship_vector[i].PrintShip();
        if (i != (ship_vector.size()-1)) {
            cout << endl << endl;
        }
    }
}
void PrintUnarmedShips(vector<Spaceship>& ship_vector) {
    for (int i=0;i<ship_vector.size();i++) {
        if (ship_vector[i].total_power == 0) {
            ship_vector[i].PrintShip();
        }
    }
}

void OpenShipFile(string file_name, vector<Spaceship>& ship_vector) {
    ifstream shipFile(file_name, ios_base::binary | ios_base::in);
    if (shipFile.is_open()) {
        int ship_count;
        /** SHIP COUNT: 4 BYTES */
        shipFile.read(reinterpret_cast<char*>(&ship_count), 4);
        for (int i=0;i<ship_count;i++) {
            int name_length;
            string name;
            int class_length;
            string ship_class;
            short length;
            int shield;
            float warp;
            int weapon_count;

            /** NAME LENGTH: 4 BYTES */
            shipFile.read(reinterpret_cast<char*>(&name_length), 4);

            /** NAME STRING: 1 BYTE X NAME LENGTH */
            for (int j=0;j<name_length;j++) {
                char temp;
                shipFile.read(reinterpret_cast<char *>(&temp), 1);
                name += temp;
            }

            /** CLASS LENGTH: 4 BYTES */
            shipFile.read(reinterpret_cast<char*>(&class_length), 4);

            /** CLASS STRING: 1 BYTE x CLASS LENGTH */
            for (int j=0;j<class_length;j++) {
                char temp;
                shipFile.read(reinterpret_cast<char *>(&temp), 1);
                ship_class += temp;
            }

            shipFile.read(reinterpret_cast<char*>(&length), 2);
            shipFile.read(reinterpret_cast<char*>(&shield), 4);
            shipFile.read(reinterpret_cast<char*>(&warp), 4);
            shipFile.read(reinterpret_cast<char*>(&weapon_count), 4);

            vector<Weapon> weapon_vector;
            if (weapon_count != 0) {
                for (int k = 0; k < weapon_count; k++) {
                    int weapon_name_length;
                    string weapon_name;
                    int power;
                    float power_consumption;

                    shipFile.read(reinterpret_cast<char *>(&weapon_name_length), 4);
                    //cout << "Length of weapon name: " << weapon_name_length << endl;

                    for (int m = 0; m < weapon_name_length; m++) {
                        char temp;
                        shipFile.read(reinterpret_cast<char *>(&temp), 1);
                        weapon_name += temp;
                    }
                    //cout << "Weapon Name: " << weapon_name << endl;

                    shipFile.read(reinterpret_cast<char*>(&power), 4);
                    shipFile.read(reinterpret_cast<char*>(&power_consumption), 4);
                    //cout << "Power: " << power << ", Consumption: " << power_consumption << endl;

                    Weapon current_weapon(weapon_name, power, power_consumption);
                    weapon_vector.push_back(current_weapon);
                }
            }
            Spaceship current_ship(name, ship_class, length, shield, warp, weapon_vector);
            ship_vector.push_back(current_ship);
            // current_ship.PrintShip();
        }
    }
}

Spaceship* FindStrongestWeapon(vector<Spaceship>& ship_vector) {
    int strongest_weapon_power = 0;
    Spaceship* strongest_weapon_ship;
    for (int i=0;i<ship_vector.size();i++) {
        for (int j=0;j<ship_vector[i].weapons.size();j++) {
            if (ship_vector[i].weapons[j].power > strongest_weapon_power) {
                strongest_weapon_power = ship_vector[i].weapons[j].power;
                strongest_weapon_ship = &ship_vector[i];
            }
        }
    }
    return strongest_weapon_ship;
}
Spaceship* FindMostPowerful(vector<Spaceship>& ship_vector) {
    int most_power = 0;
    Spaceship* most_powerful_ship;
    for (int i=0;i<ship_vector.size();i++) {
        if (ship_vector[i].total_power > most_power) {
            most_power = ship_vector[i].total_power;
            most_powerful_ship = &ship_vector[i];
        }
    }
    return most_powerful_ship;
}
Spaceship* FindWeakest(vector<Spaceship>& ship_vector) {
    int least_power = ship_vector[0].total_power;
    Spaceship* least_powerful_ship;
    for (int i=0;i<ship_vector.size();i++) {
        if (ship_vector[i].total_power != 0) {
            if (ship_vector[i].total_power < least_power) {
                least_power = ship_vector[i].total_power;
                least_powerful_ship = &ship_vector[i];
            }
        }
    }
    return least_powerful_ship;
}

int main() {
    cout << "Which file(s) to open?\n";
    cout << "1. friendlyships.shp" << endl;
    cout << "2. enemyships.shp" << endl;
    cout << "3. Both files" << endl;
    int option;
    cin >> option;

    vector<Spaceship> ship_vector;

    if (option == 1) {
        OpenShipFile("friendlyships.shp", ship_vector);
    } else if (option == 2) {
        OpenShipFile("enemyships.shp", ship_vector);
    } else if (option == 3) {
        OpenShipFile("friendlyships.shp", ship_vector);
        OpenShipFile("enemyships.shp", ship_vector);
    }

    cout << "1. Print all ships" << endl;
    cout << "2. Starship with the strongest weapon" << endl;
    cout << "3. Strongest starship overall" << endl;
    cout << "4. Weakest ship (ignoring unarmed)" << endl;
    cout << "5. Unarmed ships" << endl;

    cin >> option;

    if (option == 1) {
        PrintShips(ship_vector);
    } else if (option == 2) {
        Spaceship* strongest_weapon_ship = FindStrongestWeapon(ship_vector);
        (*strongest_weapon_ship).PrintShip();
    } else if (option == 3) {
        Spaceship* most_powerful_ship = FindMostPowerful(ship_vector);
        (*most_powerful_ship).PrintShip();
    } else if (option == 4) {
        Spaceship* weakest_ship = FindWeakest(ship_vector);
        (*weakest_ship).PrintShip();
    } else if (option == 5) {
        PrintUnarmedShips(ship_vector);
    }
    return 0;
}