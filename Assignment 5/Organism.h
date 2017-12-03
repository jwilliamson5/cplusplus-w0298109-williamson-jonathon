#ifndef _Organism_H
#define _Organism_H

#include <iostream>
#include <windows.h>
#include "GameSpecs.h"
#include "City.h"
#include <ctime>

class City;

class Organism
{
protected:
    int x;
    int y;
    char species;
    unsigned short color;
    bool moved = false;
    int breedStepCounter = 0;
    City *city;

    enum Direction { NORTH, EAST, SOUTH, WEST, NUM_DIRECTIONS };

public:
    Organism();
    Organism(City *city, char species, unsigned short color);
    Organism(City *city, char species, unsigned short color, int x, int y);
    virtual ~Organism();
    virtual void move();
    void spawn();
    virtual char getSpecies();
    virtual bool canBreed();
    virtual Organism* breed();
    int getx();
    int gety();
    void endTurn();
    void setConsoleColour(unsigned short colour);
    friend std::ostream& operator<<( std::ostream &output, Organism &organism );
};

#endif
