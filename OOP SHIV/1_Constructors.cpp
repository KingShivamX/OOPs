#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    string name;
    string color;
    int* milage;

    // constructor, a special method (func) invoked automatically at the time of object creation.
    // same name as class, dosent have return type, should be in public, as main will call.
    // it is only called once when object is created, memory allocation happens when called.
    // Constructor is used for initilization of properties.

    Car(string name, string color) {
        cout << "constructor is called" << endl;
        // name = nameVal;
        // color = colVal;

        // this is a special pointer in cpp, which points to the current object.
        this->name = name;
        this->color = color;
        // (*this).color = color; // this is same as this->color, used with address pointers.

        // assigning value to milage
        milage = new int; // created space
        *milage = 10;
    }

    // non paramterized constructor, which gets called if no explicite constructor created.
    // this will be called if no parameters passed while object creation.
    Car()  {
        cout << "This is a non parameterized" << endl;
    } 
    // Constructor Overloding : Writing multiple same names constructor in a same class.

    // We can make our own costum copy constructor too
    // Shallow Copy: copies address referance of original array.
    // Deep Copy: creates a new original copy.
    // Compailer generally creates shallow copy of dynamicially allocated vars.
    // so we create costom copy constructor to create deep copy of dynamic address vars. 
    Car(Car &original){
        cout << "Custom copy constructor used" << endl;
        name = original.name;
        // just name prop will be copied other props wont we copied.

        milage = new int;
        *milage = *original.milage; // this copies the value.
        // milage = original.milage; // this copies the address.
    }
     
    void start() {
        cout << name << " started of color " << color << endl;
    }

    void stop(){
        cout << "stop car \n";
    }

    // getter 
    string getName(){
        return name;
    }
    string getColor(){
        return color;
    }
};

int main() {

    Car c1("Porsche", "Black"); // we passing data in constructor
    // c1.start();
    // c1.getName();
 
    // Car c2(); // non parametrized constructor called.

    // Copy Constrctor, which compiler makes. after we choose to copy entire object properties.
    Car c3(c1);
    cout << c3.getName() << endl; // this will have same property and its value as c1, as we passed that.
    cout << c3.getColor() << endl; // this will have same property and its value as c1, as we passed that.
    *c1.milage = 20;

    cout << *c3.milage << endl;
    cout << *c1.milage << endl;

    return 0;
}