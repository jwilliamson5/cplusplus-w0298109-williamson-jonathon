#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

/* Pointer Terminology
 *
 * Use * as the dereference operator
 * also use * as a declarative operator for declaring a new pointer var
 * use & as the address of operator
 * use -> as the points to operator - not used in this demo
 *
 */


int main() {

    string phrase1 = "I woz here. ";
    string phrase2 = "Here I woz. ";
    string phrase3 = "Woz I here? ";
    string phrase4 = "Yes I woz! ";

    cout << phrase1 + phrase2 + phrase3 + phrase4 << endl;

    cout << &phrase1 << endl;
    //cout << *phrase1 << endl; Won't complie because phrase1 isn't a pointer

    string *p1; //Declaring a pointer variable
    string *p2;
    string *p3;

    p1 = &phrase1; //Get address of phrase1 and assign to p1
    p2 = &phrase2;
    p3 = &phrase3;

    string *p4 = &phrase4;

    cout << p1 << endl; //Prints memory address
    cout << *p1 + *p2+ *p3 + *p4 << endl; //Fetches value of the pointers address, and returns value
    cout << *p1 << endl;
    cout << p1 << endl;
    cout << &p1 << endl;

    //How to make a "Nameless variable" (aka dynamic variable)

    int *pNless; //declare an integer pointer
    pNless = new int; // 'New' unique in C++, declares a var to the heap, rather than the stack
    *pNless = 3; //Fetch memory location and assign value
    cout << *pNless << endl;
    cout << pNless << endl;

    int *pN1 = new int(3); //Declaring pointer (nameless var) and assigning value in 1 line


    return 0;
}