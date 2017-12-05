#include <iostream>
#include <windows.h>
#include "City.h"
#include "Human.h"
#include "Zombie.h"

using namespace std;

void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

void pause() {
    clock_t t;
    t = clock();
    while((float) (clock() - t) / CLOCKS_PER_SEC < PAUSE_SECONDS) {
        continue;
    }
}

int main() {
    auto *city = new City();
    vector<Zombie*> zombies;
    vector<Human*> humans;
    for(int i = 0; i < ZOMBIE_STARTCOUNT; i++) {
        zombies.emplace_back(new Zombie(city));
    }
    for(int i = 0; i < HUMAN_STARTCOUNT; i++) {
        humans.emplace_back(new Human(city));
    }

    for (int iters = 0; iters <= ITERATIONS; iters++) {
        setCursorPosition(0, 0);
        //Movement
        for(auto zombie: zombies) {
            zombie->move();
            for(int i = 0; i < humans.size(); i++) {
                auto human = humans[i];
                if(*zombie == *human) {
                    humans.erase(humans.begin() + i);
                    break;
                }
            }
        }
        for(auto human: humans) {
            human->move();
        }

        //Breed
        for(int i = 0; i < zombies.size(); i++) {
            Zombie *zombie = zombies[i];
            int dir = zombie->canBreed();
            if(dir != -1) {
                zombie->breed(dir);
            }
        }
        for(int i = 0; i < humans.size(); i++) {
            Human *human = humans[i];
            int dir = human->canBreed();
            if(dir != -1) {
                auto newHuman = dynamic_cast<Human*> (human->breed(dir));
                humans.push_back(newHuman);
            }
        }

        city->endStep();

        //check for conversions
        for(int i = 0; i < humans.size(); i++) {
            auto human = humans[i];
            if(human->canConvert()) {
                zombies.push_back(dynamic_cast<Zombie*> (city->getOrganism(human->getx(), human->gety())));
                humans.erase(humans.begin() + (i--));
            }
        }

        for(int i = 0; i < zombies.size(); i++) {
            auto zombie = zombies[i];
            if(zombie->canConvert()) {
                humans.push_back(dynamic_cast<Human*> (city->getOrganism(zombie->getx(), zombie->gety())));
                zombies.erase(zombies.begin() + (i--));
            }
        }

        //Output 1
        cout << *city << endl;
        setCursorPosition(0, GRIDSIZE + 1);
        printf("\nSteps: %d/%d   ", iters, ITERATIONS);
        printf("\nHumans: %d      \nZombies: %d   ", humans.size(), zombies.size());
        cout.flush();
        //Pause 1
        pause();
//        cin.ignore();

        //Check for extinctions
        if(humans.empty() || zombies.empty()) {
            break;
        }
    }
    cout << endl;
    if(humans.empty()) {
        cout << "Zombies win! ";
    } else if(zombies.empty()) {
        cout << "Humans win! ";
    } else {
        cout << "Max iterations reached. ";
    }
    cout << "<Press enter to exit>";
    cin.ignore();
    return 0;
}