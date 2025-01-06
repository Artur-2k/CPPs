#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {};

const std::string& Weapon::getType() const
{
    return this->_type;
}

void Weapon::setType(const std::string newType)
{
    _type = newType;
}

Weapon& Weapon::operator=(const Weapon &other)
{
    if (this != &other)
        this->_type = other.getType();
    return *this;
}
