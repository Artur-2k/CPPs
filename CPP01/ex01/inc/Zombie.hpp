#pragma once

#include <string>
#include <iostream>

class Zombie
{
    private:
        std::string _name;

    public:
        Zombie( void );
        Zombie(std::string& n);
        ~Zombie();

    void    announce( void );
    void    set_name(std::string& n);
};

Zombie* zombieHorde( int N, std::string _name );