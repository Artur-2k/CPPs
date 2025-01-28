/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:00:28 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:00:29 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string n) : _name(n) 
{
    std::cout << this->_name << " was bitten by a zombie;" << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " was killed by an ally." << std::endl;
}

void Zombie::announce( void )
{
    std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
