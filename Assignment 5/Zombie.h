#ifndef _Zombie_H
#define _Zombie_H

#include "Organism.h"

class Zombie : public Organism
{
protected:
    enum Adjacent {UP, UP_LEFT, LEFT, DOWN_LEFT, DOWN, DOWN_RIGHT, RIGHT, UP_RIGHT, NUM_ADJACENTS};
public:
    Zombie(City *city);
    virtual ~Zombie();

    void move() override;
};

#endif
