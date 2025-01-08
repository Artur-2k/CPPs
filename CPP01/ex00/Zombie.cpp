#include "Zombie.hpp"

Zombie::Zombie(std::string n) : _name(n) 
{
    std::cout << this->_name << " was bitten by a zombie;" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " was killed by an ally." << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
