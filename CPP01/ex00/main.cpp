#include "Zombie.hpp"

int main()
{
    Zombie *z1;

    z1= newZombie("Sonic");
    z1->announce();
    randomChump("Bachus");

    delete z1;
    return 0;
}