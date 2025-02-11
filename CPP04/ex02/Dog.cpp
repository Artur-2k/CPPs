/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:16:41 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/11 10:59:06 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog default constructor called" << std::endl;
    brain = new Brain();
    type = "Dog";
}

Dog::Dog(const Dog &other) : Animal()
{
    std::cout << "Dog copy constructor called" << std::endl;
    brain = new Brain(*other.brain);
    *this = other;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

Dog& Dog::operator= (const Dog &other)
{
    std::cout << "Dog operator= called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other); // copies type or wte i dont remember fuck this exercises -.-
        delete brain;
        brain = new Brain(*other.brain); // this does a deep copy
    }
    return *this;
}


void Dog::makeSound() const
{
    std::cout << "Dog sounds" << std::endl;    
}

