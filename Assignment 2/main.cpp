#include "Rational.h"
#include <regex>
#include <sstream>
using namespace std;

string btos(bool b);

int main() {
    Rational rn1;
    Rational rn2;
    cout << "Enter first fraction: \n";
    cin >> rn1;
    cout << "Enter second fraction: \n";
    cin >> rn2;
    cout << "rn1: " << rn1 << endl;
    cout << "rn2: " << rn2 << endl;
    cout << rn1 << " == " << rn2 << ": " << btos(rn1 == rn2) << endl;
    cout << rn1 << " != " << rn2 << ": " << btos(rn1 != rn2) << endl;
    cout << rn1 << " < " << rn2 << ": " << btos(rn1 < rn2) << endl;
    cout << rn1 << " > " << rn2 << ": " << btos(rn1 > rn2) << endl;
    cout << rn1 << " <= " << rn2 << ": " << btos(rn1 <= rn2) << endl;
    cout << rn1 << " >= " << rn2 << ": " << btos(rn1 >= rn2) << endl;
    cout << rn1 << " + " << rn2 << " = " << rn1 + rn2 << endl;
    cout << rn1 << " - " << rn2 << " = " << rn1 - rn2 << endl;
    cout << rn1 << " * " << rn2 << " = " << rn1 * rn2 << endl;
    cout << rn1 << " / " << rn2 << " = " << rn1 / rn2 << endl;
    return 0;
}

string btos(bool b) {
    if(b) {
        return "true";
    }
    return "false";
}