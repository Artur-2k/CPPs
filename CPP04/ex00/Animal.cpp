/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:16:44 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/10 15:12:54 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("")
{
    std::cout << "Animal default constructor called" << std::endl;    
}

Animal::Animal(const Animal &other)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = other;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;    
}

Animal& Animal::operator= (const Animal& other)
{
    std::cout << "Animal operator = called" << std::endl;
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

std::string Animal::getType() const
{
    return type;
}

void Animal::makeSound() const
{
    std::cout << "Animal sound" << std::endl;
}
