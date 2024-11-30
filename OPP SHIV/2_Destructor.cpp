#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    string name;
    string color;
    int* milage;

    // costum constructor
    Car(string name, string color) {
        cout << "constructor is called" << endl;
        this->name = name;
        milage = new int; 
        *milage = 10;
    }

    // copy constructor
    Car(Car &original){
        cout << "Custom copy constructor used" << endl;
        name = original.name;

        milage = new int;
        *milage = *original.milage;
    }

    // Destructor, it is opposite of constructor.
    // Used to deallocate all the memory after program executed.
    // Destructor is automatically created by compiler. but deallocates just statically created memory.
    // So to deallocate dynamically created memory, we create custome Destructor. 
    // We add Not ~ symbol before Class name to create a destructor.

    ~Car() { 
        cout << "costom destructor called" << endl;
        // to deallocate dynamic once just, rest will be done.
        if(milage != nullptr) { // only if milage has some address.
            delete milage; // deleting that address.
            cout << "milage deleted" << endl;
        }
    }
    //  will be called for all objects.

};

int main() {
    Car c1("Porsche", "Black");

    Car c3(c1);
    cout << c3.name << endl; 
    cout << c3.color << endl; 
    *c1.milage = 69;
    
    cout << *c3.milage << endl;
    cout << *c1.milage << endl;

    return 0;
}