This program demonstrates multilevel inheritance in C++. It models an electric car using three classes:
1. Vehicle — the base class (grandparent level).
2. Car — inherits from Vehicle (parent level).
3. ElectricCar — inherits from Car (child level).
Because of this inheritance chain, an ElectricCar object can use features defined in both Car and Vehicle.
class vehicle
Vehicle is the first or base class. It contains information and behaviour that vehicles generally have.
protected: string brand;
- brand stores the vehicle's brand or model name.
- protected means that the variable can be accessed inside Vehicle and its derived classes, such as Car and ElectricCar.
- Code outside these classes cannot access brand directly.
Constructor: Vehicle(string b) : brand(b) {}
A constructor is a special function that runs automatically when an object is created.
- string b receives a text value.
- : brand(b) is a member initializer list. It initializes brand using the value of b.
- For example, if b is "Tesla Model 3", then brand becomes "Tesla Model 3".

 The Car Class
Car inherits from Vehicle. The syntax : public Vehicle means that Car publicly inherits the accessible public and protected features of Vehicle.
numberOfDoors
protected:
    int numberOfDoors;
- int is an integer data type.
- numberOfDoors stores the number of doors.
- It is protected, so Car and classes derived from Car can access it directly.
The Car constructor
This constructor accepts the vehicle brand and the number of doors.
- Vehicle(b) calls the constructor of the base class first, so the inherited brand is initialized.
- numberOfDoors(doors) initializes the door count.
For example, Car("Tesla Model 3", 4) would initialize the brand to "Tesla Model 3" and the door count to 4,
Function: honk()
This function prints the vehicle's brand followed by a horn sound. It can use brand because brand is a protected member inherited from Vehicle.

 The ElectricCar Class
ElectricCar inherits from Car. Since Car inherits from Vehicle, an ElectricCar also receives the accessible features of Vehicle.
batteryCapacity
private:
    int batteryCapacity;
- This variable stores the battery capacity.
- private means it can be accessed directly only by member functions of ElectricCar (and friends, if any are declared).
- Other classes and code outside ElectricCar cannot access it directly.
The value is displayed with the unit kWh, which means kilowatt-hours, a unit of energy.
The ElectricCar constructor
ElectricCar(string b, int doors, int battery)
    : Car(b, doors), batteryCapacity(battery) {}
This constructor accepts three values: brand, number of doors, and battery capacity.
- Car(b, doors) calls the Car constructor. The Car constructor then calls Vehicle(b) to initialize the brand.
- batteryCapacity(battery) initializes the battery capacity.
When an ElectricCar is created, constructors run from the base class towards the most derived class: Vehicle, then Car, then ElectricCar.
Function: displaySpecs()
This function prints a report containing the brand, number of doors, and battery capacity.

It can access:
- brand, inherited from Vehicle, because it is protected.
- numberOfDoors, inherited from Car, because it is protected.
- batteryCapacity, because it is a private member of ElectricCar and the function belongs to that class.

The main() function
main() is where program execution begins.
Creating the object
ElectricCar myTesla("Tesla Model 3", 4, 75);
This creates an object named myTesla from the ElectricCar class. Its values are:
- Brand: Tesla Model 3
- Number of doors: 4
- Battery capacity: 75 kWh
Calling the functions
1. myTesla.displaySpecs(); prints the electric car's details.
2. myTesla.startEngine(); calls a function originally defined in Vehicle and inherited through Car.
3. myTesla.honk(); calls a function defined in Car.
The object can call all three functions because it is an ElectricCar, which inherits from Car, which inherits from Vehicle.
return 0;
This indicates that the program has finished successfully