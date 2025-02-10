#include "WrongCat.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:16:41 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/10 14:44:29 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    std::cout << "WrongCat default constructor called" << std::endl;
    type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;    
}

WrongCat& WrongCat::operator= (const WrongCat &other)
{
    std::cout << "WrongCat operator= called" << std::endl;
    if (this != &other)
    {
        WrongAnimal::operator=(other);
    }
    return *this;
}


void WrongCat::makeSound() const
{
    std::cout << "WrongCat sounds" << std::endl;    
}

