/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:35:12 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/30 23:39:44 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav1;

    std::cout << scav1.getName() << " atk dmg: " << scav1.getAttackDamage()
    << " || hit points: " << scav1.getHitPoints()
    << " || energy points: " << scav1.getEnergyPoints() << std::endl;

    ScavTrap scav2("antonio");


    std::cout << scav2.getName() << " atk dmg: " << scav2.getAttackDamage()
    << " || hit points: " << scav2.getHitPoints()
    << " || energy points: " << scav2.getEnergyPoints() << std::endl;

    ScavTrap scav3(scav2);


    std::cout << scav3.getName() << " atk dmg: " << scav3.getAttackDamage()
    << " || hit points: " << scav3.getHitPoints()
    << " || energy points: " << scav3.getEnergyPoints() << std::endl;
    
        
    return 0;
}