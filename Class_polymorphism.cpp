#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;
// PARENT CLASS: Shape
class Shape {
public:
    // Virtual member function
    virtual void calculateArea() const {
        cout << "Area calculation for a generic shape is undefined.\n";
    }
    // Virtual Destructor 
    virtual ~Shape() {
        cout << " Shape resources cleaned up.\n";
    }
};
// DERIVED CLASS 1: Circle (Overrides Parent Function)
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r > 0 ? r : 1.0) {}
    // Overriding the virtual member function
    void calculateArea() const override {
        double area = M_PI * radius * radius;
        cout << " Circle with radius " << radius << " -> Calculated Area: " << area << "\n";
    }

    ~Circle() override {
        cout << " Circle destroyed.\n";
    }
};
// 3. DERIVED CLASS 2: Rectangle (Overrides Parent Function)
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w > 0 ? w : 1.0), height(h > 0 ? h : 1.0) {}
    //  Overriding the virtual member function
    void calculateArea() const override {
        double area = width * height;
        cout << "Rectangle (" << width << "x" << height << ") -> Calculated Area: " << area << "\n";
    }

    ~Rectangle() override {
        cout << " Rectangle destroyed.\n";
    }
};

int main() {
    cout << "--- Initializing Dynamic Objects ---\n\n";
    // Creatng base-class pointers pointing to derived-class objects
    Shape* shape1 = new Circle(5.0); 
    Shape* shape2 = new Rectangle(4.0, 6.0); 

    cout << "--- Executing Runtime Polymorphism ---\n";
    
    // Call the virtual function through the base-class pointers
    shape1->calculateArea();
    shape2->calculateArea(); 
    cout << "\n--- Memory Cleanup Sequence ---\n";
    // Deleting via base pointers executes the overridden child destructors
    delete shape1; 
    delete shape2;

    return 0;
}
