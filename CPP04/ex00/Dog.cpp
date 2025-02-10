/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:16:41 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/10 14:44:29 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    type = "Dog";
}

Dog::Dog(const Dog &other) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;    
}

Dog& Dog::operator= (const Dog &other)
{
    std::cout << "Dog operator= called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}


void Dog::makeSound() const
{
    std::cout << "Dog sounds" << std::endl;    
}

