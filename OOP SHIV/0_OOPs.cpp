#include <bits/stdc++.h>
using namespace std;

// OOPs - Object Oriented Programming

// Class - Blueprint, Or a self defined data type, which can have its own pointers.
// Object - Instance of the Class

// 4 Pillars of OOPs
// 1. Encapsulation - Wrapping up of data and methods (member functions) in a single unit, it also helps in data hiding using access modifiers.
// 2. Inheritance - The process of inheriting properties and methods from one class to another, it helps in code reusability.
// 3. Polymorphism - The ability to take multiple forms, it can be achieved by method overriding and method overloading.       
// 4. Abstraction - The process of hiding the implementation details and showing only the functionality to the user.  

// Association - The relationship between two classes, it can be one-to-one, one-to-many, many-to-one, many-to-many
// Aggregation - The process of combining two or more classes into a single unit, it is a specialized form of association
// Composition - The process of combining two or more classes into a single unit, it is a specialized form of aggregation

// to create a class we use the keyword "class"
// class is a blueprint for creating objects

class student {
    // Access Modifiers - public, private, protected
    // public - accessible to everyone, class and outside the class
    // private - accessible to the class only, not outside the class
    // protected - accessible to the class and its derived classes, used in inheritance

    // default access modifier for a class is private

private:
    string name;
    int age;
    int roll_no;

public:
    // setter methods, used to set the values of the private members
    void setName(string n) {   
        name = n;
    } 
    void setAge(int a) {
        age = a;
    }
    void setRollNo(int r) {
        roll_no = r;
    }

    // getter methods, used to get the values of the private members    
    void getDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Roll No: " << roll_no << endl;
    }
};

int main() {

    // we cannot access the meathods and data of class without creating a Object of that class.
    student s1;
    s1.setName("Shivam");
    s1.setAge(20);
    s1.setRollNo(1);

    s1.getDetails();

    return 0;
}