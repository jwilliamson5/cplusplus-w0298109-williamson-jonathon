#ifndef _Organism_H
#define _Organism_H

#include <iostream>
#include <windows.h>
#include "GameSpecs.h"
#include "City.h"

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
    bool convert = false;
    City *city;

    enum Direction { NORTH, EAST, SOUTH, WEST, NUM_DIRECTIONS };

public:
    Organism();
    Organism(City *city, char species, unsigned short color);
    Organism(City *city, char species, unsigned short color, int x, int y);
    virtual ~Organism();
    virtual void move();
    bool checkCollision(int dir);
    void spawn();
    virtual char getSpecies();
    virtual int canBreed();
    virtual Organism* breed(int dir);
    int getx();
    int gety();
    bool canConvert();
    void flagForConvert();
    virtual void endTurn();
    void setConsoleColour(unsigned short colour);
    bool operator== (Organism& other);
    friend std::ostream& operator<<( std::ostream &output, Organism &organism );
};

#endif
