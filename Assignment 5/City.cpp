#include "City.h"

City::City() {
    for(int y = 0; y < GRIDSIZE; y++) {
        for(int x = 0; x < GRIDSIZE; x++) {
            grid[x][y] = new Organism();
        }
    }
    mt = std::mt19937_64(rd());
}
City::~City() = default;

Organism* City::getOrganism(int x, int y) {
    return grid[x][y];
}

void City::setOrganism(Organism *organism, int x, int y) {
    grid[x][y] = organism;
}

std::ostream& operator<<(std::ostream &output, City &city) {
    Organism *organism;
    output << "+";
    for(int i = 0; i < GRIDSIZE; i++) {
        output << '-';
    }
    output << "+\n";
    for(int y = 0; y < GRIDSIZE; y++) {
        output << "|";
        for(int x = 0; x < GRIDSIZE; x++) {
            organism = city.grid[x][y];
            output << *organism;
        }
        output << "|\n";
    }
    output << "+";
    for(int i = 0; i < GRIDSIZE; i++) {
        output << '-';
    }
    output << "+\n";
}
int City::getRand(int max) {
    std::uniform_int_distribution<int> dist (0, max - 1);
    return dist(mt);
}


void City::endStep() {
    for(auto& row: grid) {
        for(Organism* organism: row) {
            organism->endTurn();
        }
    }
}