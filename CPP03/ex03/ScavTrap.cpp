/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:56:46 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/03 10:54:32 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "ScavTrap parameter constructor called" << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);                
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other.getName())
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other; 
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator= (const ScavTrap &other)
{
    std::cout << "ScavTrap operator = called" << std::endl;
    if (this != &other)
    {
        setName(other.getName());
        setEnergyPoints(other.getEnergyPoints());
        setAttackDamage(other.getAttackDamage());
        setHitPoints(other.getHitPoints());
    }
    return *this;
}

void ScavTrap::guardGate()
{
    if (getEnergyPoints() <= 0 || getHitPoints() <= 0) return ;

    std::cout << getName() << " is in guard mode" << std::endl;
    setEnergyPoints(getEnergyPoints() - 1);
    return ;
}