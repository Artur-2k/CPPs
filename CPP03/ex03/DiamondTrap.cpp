/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:37:13 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/31 23:08:37 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap() , FragTrap(), _name("unknown")
{
    // Log
    std::cout << "DiamondTrap default constructor called" << std::endl;
    
    // Setting to the values
    ClapTrap::setName("unknown_clap_name");
    setHitPoints(100); 
    setEnergyPoints(50);
    setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"),
                                                    ScavTrap(name),
                                                    FragTrap(name),
                                                    _name(name)
{
    // Log
    std::cout << "DiamondTrap parameterized constructor called" << std::endl;
    
    // Setting to the values
    setHitPoints(100); 
    setEnergyPoints(50);
    setAttackDamage(30);
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) :    ClapTrap(static_cast<const ClapTrap&>(other)),
                                                        ScavTrap(static_cast<const ScavTrap&>(other)),
                                                        FragTrap(static_cast<const FragTrap&>(other)),
                                                        _name(other.getName())
{
    // Log
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    // Log
    std::cout << "DiamondTrap destructor called" << std::endl;    
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& other)
{
    std::cout << "DiamondTrap operator= called" << std::endl;

    if (this != &other)
    {
        this->_name = other._name;
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
    }
    return *this;
}

// Getter
std::string DiamondTrap::getName() const
{
    return _name;    
}

// Setter
void DiamondTrap::setName(const std::string &newName)
{
    this->_name = newName;
    ClapTrap::setName(newName);
}

void Diamond trap::whoAmI() const
{
    std::cout << "DiamondTrap name: " << _name << std::endl
    std::cout << "ClapTrap name: << ClapTrap::_name << std::endl;
}