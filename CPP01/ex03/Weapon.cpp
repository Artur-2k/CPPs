/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:01:12 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:01:13 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {};

const std::string& Weapon::getType() const
{
    return this->_type;
}

void Weapon::setType(const std::string newType)
{
    _type = newType;
}

Weapon& Weapon::operator=(const Weapon &other)
{
    if (this != &other)
        this->_type = other.getType();
    return *this;
}
