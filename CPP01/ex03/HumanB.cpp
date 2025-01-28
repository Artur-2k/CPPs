/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:00:59 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:01:02 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) ,_wpn(NULL) {};

HumanB::~HumanB() {};

void HumanB::setWeapon(Weapon &wpn)
{
    this->_wpn = &wpn;
}

void HumanB::attack() const
{
    std::cout << this->_name 
    << " attacks with their "
    << (_wpn ? _wpn->getType() : "hands.")
    << std::endl;
}