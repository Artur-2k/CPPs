/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:35:28 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/31 17:09:16 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() :  _name("unknown"),
                        _hitPoints(10),
                        _energyPoints(10),
                        _attackDamage(0) 
{
    std::cout << GREEN << "ClapTrap Constructor" << RESET << " called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &other) 
{
    std::cout << GREEN << "ClapTrap Copy constructor" << RESET << " called" << std::endl;

    *this = other;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << GREEN << "ClapTrap Parameter constructor" << RESET << " called" << std::endl;
}


ClapTrap::~ClapTrap() 
{
    std::cout << RED << "ClapTrap Destructor" << RESET << " called" << std::endl;
}

ClapTrap& ClapTrap::operator= (const ClapTrap &other)
{
    if (this != &other)
    {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    return *this;
}

// Getters
std::string ClapTrap::getName() const
{
    return this->_name;
}

int ClapTrap::getHitPoints() const
{
    return this->_hitPoints;
}

int ClapTrap::getAttackDamage() const
{
    return this->_attackDamage;
}

int ClapTrap::getEnergyPoints() const
{
    return this->_energyPoints;
}

// Setters
void ClapTrap::setHitPoints(const int ammount)
{
    _hitPoints = ammount;
}

void ClapTrap::setEnergyPoints(const int ammount)
{
    _energyPoints = ammount;
}

void ClapTrap::setAttackDamage(const int ammount)
{
    _attackDamage = ammount;
}

void ClapTrap::setName(const std::string &name)
{
    _name = name;
}

// Action functions
void ClapTrap::attack(const std::string &target)
{
    if (this->_energyPoints <= 0) return ;

    std::cout << "ClapTrap " << UGREEN << _name << RESET
    << BLUE << " attacks " << RESET << target 
    << ", causing " << _attackDamage << RESET
    << " points of damage" << std::endl;

    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= 0) return ;

    std::cout << "ClapTrap " << UGREEN <<_name << RESET
    << RED << " took " << RESET << amount << RESET
    << " points of damage " << std::endl;

    this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints <= 0) return ;

    std::cout << "ClapTrap " << UGREEN << _name << RESET
    << YELLOW << " restored " << RESET << amount << RESET
    << " hit points" << std::endl;
  
    _energyPoints--;
    _hitPoints += amount;
}
