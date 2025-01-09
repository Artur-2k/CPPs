#include "Fixed.hpp"

const int Fixed::bits = 8;

Fixed::Fixed() : value(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
	
}

Fixed::Fixed(const int num) : value(num * (1 << bits))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : value(static_cast<int>(roundf(num * (1  << bits))))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::toInt ( void ) const
{
    return (value >> bits);
}

float Fixed::toFloat ( void ) const
{
    return (static_cast<float>(value) / (1 << bits));
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
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
	return (Fixed((this->value * other.value) >> this->bits)); 
}

Fixed Fixed::operator / (const Fixed &other)
{
	return (Fixed((this->value << this->bits) / other.getRawBits()));
}

Fixed &Fixed::operator = (const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->value = other.getRawBits();
	return *this;
}

std::ostream &operator <<(std::ostream &os, Fixed const &fixedPoint)
{
    os << fixedPoint.toFloat();
    return os;
}
