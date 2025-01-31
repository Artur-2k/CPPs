/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:56:31 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/31 17:27:30 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FragTrap.hpp"

int main()
{
    {
        FragTrap ft1;

        std::cout << std::endl;

        ft1.highFivesGuys();

        std::cout << std::endl;

        std::cout << ft1.getName()  << " has " << ft1.getHitPoints()
                                    << " HP and " << ft1.getAttackDamage()
                                    << " Atk Dmg and " << ft1.getEnergyPoints()
                                    << " energy points" << std::endl;

        std::cout << std::endl;

        ft1 = FragTrap("Mikey Mouse");
        
        std::cout << std::endl;
        
        std::cout << ft1.getName()  << " has " << ft1.getHitPoints()
                                << " HP and " << ft1.getAttackDamage()
                                << " Atk Dmg and " << ft1.getEnergyPoints()
                                << " energy points" << std::endl;
    
        std::cout << std::endl;
    }    
    {
        std::cout << std::endl;
        
        FragTrap ft2("Amberosio");
        
        std::cout << std::endl;
        
        std::cout << ft2.getName()  << " has " << ft2.getHitPoints()
                                    << " HP and " << ft2.getAttackDamage()
                                    << " Atk Dmg and " << ft2.getEnergyPoints()
                                    << " energy points" << std::endl;

        std::cout << std::endl;

        FragTrap ft3(ft2);
        
        std::cout << std::endl;
        
        std::cout << ft2.getName()  << " has " << ft3.getHitPoints()
                                    << " HP and " << ft3.getAttackDamage()
                                    << " Atk Dmg and " << ft3.getEnergyPoints()
                                    << " energy points" << std::endl;

        std::cout << std::endl;
    }
    return 0;
}