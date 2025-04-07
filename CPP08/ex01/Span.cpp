/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:41:56 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/07 12:20:02 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default Constructor
// 10000 as the default because of the subject lol
Span::Span() : _N(10000) {}

// Param Constructor
Span::Span(unsigned int N) : _N(N) {}

// Copy Constructor
Span::Span(const Span& other)
{
    *this = other;
}

// Destructor
Span::~Span()
{}

// Assignment operator overload
Span& Span::operator= (const Span& other)
{
    if (this != &other)
    {
        this->_N = other._N;
        this->_vec = other._vec;
    }
    return *this;
}

// gets max integers number
unsigned int Span::getMaxCapacity() const { return this->_N; }


// adds a new number if not at max number capacity (_N). if that happens throws an exception
void Span::addNumber(int num)
{
    if (_vec.size() >= _N) throw std::runtime_error("Container at maximum capacity");

    _vec.push_back(num);
}

// O(N^2)
int Span::shortestSpan() const
{
    if (_vec.size() < 2) throw std::runtime_error("Not enough numbers");
    
    std::vector<int>::const_iterator it = _vec.begin();
    std::vector<int>::const_iterator it2 = _vec.begin(); it2++;
    
    int span = std::abs(*it - *it2);
    while (it != _vec.end() - 1) // we only need to go with it until the the (N - 1) element
    {
        std::vector<int>::const_iterator it2 = it;
        it2++;    
        while (it2 != _vec.end())
        {
            int test = std::max(*it, *it2) - std::min(*it, *it2);
        
            if (test < span)
                span = test;
            it2++;
        }
        it++;
    }
    return span;
}

// O(N^2)
int Span::longestSpan() const
{
    if (_vec.size() < 2) throw std::runtime_error("Not enough numbers");
    
    std::vector<int>::const_iterator it = _vec.begin();
    std::vector<int>::const_iterator it2 = _vec.begin(); it2++;
    
    int span = std::abs(*it - *it2);
    while (it != _vec.end() - 1) // we only need to go with it until the the (N - 1) element
    {
        std::vector<int>::const_iterator it2 = it;
        it2++;    
        while (it2 != _vec.end())
        {
            int test = std::max(*it, *it2) - std::min(*it, *it2);
        
            if (test > span)
                span = test;
            it2++;
        }
        it++;
    }
    return span;
}

int Span::size() const
{
    return _vec.size();
}

void Span::print() const
{
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << std::endl;
}

