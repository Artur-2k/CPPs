#pragma once

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie(std::string n);
        ~Zombie();

        void    announce( void );
};

Zombie* newZombie( std::string _name );
void randomChump( std::string _name );
