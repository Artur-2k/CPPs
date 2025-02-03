/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:56:52 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/03 14:16:04 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string &name);
        ScavTrap(const ScavTrap &other);
        ~ScavTrap();
        ScavTrap& operator= (const ScavTrap &other);

        void attack(const std::string &target);
        void guardGate();
};