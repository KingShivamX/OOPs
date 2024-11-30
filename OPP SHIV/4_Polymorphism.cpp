#include <bits/stdc++.h>
using namespace std;

// Polymorphism: it is the ability of objects to take on different forms,
// or behave in different ways depending on the context in which they are used.
// when we create multiple functions or constructors with same name, that there is polymorphism.

// Types of polymorphism, Compile time polymorphism & runtime polymorphism.

// ////////////////////////////////////////////////////////////////////////////////////////
// In Compile time polymorphism:
//// Function Overloding, when we create multiple functions with same name in same class,
    // return type can be anything, but parametre type or parameter numbers should atleast differ.
class Print {
public:
    void show(int x) {
        cout << "int: " << x << endl; 
    }

    void show(string str) {
        cout << "string: " << str << endl;
    }
};

//// Constructor overloading, same as function, multiple Constructor with same name.

//// Operator Overloading,
    // Operator Overloading
    // Operator overloading allows us to define how operators (like +, -, *, etc.) behave when applied to objects of a class. 
    // we define it as, returnType operator opSymbol() {...}
class Complex {
private:
    int real;
    int img;

public:
    Complex(int r, int i) {
        this->real = r;
        this->img = i;
    }

    void showNum() {
        cout << real << " + " << img << "i\n";
    }

    // Operator overloading for the + operator
    // This function defines how the + operator behaves for Complex objects.
    // It takes a reference to another Complex object as a parameter.
    Complex operator + (Complex &obj) {
        // Add the real parts and imaginary parts of the two Complex objects
        int resReal = this->real + obj.real;   // Add real parts
        int resImg = this->img + obj.img;      // Add imaginary parts
        
        // Create a new Complex object with the results
        Complex ansObj(resReal, resImg); 

        // Return the new Complex object
        return ansObj; // Return the result of the addition
    }

    // Operator Overloading for - operator
    void operator - (Complex &obj) {
        int realPart = this->real - obj.real;
        int realImg = this->img - obj.img;
        Complex ans(realPart, realImg);

        ans.showNum(); // result will be automatically printed.
    }
};

// /////////////////////////////////////////////////////////////////////////////////
// in Runtime polymorphism. (dynamic binding)
//// Function overridding, when parent and chid both class have same function with diffrent implimentation.
    // parent class function is said to be overridden. over child.
    // it is decided at run time, which function is to be used. compiler does not know.

//// Virtual functions, a member function which will be redefined in dirived class,
    // we add virtual keyword before return type if function.
    // it is compulsary to redefine a virtual function in child class.

class Parent {
public:
    void show() {
        cout << "parent class show \n";
    }
    
    virtual void hello() { // virtual function
        cout << "parent hello \n";
    }
};
class Child : public Parent {
public:
    void show() {
        cout << "Child class show \n";
    }

    // redefining virtual func, virtual keyword is not used in base class
    // we can use override keyword after function name, explecitly showing it is overridden.
    void hello() override {
        cout << "child hello \n";
    }
};

int main() {

    // Function Overloding, Compile time polymorphism
    Print p1;
    p1.show(6); 
    p1.show("shiva");

    Complex c1(1, 2);
    c1.showNum();
    Complex c2(3, 4);
    c2.showNum();
    cout << endl;

    Complex c3 = c1 + c2; // c1.operator+(c2);, internally 
    // we can perform arthematic operation on objects now.
    c3.showNum();

    c2 - c1; // c1.operator-(c2);

    //////
    Child child1;
    child1.show(); 
    // Child class show function will be printed, as it is obj of child class.
    // this overridding is decided at runtime of program.

    Parent parent1;
    parent1.show(); // it will show parent class func, as it is obj of parent class.

    Child child2;
    Parent *ptr; // pointer pointing to object of Parent class.
    ptr = &child2; // now it is pointing to the object of child class,
    // binding parent object to child, in run time.
    ptr->hello(); // (*ptr).hello(); // virtual function.
    // now child class hello function will be printed. as Object in ptr is of Child class.
    // as it was a virtual function, overridden in child class.
    // This is called runtime polynorphism, all things hapenning at runtime.

    // Same way to do that
    Parent *ptr2 = new Child(); // making object of Child and stoirng into ptr2 pointer.
    ptr2->hello(); // Child Class hello will be called, as object is of child.
    delete ptr2; // deleting it as it was created dynamically.
    
    return 0;
}