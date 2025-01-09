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
		// TODO <>!=== ++ ++ -- -- and min max
};

std::ostream &operator <<(std::ostream &so, const Fixed &fixedPoint);
