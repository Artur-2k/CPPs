/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:44:10 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/29 22:44:11 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main ()
{
    ClapTrap a;
    ClapTrap b("antonio");
    ClapTrap c("jose");
    a = b;

    std::cout << "\n";
    std::cout << "a energy before attacking: " << a.getEnergyPoints() << std::endl;
    a.attack("uma pedra qualquer");
    std::cout << "a energy after attacking: " << a.getEnergyPoints() << std::endl;


    std::cout << "\n";

    std::cout << "B energy before attacking: " << b.getEnergyPoints() << std::endl;
    std::cout << "B hitpoints before taking damage: " << b.getHitPoints() << std::endl;
    b.beRepaired(420);
    std::cout << "B hitpoints after reparing: " << b.getHitPoints() << std::endl;
    std::cout << "B energy after attacking: " << b.getEnergyPoints() << std::endl;
    
    std::cout << "\n";
    std::cout << "C hitpoints before taking damage: " << c.getHitPoints() << std::endl;
    c.takeDamage(69);
    std::cout << "C hitpoints after taking damage: " << c.getHitPoints() << std::endl;
    std::cout << "\n";

    return 0;
}