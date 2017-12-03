#include "Zombie.h"

Zombie::Zombie(City *city)
        :Organism(city, ZOMBIE_CH, ZOMBIE_COLOR) {}
Zombie::~Zombie() = default;

void Zombie::move() {
    Organism::move();
}
