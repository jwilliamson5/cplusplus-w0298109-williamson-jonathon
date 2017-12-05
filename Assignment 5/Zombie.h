#ifndef _Zombie_H
#define _Zombie_H

#include "Organism.h"
#include "Human.h"

class Zombie : public Organism
{
protected:
    int starve_stepCounter = 0;
    enum Adjacent {UP, RIGHT, DOWN, LEFT, UP_RIGHT, DOWN_RIGHT, DOWN_LEFT, UP_LEFT, NUM_ADJACENTS};
public:
    explicit Zombie(City *city);
    Zombie(City *city, int x, int y);
    virtual ~Zombie();
    char getType(int dir);
    void move() override;
    int canBreed();
    Organism* breed(int dir);
    void endTurn();
};

#endif
