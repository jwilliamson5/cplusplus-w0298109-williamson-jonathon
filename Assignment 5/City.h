#ifndef _CITY_H
#define _CITY_H

#include <iostream>
#include "GameSpecs.h"
#include "Organism.h"
#include <ctime>
#include <random>

class Organism;

const int GRID_WIDTH = GRIDSIZE;
const int GRID_HEIGHT = GRIDSIZE;

class City
{
protected:
    Organism *grid[GRID_HEIGHT][GRID_WIDTH];
//    std::random_device rd;
//    std::default_random_engine mt;

public:
    City();
    virtual ~City();

    Organism *getOrganism( int x, int y );
    void setOrganism( Organism *organism, int x, int y );
    void endStep();
    int getRand(int max);
    friend std::ostream& operator<<( std::ostream &output, City &city );

};

#endif

