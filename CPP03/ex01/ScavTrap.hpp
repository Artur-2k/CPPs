/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:34:59 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/30 23:44:09 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap()
        {
            std::cout << "ScavTrap default constructor called" << std::endl;
            setHitPoints(100);
            setEnergyPoints(50);
            setAttackDamage(20);
        }
        
        ScavTrap(const std::string &name) : ClapTrap(name)
        {
            std::cout << "ScavTrap parameter constructor called" << std::endl;
            setHitPoints(100);
            setEnergyPoints(50);
            setAttackDamage(20);                
        }
        
        ScavTrap(ScavTrap &other) : ClapTrap(other.getName())
        {
            std::cout << "ScavTrap copy constructor called" << std::endl;
            *this = other; 
        }

        ~ScavTrap()
        {
            std::cout << "ScavTrap destructor called" << std::endl;
        }

        ScavTrap& operator= (ScavTrap &other)
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
};