#ifndef _Human_H
#define _Human_H

#include "Organism.h"

class Human : public Organism
{
public:
    explicit Human(City *city);
    Human(City *city, int x, int y);
    virtual ~Human();
    bool canBreed();
    Organism* breed();
};

#endif
