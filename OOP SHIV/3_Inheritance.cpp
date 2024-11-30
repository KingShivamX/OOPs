#include <bits/stdc++.h>
using namespace std;

// Inheritance: getting the properties and methods from base class.
// child class inherits properties from parent class.
// after child class we add , ":" and then a access modifier and parent class name.

class Animal {
public:
    string breed;

    void eats() {
        cout << "eats" << endl;
    }
    void drinks() {
        cout << "drinks" << endl;
    }
};

// Inheriting   
// private funcs and data cannot he inherited.
// protected is same as privte but just can be inherited.

// mode of inheritance
// public mode, public funcs in parent will be public in child & protected will be proteceted 
// protected mode, public and private both will be protected in child class, cant access in main()
// private mode, public and private both will be proteced in child class, cant access in main()

class Fish : public Animal { 
public:
    string fish;

    void fins() {
        cout << "fins" << endl;
    }
};

//  It was Single level Inheritance
// Now we doing multi level Inheritance, when child class will also have its child

// Inheriting Fish, Fish is Inheriting Animal, so we have Inherited Animal too.
class Sea : public Fish {
public:
    string sea;

    void seaName() {
        cout << "Arabean sea" << endl;
    }
};

class Example {
public:
    void example() {
        cout << "example" << endl;
    }
};

// Multiple Inheritance, Inheriting multiple parent Classes in Child class.
class Nature : public Sea, public Example{
public:
    string nature;
    void nisarga() {
        cout << "this is nature" << endl; 
    }
}; // this class has inherited multiple parents.

// Hierarchical Inheritance, when one base class, has multiple child class.
// Hybrid Inhritance, when one base class has child class and that child class also has its child classes,
// Animal is Hybrid inheritance example, Multi level inhritance.
// Example class's child class is not inherited further, thus that is Hierarchical

int main() {

    Fish f1;
    f1.breed = "yes";
    cout << f1.breed << endl;
    f1.eats();

    Sea s1;
    s1.eats(); // animal class
    s1.fins(); // fish classs
    s1.seaName(); // sea class
    // this was milti level inheritance.

    Nature n1;
    n1.eats(); // animal inherited class
    n1.example(); // example inherited class
    n1.nisarga(); // self

    return 0;
}