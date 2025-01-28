/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:18:24 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 14:18:25 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int value;
        static const int bits;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed(const int num);
        Fixed(const float num);
        ~Fixed();


        int toInt ( void ) const;
        float toFloat ( void ) const;

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed &operator = (const Fixed &other);
        Fixed operator + (const Fixed &other);
        Fixed operator - (const Fixed &other);
        Fixed operator * (const Fixed &other);
        Fixed operator / (const Fixed &other);

        static Fixed& min(Fixed &a, Fixed &b);
        static const Fixed& min(const Fixed &a, const Fixed &b);
        static Fixed& max(Fixed &a,Fixed &b);
        static const Fixed& max(const Fixed &a, const Fixed &b);

        bool operator < (const Fixed &other) const;
        bool operator <= (const Fixed &other) const;
        bool operator > (const Fixed &other) const;
        bool operator >= (const Fixed &other) const;
        bool operator == (const Fixed &other) const;
        bool operator != (const Fixed &other) const;
        Fixed operator ++ (); // pre increment
        Fixed operator ++ (int); // post increment
        Fixed operator -- (); // pre increment
        Fixed operator -- (int); // post increment
};

std::ostream &operator <<(std::ostream &so, const Fixed &fixedPoint);
