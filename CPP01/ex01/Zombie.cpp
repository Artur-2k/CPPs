#include "Zombie.hpp"

Zombie::Zombie( void )
{
    std::cout << "Zombie noises from afar..." << std::endl;
}

Zombie::Zombie(std::string& n) : _name(n) 
{
    std::cout << _name << " was bitten by a zombie;" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " was killed by an ally." << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::set_name(std::string& n)
{
    this->_name = n;
}

