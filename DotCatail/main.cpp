#include <iostream>
#include <conio.h>
using namespace std;

class Cat {

private:
    int itsAge;

public:
    Cat() {
        itsAge = 2;
    }

    ~Cat(){} //destructor, for garbage collection

    int getAge() const {
        return itsAge;
    }

    void setAge(int age) {
        itsAge = age;
    }

};//end class


int main() {

    Cat *pCharlie = new Cat; //note no parenthesis
    Cat fritz = Cat(); //Requires constructor call

    pCharlie->setAge(5);
    fritz.setAge(3);

    cout << "Charlie is " << pCharlie->getAge() << " years old.\n"; //Instead of using (*pCharlie).getAge() every time, use pCharlie->getAge()
    cout << "Fritz is " <<  fritz.getAge() << " years old.\n";


    return 0;
}