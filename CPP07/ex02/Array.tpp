/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:43:59 by artuda-s          #+#    #+#             */
/*   Updated: 2025/04/01 18:56:22 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Array.hpp"

// new type[0] will return a valid pointer to that type but we cannot dereference it!
template <class T>
Array<T>::Array() : _array(new T[0]), _size(0) {}

// new T[n]() new type[n]() initializes to 0
template <class T>
Array<T>::Array(const unsigned int n) : _size(n)
{
    try {
        _array = new T[n]();
    } catch (std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return;
    }
}

template <class T>
Array<T>::Array(const Array &other)
{
    try{
        this->_size = other._size;
        this->_array = new T[this->_size]();
        for (unsigned int i = 0; i < this->_size; i++)
            this->_array[i] = other._array[i];
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    
}

template <class T>
Array<T>& Array<T>::operator= (const Array<T> &other)
{
    if (this != &other)
    {
        this->_size = other._size;

        // assuring a deep copy
        delete[] this->_array;
        try{
            this->_array = new T[this->_size]();
        }
        catch(const std::exception& e){
            std::cerr << e.what() << std::endl;
            throw;
        }
        for (size_t i = 0; i < this->_size; i++)
            this->_array[i] = other._array[i];
    }
    return *this;
}

template <class T>
T& Array<T>::operator[] (size_t index)
{
    if (_size == 0 || index > this->_size - 1) throw std::out_of_range("Index is out of bounds");
    
    return this->_array[index];
}

template <class T>
const T& Array<T>::operator[] (size_t index) const
{
    if (_size == 0 || index > this->_size - 1) throw std::out_of_range("Index is out of bounds");
    
    return this->_array[index];
}


template <class T>
unsigned int Array<T>::size(void) const
{ return this->_size; }

template <class T>
Array<T>::~Array()
{ 
    if (_array)
        delete[] _array;
}
