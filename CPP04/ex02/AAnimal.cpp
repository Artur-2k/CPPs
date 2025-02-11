/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:16:44 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/11 11:35:32 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("")
{
    std::cout << "AAnimal default constructor called" << std::endl;    
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = other;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;    
}

AAnimal& AAnimal::operator= (const AAnimal& other)
{
    std::cout << "AAnimal operator = called" << std::endl;
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

std::string AAnimal::getType() const
{
    return type;
}
