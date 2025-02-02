/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:37:11 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/31 23:06:44 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        std::string _name;
        
    public:
        DiamondTrap();
        DiamondTrap(const std::string &name);
        DiamondTrap(const DiamondTrap &other);
        DiamondTrap& operator= (const DiamondTrap& other);
        ~DiamondTrap();
        
        // Bringing the attack method to DiamondTrap's scope
        using ScavTrap::attack;;
        
        // Getter
        std::string getName() const;
        
        // Setter
        void setName(const std::string &newName);

        void whoAmI();
};
