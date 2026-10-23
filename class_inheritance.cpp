#include <iostream>
#include <string>
using namespace std;
// BASE CLASS: Vehicle (Grandparent Level)
class Vehicle {
protected:
    string brand; 

public:
    Vehicle(string b) : brand(b) {}

    void startEngine() const {
        cout << brand << " engine system ignited.\n";
    }
};
// INTERMEDIATE CLASS: Car (Parent Level - Inherits from Vehicle)
class Car : public Vehicle {
protected:
    int numberOfDoors;

public:
    Car(string b, int doors) : Vehicle(b), numberOfDoors(doors) {}

    void honk() const {
        cout << brand << " says: Beep! Beep!\n";
    }
};
// MOST DERIVED CLASS: ElectricCar (Child Level - Inherits from Car)
class ElectricCar : public Car {
private:
    int batteryCapacity;

public:
    ElectricCar(string b, int doors, int battery) 
        : Car(b, doors), batteryCapacity(battery) {}

    void displaySpecs() const {
        cout << "--- Electric Car Report Card ---\n";
        cout << "Vehicle Brand: " << brand << "\n";
        cout << "Door Count: " << numberOfDoors << "\n";
      cout << "Battery Capacity: " << batteryCapacity << " kWh\n";
    } 
};
int main() {
    ElectricCar myTesla("Tesla Model 3", 4, 75);

    myTesla.displaySpecs();   
    myTesla.startEngine();  
    myTesla.honk();           

    return 0;
}
