/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 17:17:51 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/11 10:48:36 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}
Brain::~Brain() 
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator= (const Brain &other)
{
    if (this != &other)
    {
        // Deep copy
        for (int i = 0; i < 100; i++)
            ideas[i] = other.ideas[i];
    }
    return *this;
}

void Brain::append(std::string &idea, int idx)
{
    if (100 > idx && idx >= 0)
        ideas[idx] = idea;
}

void Brain::printIdea(int idx)
{
   if (100 > idx && idx >= 0)
        std::cout << ideas[idx] << std::endl;
}