#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wpn) : _name(name), _wpn(wpn) {};

HumanA::~HumanA() {};

void HumanA::attack() const
{
    std::cout << this->_name 
    << " attacks with their "
    << this->_wpn.getType()
    << std::endl;
}