#include "Human.h"

Human::Human(City *city)
        :Organism(city, HUMAN_CH, HUMAN_COLOR) {}
Human::Human(City *city, int x, int y)
        :Organism(city, HUMAN_CH, HUMAN_COLOR, x, y) {}
Human::~Human() = default;

int Human::canBreed() {
    if(((breedStepCounter++) < HUMAN_BREED) || convert) {
        return -1;
    }
    breedStepCounter = 0;
    int dir = city->getRand(NUM_DIRECTIONS);
    for(int i = 0; i < NUM_DIRECTIONS; i++) {
        if(dir >= NUM_DIRECTIONS) {
            dir = NORTH;
        }
        if(checkCollision(dir)) {
            dir += 1;
            continue;
        }
        return dir;
    }
    return -1;
}

Organism* Human::breed(int dir) {
    breedStepCounter = 0;
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