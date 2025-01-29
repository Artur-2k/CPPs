/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:36:52 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/29 22:33:29 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define UGREEN "\033[4;32m"

class ClapTrap
{
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
        
    public: 
        ClapTrap();
        ClapTrap(ClapTrap &other);
        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap& operator = (const ClapTrap &other) ;

        std::string getName();
        int getHitPoints();
        int getAttackDamage();
        int getEnergyPoints();

        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};