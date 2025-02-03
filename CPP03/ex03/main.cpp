/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:56:31 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/03 11:22:25 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
hp      100
ep      50
atk     30

*/

#define CLEAR_SCREEN "\033[2J\033[1;1H"

#include "DiamondTrap.hpp"

int main()
{
    char ch;

    std::cout << CLEAR_SCREEN;
    
    {    
        std::cout << "CREATING DIAMOND TRAP PARAMETER PZZZZZZ\n" << std::endl;

        DiamondTrap diamond("Arturito");


        std::cout << "\nChecking what the fuck is in DIAMOND TRAP PZZZZZZ\n" << std::endl;

        std::cout   << "ClapTrap name: " << diamond.ClapTrap::getName() << "\n"
                    << "DiamondTrap name: " << diamond.getName() << "\n"
                    << "HP: " << diamond.getHitPoints() << "\n"
                    << "Energy: " << diamond.getEnergyPoints() << "\n"
                    << "Attack dmg: " << diamond.getAttackDamage() << "\n" <<
        std::endl;

        std::cout << "\nChecking attack abilitie PZZZZZZ\n" << std::endl;

        diamond.attack("Tomas");
        
        std::cout << std::endl;
    }

    std::cin >> ch;

    std::cout << CLEAR_SCREEN;

    {    
        std::cout << "CREATING DIAMOND TRAP DEFAULT PZZZZZZ\n" << std::endl;

        DiamondTrap diamond;


        std::cout << "\nChecking what the fuck is in DIAMOND TRAP PZZZZZZ\n" << std::endl;

        std::cout   << "ClapTrap name: " << diamond.ClapTrap::getName() << "\n"
                    << "DiamondTrap name: " << diamond.getName() << "\n"
                    << "HP: " << diamond.getHitPoints() << "\n"
                    << "Energy: " << diamond.getEnergyPoints() << "\n"
                    << "Attack dmg: " << diamond.getAttackDamage() << "\n" <<
        std::endl;

        std::cout << "\nChecking attack abilitie PZZZZZZ\n" << std::endl;

        diamond.attack("Tomas");
        
        std::cout << std::endl;
    }

    std::cin >> ch;

    std::cout << CLEAR_SCREEN;

    {    
        std::cout << "CREATING DIAMOND TRAP COPY PZZZZZZ\n" << std::endl;

        DiamondTrap diamond = DiamondTrap("Sonic");

        std::cout << "\nChecking what the fuck is in DIAMOND TRAP PZZZZZZ\n" << std::endl;

        std::cout   << "ClapTrap name: " << diamond.ClapTrap::getName() << "\n"
                    << "DiamondTrap name: " << diamond.getName() << "\n"
                    << "HP: " << diamond.getHitPoints() << "\n"
                    << "Energy: " << diamond.getEnergyPoints() << "\n"
                    << "Attack dmg: " << diamond.getAttackDamage() << "\n" <<
        std::endl;

        std::cout << "\nChecking attack abilitie PZZZZZZ\n" << std::endl;

        diamond.attack("Tomas");
        
        std::cout << std::endl;

        std::cin >> ch;

        std::cout << "CHANGING DIAMOND TRAP PZZZZZZ\n" << std::endl;
        
        diamond = DiamondTrap("boomer");
        
                std::cout << "\nChecking what the fuck is in DIAMOND TRAP PZZZZZZ\n" << std::endl;

        std::cout   << "ClapTrap name: " << diamond.ClapTrap::getName() << "\n"
                    << "DiamondTrap name: " << diamond.getName() << "\n"
                    << "HP: " << diamond.getHitPoints() << "\n"
                    << "Energy: " << diamond.getEnergyPoints() << "\n"
                    << "Attack dmg: " << diamond.getAttackDamage() << "\n" <<
        std::endl;

        std::cout << "\nChecking attack abilitie PZZZZZZ\n" << std::endl;

        diamond.attack("Tomas");
        
        std::cout << std::endl;
    }

    {
       std::cout << std::endl;

        std::cin >> ch;

        std::cout << "WHOAMI TESTER PZZZZZZ\n" << std::endl;

       DiamondTrap funtester("Catarina");

       std::cout << "\nWHOAMI TESTER PZZZZZZ\n" << std::endl;

       funtester.whoAmI();

        std::cout << std::endl;
       
       funtester = DiamondTrap("Artur");

       std::cout << "\nWHOAMI TESTER PZZZZZZ\n" << std::endl;
       funtester.whoAmI();
    }

    return 0;
}