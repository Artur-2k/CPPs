/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:00:55 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:00:56 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &wpn) : _name(name), _wpn(wpn) {};

HumanA::~HumanA() {};

void HumanA::attack() const
{
    std::cout << this->_name 
    << " attacks with their "
    << this->_wpn.getType()
    << std::endl;
}