/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:18:26 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 14:18:32 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : value(0)
{
}
Fixed::Fixed(const Fixed &other)
{
    *this = other;
	
}

Fixed::Fixed(const int num) : value(num * (1 << bits))
{
}

Fixed::Fixed(const float num) : value(static_cast<int>(roundf(num * (1  << bits))))
{
}

Fixed::~Fixed()
{
}

int Fixed::toInt ( void ) const
{
    return (static_cast<int>(roundf(static_cast<float>(value) / (1 << bits))));
}

float Fixed::toFloat ( void ) const
{
    return (static_cast<float>(value) / (1 << bits));
}

int Fixed::getRawBits( void ) const
{
    return value;
}

void Fixed::setRawBits( int const raw )
{
	value = raw;
}

Fixed Fixed::operator + (const Fixed &other)
{
	Fixed ret (*this);
	ret.value += other.getRawBits();
	return ret;
}

Fixed Fixed::operator - (const Fixed &other)
{
	Fixed ret (*this);
	ret.value += other.getRawBits();
	return ret;
}

Fixed Fixed::operator * (const Fixed &other)
{
	Fixed retval;
	retval.setRawBits((this->value * other.getRawBits()) >> this->bits);
	return (retval); 
}

Fixed Fixed::operator / (const Fixed &other)
{
	Fixed retval;
	retval.setRawBits((this->value << this->bits) / other.getRawBits());
	return (retval);
}

Fixed &Fixed::operator = (const Fixed &other)
{
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

bool Fixed::operator < (const Fixed &other) const
{
	return (this->value < other.getRawBits());	
}

bool Fixed::operator <= (const Fixed &other) const
{
	return (this->value <= other.getRawBits());	
}

bool Fixed::operator > (const Fixed &other) const
{
	return (this->value > other.getRawBits());	
}

bool Fixed::operator >= (const Fixed &other) const
{
	return (this->value >= other.getRawBits());	
}

bool Fixed::operator != (const Fixed &other) const
{
	return (this->value != other.getRawBits());	
}

bool Fixed::operator == (const Fixed &other) const
{
	return (this->value == other.getRawBits());	
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a < b ? b : a);

}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a < b ? b : a);

}

Fixed Fixed::operator ++ () // pre increment
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator ++ (int) // post increment
{
	Fixed old(*this);
	this->value++;
	return (old);
}

Fixed Fixed::operator -- () // pre increment
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator -- (int) // post increment
{
	Fixed old(*this);
	this->value--;
	return (old);
}


std::ostream &operator <<(std::ostream &os, Fixed const &fixedPoint)
{
    os << fixedPoint.toFloat();
    return os;
}
