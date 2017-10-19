#include "Rational.h"
#include <iostream>
using namespace std;

string btos(bool b) {
    if(b) {
        return "true";
    }
    return "false";
}

int main() {
    cout << "Rational rn_default;\n";
    Rational rn_default;
    cout << "= " << rn_default << endl;
    cout << endl;

    cout << "Rational rn_1Int(5);\n";
    Rational rn_1Int(5);
    cout << "= " << rn_1Int << endl;
    cout << endl;

    cout << "Rational rn_1Int_neg(-5);\n";
    Rational rn_1Int_neg(-5);
    cout << "= " << rn_1Int_neg << endl;
    cout << endl;

    cout << "Rational rn_1Int_0(0);\n";
    Rational rn_1Int_0(0);
    cout << "= " << rn_1Int_0 << endl;
    cout << endl;

    cout << "Rational rn_2Int(1,2);\n";
    Rational rn_2Int(1,2);
    cout << "= " << rn_2Int << endl;
    cout << endl;

    cout << "Rational rn_2Int_negNum(-1,2);\n";
    Rational rn_2Int_negNum(-1,2);
    cout << "= " << rn_2Int_negNum << endl;
    cout << endl;

    cout << "Rational rn_2Int_negDen(1,-2);\n";
    Rational rn_2Int_negDen(1,-2);
    cout << "= " << rn_2Int_negDen << endl;
    cout << endl;

    cout << "Rational rn_2Int_dblNeg(-1,-2);\n";
    Rational rn_2Int_dblNeg(-1,-2);
    cout << "= " << rn_2Int_dblNeg << endl;
    cout << endl;

    cout << "Rational rn_2Int_0Num(0,2);\n";
    Rational rn_2Int_0Num(0,2);
    cout << "= " << rn_2Int_0Num << endl;
    cout << endl;

    cout << "Rational rn_2Int_0Num_negDen(0,-2);\n";
    Rational rn_2Int_0Num_negDen(0,-2);
    cout << "= " << rn_2Int_0Num_negDen << endl;
    cout << endl;

//    cout << "Rational rn_2Int_0Den(2,0);\n";
//    Rational rn_2Int_0Den(2,0);
//    cout << "= " << rn_2Int_0Den << endl;
//    cout << endl;

    cout << "Rational rn_reduce(6,12);\n";
    Rational rn_reduce(6,12);
    cout << "= " << rn_reduce << endl;
    cout << endl;

    cout << "Rational rn_reduce2(12,6);\n";
    Rational rn_reduce2(12,6);
    cout << "= " << rn_reduce2 << endl;
    cout << endl;

    cout << "Rational rn_getSet(16/18);\n";
    Rational rn_getSet(16,18);
    cout << "rn_getSet.getNumerator();\n";
    cout << "= " << rn_getSet.getNumerator() << endl;
    cout << "rn_getSet.getDenominator();\n";
    cout << "= " << rn_getSet.getDenominator() << endl;
    cout << "rn_getSet.setNumerator(-8);\n";
    rn_getSet.setNumerator(-8);
    cout << "= " << rn_getSet.getNumerator() << endl;
    cout << "rn_getSet.setDenominator(-9);\n";
    rn_getSet.setDenominator(-9);
    cout << "= " << rn_getSet.getDenominator() << endl;
    cout << "rn_getSet.setDenominator(-9);\n";
    rn_getSet.setDenominator(-9);
    cout << "rn_getSet = " << rn_getSet << endl;
    cout << endl;

    return 0;
}