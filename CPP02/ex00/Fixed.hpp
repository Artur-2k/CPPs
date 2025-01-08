#pragma once

#include <iostream>

class Fixed
{
    private:
        int value;
        static const int bits;
    public:
        Fixed();
        Fixed(const Fixed &other);
        ~Fixed();

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        Fixed &operator = (const Fixed &other);

};