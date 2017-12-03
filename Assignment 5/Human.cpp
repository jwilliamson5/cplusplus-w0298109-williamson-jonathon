#include "Human.h"

Human::Human(City *city)
        :Organism(city, HUMAN_CH, HUMAN_COLOR) {}
Human::Human(City *city, int x, int y)
        :Organism(city, HUMAN_CH, HUMAN_COLOR, x, y) {}
Human::~Human() = default;

bool Human::canBreed() {
    if(breedStepCounter < HUMAN_BREED) {
        return false;
    }
    breedStepCounter = 0;
    for(int y =  -1; y <= 1; y++) {
        for(int x = -1; x <= 1; x++) {
            if((x == 0 && y == 0)
               || this->x + x < 0
               || this->x + x >= GRIDSIZE
               || this->y + y < 0
               || this->y + y >= GRIDSIZE) {
                continue;
            }
            if(city->getOrganism(this->x + x, this->y + y)->getSpecies() == SPACE_CH) {
                return true;
            }
        }
    }
    return false;
}

Organism* Human::breed() {
    int dir = city->getRand(NUM_DIRECTIONS);
    while(true) {
        switch (dir) {
            case (NORTH):
                return new Human(city, x, y - 1);
            case (EAST):
                return new Human(city, x + 1, y);
            case (SOUTH):
                return new Human(city, x, y + 1);
            case (WEST):
                return new Human(city, x - 1, y);
            default:
                continue;
        }
    }
}