/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:35:12 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/03 14:18:19 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ScavTrap scav1;
    std::cout << std::endl;
    std::cout <<scav1.getName() << " atk dmg: " << scav1.getAttackDamage()
    << " || hit points: " << scav1.getHitPoints()
    << " || energy points: " << scav1.getEnergyPoints() << std::endl;

    std::cout << std::endl;
    ScavTrap scav2("Antonio");
    std::cout << std::endl;
    std::cout <<scav2.getName() << " atk dmg: " << scav2.getAttackDamage()
    << " || hit points: " << scav2.getHitPoints()
    << " || energy points: " << scav2.getEnergyPoints() << std::endl;

    std::cout << std::endl;
    ScavTrap scav3(scav2);
    std::cout << std::endl;
    std::cout << scav3.getName() << " atk dmg: " << scav3.getAttackDamage()
    << " || hit points: " << scav3.getHitPoints()
    << " || energy points: " << scav3.getEnergyPoints() << std::endl;
    
    std::cout << std::endl;
    scav3.attack("Miguelito");
    std::cout << std::endl;

    scav2.guardGate();
    std::cout << std::endl;

    std::cout << "now without energy: " << std::endl;
    scav2.setEnergyPoints(0);
    scav2.guardGate();
    std::cout << "Nothing done as expected, right?: " << std::endl;
        
    std::cout << std::endl;

    return 0;
}