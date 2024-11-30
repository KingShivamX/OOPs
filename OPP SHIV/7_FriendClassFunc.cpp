#include <bits/stdc++.h>
using namespace std;

//// Friend Class & Functions:
    // it is not possible to access the private & protected data in other classes
    // but a Friend class or a Friend function can acess private and protected members of other classes,
    // in which it is declared as a friend.

class A {
    string secret = "Secret Data";

    friend class B;
    // we are making B friend of A class, so now B can access the private data from A class.
    // A class cannot access members of B class.

    friend void revealSecret(A &obj); // writing all signature of func after friend keyword.
    // making revealSecret func a Friend Function of A class.

};


//// Frined class
class B { // B is frined class of A class
public: 
    void showSecret(A &obj) { // taking object of/type of A class.
        cout << obj.secret << endl; // it will give error as, secret is private.
        // but now B is friend of A class so it can access.
    }

};

//// Frined Function
// This is now a Friend Function of A class
void revealSecret(A &obj) { // func will take obj of A class
    cout << obj.secret << endl; // we cannot access screte as it is private value of A.
}


int main() {
    A a1;
    B b1;

    b1.showSecret(a1);

    revealSecret(a1);

    return 0;
}