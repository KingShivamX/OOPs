#include <bits/stdc++.h>
using namespace std;

// Static Keyword, Variables declared as static in a function are created and initialised once while entire program execution.
// Even if we call a function multiple times, that variable will not be reaassigned with thet value again, it will stay in memory.

void count() {
    static int count = 0; // will be initialised only ones first time.
    count++;
    cout << count << "\n";    
}

// Static var in a class behaves same, iniatialised once, and is shared among all the objects.
// that static var will not be created speperate for all the objects.
class Count {
public:
    // static int x = 0; // we cannot assign value to normal static vars in class
    static const int x = 6; // it should be const, to assign value

    static int y; // will be assigned outsied of class

    //// learning Static Objects
    Count() {
        cout << "Object created" << endl;
    }
    ~Count() {
        cout << "Object deleted" << endl;
    }

};
// if we want create non const vars we need to create that outside of class.
// Using Scope Operator :: Count::y means, y from Count. like std::cout, cout from std.
int Count::y = 1; // asigned a non const value.
// all objects will share this single y and can be modified

int main() {

    count(); // 1
    count(); // 2
    count(); // 3
    // value will keep increasing, as var is static 
    static const auto num = 5;

    Count c1;
    Count c2;
    cout << c1.x << endl; 
    cout << c2.x << endl;
    // both objects pointing to same static variable
    
    cout << c1.y++ << endl; // 1
    cout << c2.y++ << endl; // 2, as both diffrent operators share same static non-const var 

    //// Static Objects, which will not get deleted after the scope / stack ended.
    if(true) {
        Count c3; // this object will be created and will be deleted after if block ended.

        // but if we want it to be remain until program (main func) ends, we use static key word.
        static Count c4; // this will remain in memory even after if block ends.
    }

    cout << "Program ended..." << endl;
    
    return 0;
}