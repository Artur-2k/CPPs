/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:17:06 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/10 15:17:09 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat default constructor called" << std::endl;
    type = "Cat";
}

Cat::Cat(const Cat &other) : Animal()
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;    
}

Cat& Cat::operator= (const Cat &other)
{
    std::cout << "Cat operator= called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
    }
    return *this;
}


void Cat::makeSound() const
{
    std::cout << "Cat sounds" << std::endl;    
}

