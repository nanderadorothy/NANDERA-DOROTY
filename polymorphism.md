This C++ program demonstrates inheritance, function overriding, runtime polymorphism, dynamic memory allocation, and virtual destructors.

It defines a general class called Shape and two derived classes, Circle and Rectangle. Each derived class calculates its own area. In main(), the program creates the objects dynamically, calls their area functions through pointers to the base class, and then deletes the objects safely.

Shape is the base class. It represents a general shape, without specifying whether the shape is a circle, rectangle, or another type.
The calculateArea() function
- public means code outside the class can call this function.
- virtual allows a derived class's overridden version to be selected when the function is called through a base-class pointer or reference.
- void means the function does not return a value.
- const means the function promises not to modify the object's data members.
- The function prints a message because a generic shape has no single area formula.
This function is virtual so that Circle and Rectangle can provide their own area calculations.

The virtual destructor
A destructor is a special member function that runs when an object is destroyed. Its name begins with ~.
The destructor is marked virtual because the program deletes derived objects through pointers of type Shape*. This ensures that the derived-class destructor runs first, followed by the base-class destructor.

 Derived Class 1: Circle
class Circle : public Shape means Circle publicly inherits from Shape. It receives the accessible public and protected members of Shape.
The radius variable
double radius;
- double stores a number that can include a decimal part.
- radius stores the circle's radius.
- It is private, so it can be accessed directly only by member functions of Circle (and any friends, if declared).
The constructor receives a radius called r and initializes radius.

The expression r > 0 ? r : 1.0 is the conditional (ternary) operator:
- If r > 0 is true, use r.
- Otherwise, use 1.0.
This means a zero or negative radius is replaced with 1.0. It is a simple input safeguard, although a program could instead reject invalid values or report an error.
Overriding calculateArea()
- override tells the compiler that this function is intended to override a virtual function from the base class. The compiler reports an error if it does not correctly match a base-class virtual function.
- The area of a circle is:
  A = \pi r^2
- M_PI * radius * radius calculates π multiplied by the radius twice.
- The function then prints the radius and calculated area.
For the object created in main(), the radius is 5.0, so the area is approximately \(78.54\) square units.
The Circle destructor
This prints a message when a Circle object is destroyed. override is valid here because the base class has a virtual destructor.

 Derived Class 2: Rectangle
Rectangle also inherits publicly from Shape.
Width and height
- width stores the rectangle's width.
- height stores the rectangle's height.
- Both use double so they can hold decimal values.
- Both are private members of Rectangle.
The constructor
Rectangle(double w, double h)
    : width(w > 0 ? w : 1.0),
      height(h > 0 ? h : 1.0) {}
The constructor accepts width w and height h. Each value is checked separately. A positive value is kept; a zero or negative value is replaced with 1.0.
Overriding calculateArea()
The rectangle's area is calculated using:
A ={width}*{height}
The function prints the width, height, and calculated area.
The Rectangle destructor
The destructor prints a message when a Rectangle object is destroyed.

 The main() Function
Program execution begins in main().
Creating the objects dynamically
Shape* shape1 = new Circle(5.0);
Shape* shape2 = new Rectangle(4.0, 6.0);
- Shape* declares a pointer whose type is pointer-to-Shape.
- new Circle(5.0) creates a Circle object dynamically and returns a pointer to it.
- new Rectangle(4.0, 6.0) creates a Rectangle object dynamically.
- shape1 points to a Circle object with radius 5.0.
- shape2 points to a Rectangle object with width 4.0 and height 6.0.
Although the pointer types are both Shape*, the actual objects are different derived types.
Calling functions through pointers
shape1->calculateArea();
shape2->calculateArea();
The -> operator accesses a member through a pointer. Because calculateArea() is virtual, C++ chooses the function that matches the actual object:
- shape1->calculateArea() calls Circle::calculateArea().
- shape2->calculateArea() calls Rectangle::calculateArea().
This behaviour is called runtime polymorphism: the function implementation is selected at runtime according to the actual object type.
Deleting the objects
delete shape1;
delete shape2;
delete releases the dynamically allocated object. Since Shape has a virtual destructor, deleting through a Shape* correctly calls the derived destructor and then the base destructor.

For shape1, the order is:
1. Circle::~Circle()
2. Shape::~Shape()
For shape2, the order is:
1. Rectangle::~Rectangle()
2. Shape::~Shape()
This is important for safe cleanup when using polymorphic base-class pointers. In larger programs, smart pointers such as std::unique_ptr<Shape> are often preferred because they manage cleanup automatically.
return 0;
This indicates that main() completed successfully.