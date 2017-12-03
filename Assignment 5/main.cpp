#include <iostream>
#include <windows.h>
#include <wincon.h>
#include "City.h"
#include "Human.h"

using namespace std;

void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

int main() {
    auto *city = new City();
    int human_count = HUMAN_STARTCOUNT;
    Human* humans [HUMAN_STARTCOUNT];
    for(int i = 0; i < HUMAN_STARTCOUNT; i++) {
        humans[i] = new Human(city);
    }
    for (int iters = 0; iters < ITERATIONS; iters++) {
        setCursorPosition(0, 0);
        for(int i = 0; i < human_count; i++) {
            humans[i]->move();
        }
        cout << *city << endl;
        setCursorPosition(0, GRIDSIZE + 1);
        printf("\nSteps: %d    \n", iters);
        cout.flush();
        setCursorPosition(0, 0);
        Sleep(PAUSE_MILLISECONDS);
        for(int i = 0; i < human_count; i++) {
            if(humans[i]->canBreed()) {
                Human* human = humans[i];
                auto newHuman = dynamic_cast<Human*> (human->breed());
                Human* tmp [human_count + 1];
                for(int x = 0; x < human_count; x++) {
                    tmp[x] = humans[x];
                }
                tmp[human_count] = newHuman;
                human_count += 1;
                humans = new Human[human_count]; //TODO DJKHFG SJLKDGF JLKSDGF LJKHSDG
                for(int x = 0; x < human_count; x++) {
                    humans[x] = tmp[x];
                }
            }
        }
        cout << *city << endl;
        setCursorPosition(0, GRIDSIZE + 1);
        printf("\nSteps: %d    \n", iters);
        cout.flush();
        Sleep(PAUSE_MILLISECONDS);
        city->endStep();
    }
    return 0;
}