/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:56:16 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/03 10:55:29 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    std::cout << "FragTrap parameter constructor called" << std::endl;
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);  
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other.getName())
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    setHitPoints(other.getHitPoints());
    setEnergyPoints(other.getEnergyPoints());
    setAttackDamage(other.getAttackDamage());   
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator= (const FragTrap &other)
{
    if (this != &other)
    {
        setName(other.getName());
        setHitPoints(other.getHitPoints());
        setEnergyPoints(other.getEnergyPoints());
        setAttackDamage(other.getAttackDamage());  
    }    
    return *this;
}

void FragTrap::highFivesGuys(void)
{
    if (getEnergyPoints() <= 0 || getHitPoints() <= 0) return ;
    
    std::cout << "Hi five me please I'm beg- NOO PLEASE DONT LEAVE..." << std::endl;
    setEnergyPoints(getEnergyPoints() - 1);

    return ;
}