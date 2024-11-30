#include <bits/stdc++.h>
using namespace std;

// Abstraction: The process of hiding the implementation details and showing only the functionality to the user.  
// One part is to use Access specifiers and hide all unnesaserry/secrete data from user.
// Other way of Implimenting Abstraction:

//// Abstract CLass & Pure Virtual Function (Abstract Functions):
    // Abstract class is a normal class but it is not used to create Objects.
    // Its purpose is to give blue print or interface to child class which inherited, they dont have clear defination.
    // Abstract class should have atleast 1 pure virtual function, compiler will recognize it so.
    // Functions in abstract class which dont have their clear defination, is called Pure virtual functions.
    // Virtual function are assigned with 0, to make them "pure", at time of decleration.

// abstract class
class Shape {
public:
    virtual void draw() = 0; 
    // abstract func, pure virtul func.
};

// implementing virtual functions in derived class.
class Circle : public Shape {
public:
    void draw() {
        cout << "draw Circle \n";
    }
};

class Square : public Shape {
public:
    void draw() {
        cout << "draw Square \n";
    }
};

int main() {

    Circle cir1;
    cir1.draw();

    Square sqr1;
    sqr1.draw();

    // Shape Obj1; // we cannot create objects of Abstract class, error will be occurred.
    // Obj1.draw();

    return 0;
}