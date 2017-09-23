#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

class Test {
public:
    void mod2DArray(int p[][3], int rowSize, int colSize) {
        for(int row = 0; row < rowSize; row++) {
            for(int col = 0; col < colSize; col++) {
                p[row][col] += 10;
            }
        }
    }

};//end class

int main() {

    Test myTest = Test();
    int numArray[][3] = {{1,2,3},
                         {4,5,6},
                         {7,8,9}};
    int rowSize = 3;
    int colSize = 3;

    cout << &rowSize << endl;

    cout << "Array before mod:\n";
    for(int row = 0; row < rowSize; row++) {
        for(int col = 0; col < colSize; col++) {
            cout << " " << numArray[row][col];
        }
        cout << endl;
    }

    myTest.mod2DArray(numArray,rowSize,colSize);

    cout << "Array after mod:\n";
    for(int row = 0; row < rowSize; row++) {
        for(int col = 0; col < colSize; col++) {
            cout << " " << numArray[row][col];
        }
        cout << endl;
    }

//    vector<float> v;
//    v.assign(8,16.3);
//    v[2] = 16.4;
//    v[3] = 66.6;
//
//    v.push_back(11.8);
//    v.push_back(-7.3);
//
//    for(int i=0; i < v.size(); i++) {
//        cout << i << ": " << v[i] << endl;
//    }
//
//    vector<float>::iterator iter;
//    for(iter = v.begin();iter != v.end(); iter++) {
//        cout << *iter << endl;
//    }


//    int size;
//    //int myArray[size]; //issue - must have const value
//    int MyArrayOne[10];
//    const int SIZE = 10;
//    int MyArrayTwo[SIZE];
//
//    const int MAX = 5;
//    int nonD[MAX];
//    int c = 0;
//
//    cout << "Enter a number\n";
//    while(cin >> nonD[c]) { //
//        c++;
//        if(c<5)
//            cout << c << " elements used, max is: " << MAX << endl;
//        else
//            cout << "At max - next will exceed array size\n";
//
//        for(int i = 0; i < MAX; i++) {
//            cout << nonD[i] << endl;
//        }
//
//        //A basic array will continue eo let you enter data pass the max
//        //Better alternative is vectors
//
//    }

//    int max = 5; //Note: not const
//    int *dynArray = new int[max];
//
//    int c = 0;
//
//    cout << "Enter an integer\n";
//    while(cin >> dynArray[c]) {
//        c++;
//        if(c >= max) {
//            max *= 2;
//            int *temp = new int[max];
//
//            for(int i = 0; i < c; i++) {
//                temp[i] = dynArray[i];
//            }
////            delete dynArray; //Creates mem leak - only deletes first element
//            delete []dynArray;
//
//            dynArray = temp;
//
//
//        }
//
//    }

    return 0;
}

















