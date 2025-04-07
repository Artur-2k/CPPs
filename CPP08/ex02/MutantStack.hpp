/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 15:33:25 by fang              #+#    #+#             */
/*   Updated: 2025/04/03 20:24:30 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//Includes
#include <deque>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{
public:
    //Default Constructor
    MutantStack() : std::stack<T>() {};

    //Copy Constructor
    MutantStack(const MutantStack &other) { *this = other; };

    //Destructor
    ~MutantStack() {};

    //Copy Constructor
    MutantStack& operator= (const MutantStack &other) 
    {
        if (this != &other)
            this->c = other.c;
        return *this;
    };
    
    // Expose iterators
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator  const_iterator;

    // begin() and end()
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

};