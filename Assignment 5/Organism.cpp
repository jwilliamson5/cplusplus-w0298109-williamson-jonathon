#include "Organism.h"

Organism::Organism() {
    species = SPACE_CH;
    color = 7;
}

Organism::Organism(City *city, char species, unsigned short color)
        :city(city), species(species), color(color) {
    spawn();
}

Organism::Organism(City *city, char species, unsigned short color, int x, int y)
        :city(city), species(species), color(color), x(x), y(y) {
    city->setOrganism(this, x, y);
}

Organism::~Organism() = default;

void Organism::move() {
    if(moved) {
        return;
    } else {
        moved = true;
    }
    int attempt_x = x;
    int attempt_y = y;
    int dir = city->getRand(NUM_DIRECTIONS);
    if(!checkCollision(dir)) {
        switch (dir) {
            case(NORTH):
                attempt_y -= 1;
                break;
            case (EAST):
                attempt_x += 1;
                break;
            case (SOUTH):
                attempt_y += 1;
                break;
            case (WEST):
                attempt_x -= 1;
                break;
            default:
                break;
        }
        city->setOrganism(this, attempt_x, attempt_y);
        city->setOrganism(new Organism(), x, y);
        x = attempt_x;
        y = attempt_y;
    }
}

bool Organism::checkCollision(int dir) {
    int attempt_x = x;
    int attempt_y = y;
    switch (dir) {
        case(NORTH):
            if(y-1 >= 0) {
                attempt_y -= 1;
            }
            break;
        case (EAST):
            if(x+1 < GRIDSIZE) {
                attempt_x += 1;
            }
            break;
        case (SOUTH):
            if(y+1 < GRIDSIZE) {
                attempt_y += 1;
            }
            break;
        case (WEST):
            if(x-1 >= 0) {
                attempt_x -= 1;
            }
            break;
        default:
            break;
    }

    if(city->getOrganism(attempt_x, attempt_y)->getSpecies() == SPACE_CH) {
        if(!(x == attempt_x && y == attempt_y)) {
            return false;
        }
    }
    return true;
}

void Organism::spawn() {
    int spawn_x = city->getRand(GRIDSIZE);
    int spawn_y = city->getRand(GRIDSIZE);

    while(city->getOrganism(spawn_x, spawn_y)->getSpecies() != SPACE_CH) {
        spawn_x = city->getRand(GRIDSIZE);
        spawn_y = city->getRand(GRIDSIZE);
    }
    x = spawn_x;
    y = spawn_y;
    city->setOrganism(this, x, y);
    moved = true;
}

char Organism::getSpecies() {
    return species;
}

int Organism::canBreed() {
    return -1;
}

Organism* Organism::breed(int dir) {
    return new Organism();
}

int Organism::getx() {
    return x;
}

int Organism::gety() {
    return y;
}

bool Organism::canConvert() {
    return convert;
}

void Organism::flagForConvert() {
    convert = true;
}

void Organism::endTurn() {
    moved = false;
}

void Organism::setConsoleColour(unsigned short colour)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    SetConsoleTextAttribute(hOut, colour);
}

bool Organism::operator==(Organism &other) {
    return (this->getx() == other.getx()) && (this->gety() == other.gety());
}

std::ostream& operator<<( std::ostream &output, Organism &organism ) {
    organism.setConsoleColour(organism.color);
    output << std::string(1, organism.species);
    organism.setConsoleColour(7);
}