#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) ,_wpn(NULL) {};

HumanB::~HumanB() {};

void HumanB::setWeapon(Weapon &wpn)
{
    this->_wpn = &wpn;
}


void HumanB::attack() const
{
    std::cout << this->_name 
    << " attacks with their "
    << (_wpn ? _wpn->getType() : "hands.")
    << std::endl;
}