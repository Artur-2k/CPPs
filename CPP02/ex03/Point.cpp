/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:30:29 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/31 16:29:37 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::Point( int x, int y ) : _x(x), _y(y) {}

Point::Point( float x, float y ) : _x(x), _y(y) {}

Point::Point (const Point &other) 
{
    *this = other;
}

Point::~Point( void ) {}

Point& Point::operator = ( const Point &other )
{
    if (this != &other)
    {
        std::cout << "stupid ass idea to make point coordinates const lol" << std::endl;
    }   
    return *this;
}

Fixed Point::getX( void ) const
{
    return this->_x;
}

Fixed Point::getY( void ) const
{
    return this->_y;
}
