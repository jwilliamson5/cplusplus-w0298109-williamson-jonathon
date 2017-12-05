#include "Zombie.h"

Zombie::Zombie(City *city)
        :Organism(city, ZOMBIE_CH, ZOMBIE_COLOR) {}
Zombie::Zombie(City *city, int x, int y)
        :Organism(city, ZOMBIE_CH, ZOMBIE_COLOR, x, y) {}
Zombie::~Zombie() = default;

void Zombie::move() {
    if(moved) {
        return;
    }
    int dir = city->getRand(NUM_ADJACENTS);
    for(int i = 0; i < NUM_ADJACENTS; i++) {
        if(dir >= NUM_ADJACENTS) {
            dir = UP;
        }
        if(getType(dir) == HUMAN_CH) {
            int eat_x = x;
            int eat_y = y;

            if(dir >= NUM_DIRECTIONS) {
                switch(dir) {
                    case(UP_RIGHT):
                        eat_x += 1;
                        break;
                    case (DOWN_RIGHT):
                        eat_y += 1;
                        break;
                    case (DOWN_LEFT):
                        eat_x -= 1;
                        break;
                    case (UP_LEFT):
                        eat_y -= 1;
                        break;
                    default:
                        break;
                }
                dir -= 4;
            }
            switch(dir) {
                case(UP):
                    eat_y -= 1;
                    break;
                case (RIGHT):
                    eat_x += 1;
                    break;
                case (DOWN):
                    eat_y += 1;
                    break;
                case (LEFT):
                    eat_x -= 1;
                    break;
                default:
                    break;
            }
            city->setOrganism(this, eat_x, eat_y);
            city->setOrganism(new Organism(), x, y);
            x = eat_x;
            y = eat_y;
            starve_stepCounter = 0;
            moved = true;
            return;
        }
        dir++;
    }
    Organism::move();
}

char Zombie::getType(int dir) {
    int check_x = x;
    int check_y = y;

    if(dir >= NUM_DIRECTIONS) {
        switch(dir) {
            case(UP_RIGHT):
                check_x += 1;
                break;
            case (DOWN_RIGHT):
                check_y += 1;
                break;
            case (DOWN_LEFT):
                check_x -= 1;
                break;
            case (UP_LEFT):
                check_y -= 1;
                break;
            default:
                break;
        }
        dir -= 4;
    }
    switch(dir) {
        case(UP):
            check_y -= 1;
            break;
        case (RIGHT):
            check_x += 1;
            break;
        case (DOWN):
            check_y += 1;
            break;
        case (LEFT):
            check_x -= 1;
            break;
        default:
            break;
    }

    if(check_x < 0 || check_x >= GRIDSIZE || check_y < 0 || check_y >= GRIDSIZE) {
        return SPACE_CH;
    }

    return city->getOrganism(check_x, check_y)->getSpecies();
}

int Zombie::canBreed() {
    if((breedStepCounter++) < ZOMBIE_BREED) {
        return -1;
    }
    int dir = city->getRand(NUM_ADJACENTS);
    for(int i = 0; i < NUM_ADJACENTS; i++) {
        if(dir >= NUM_ADJACENTS) {
            dir = UP;
        }
        if(getType(dir) == HUMAN_CH) {
            return dir;
        }
        dir++;
    }
    return -1;
}

Organism* Zombie::breed(int dir) {
    int convert_x = x;
    int convert_y = y;

    if(dir >= NUM_DIRECTIONS) {
        switch(dir) {
            case(UP_RIGHT):
                convert_x += 1;
                break;
            case (DOWN_RIGHT):
                convert_y += 1;
                break;
            case (DOWN_LEFT):
                convert_x -= 1;
                break;
            case (UP_LEFT):
                convert_y -= 1;
                break;
            default:
                break;
        }
        dir -= 4;
    }
    switch(dir) {
        case(UP):
            convert_y -= 1;
            break;
        case (RIGHT):
            convert_x += 1;
            break;
        case (DOWN):
            convert_y += 1;
            break;
        case (LEFT):
            convert_x -= 1;
            break;
        default:
            break;
    }
    city->getOrganism(convert_x, convert_y)->flagForConvert();
    new Zombie(city, convert_x, convert_y);
    breedStepCounter = 0;
}

void Zombie::endTurn() {
    if((starve_stepCounter++) >= ZOMBIE_STARVE) {
        flagForConvert();
        new Human(city, x, y);
    }
    Organism::endTurn();
}