/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 15:30:25 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/07 12:19:41 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <vector>
#include <algorithm>
#include <iostream> //todo delete

class Span
{
private:
    unsigned int _N;
    std::vector<int> _vec;
public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    ~Span();
    
    Span& operator= (const Span& other);
    
    unsigned int getMaxCapacity() const;
    
    // adds a new number if not at max number capacity (_N). if that happens throws an exception
    void addNumber(int num); 

    template <class T>
    void addNumber(T begin, T end)
    {
        if (_vec.size() + std::distance(begin, end) > _N) throw std::runtime_error("Adding will exceed maximum capacity");
        
        for (T it = begin; it != end; ++it)
            _vec.push_back(*it);
    }
    
    int shortestSpan() const;
    int longestSpan() const;
    int size() const;
    void print() const;
};