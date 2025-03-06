/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:44:43 by artuda-s          #+#    #+#             */
/*   Updated: 2025/03/06 10:36:53 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template <class T>
class Array
{
    private:
        T *_array;
        unsigned int _size;
    public:
        Array();
        Array(const unsigned int n);
        Array(const Array &other);
        Array& operator= (const Array &other);
        T& operator[] (size_t index) const;
        ~Array();

        unsigned int size(void) const;
    
};

// Implementation
#include "Array.tpp"