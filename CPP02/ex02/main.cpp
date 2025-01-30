#include "Fixed.hpp"

// Macros for red, green, and reset colors
# define RED    "\033[31m"
# define GREEN  "\033[32m"
# define RESET  "\033[0m"

int main( void )
{
	Fixed a;
	Fixed b(4.20f);
	Fixed c(b);
	Fixed d(69);
	a = d;

	//Constructors
	std::cout << "Constructors" << std::endl;
	std::cout << RED << "b(4.20f): " << GREEN  << b << RESET << std::endl;
	std::cout << RED << "c(B): " << GREEN  << c << RESET << std::endl;
	std::cout << RED << "d(69): " << GREEN  << d << RESET << std::endl;
	std::cout << RED << "a=d: " << GREEN  << a << RESET << std::endl;

	std::cout << "+ - * /" << std::endl;
	std::cout << RED << "b + c: " << GREEN  << b + c << RESET << std::endl;
	std::cout << RED << "b - c: " << GREEN  << b - c << RESET << std::endl;
	std::cout << RED << "a * d: " << GREEN  << a * d << RESET << std::endl;
	std::cout << RED << "b / c: " << GREEN  << b / c << RESET << std::endl;
	
	std::cout << "< <= >= != ==" << std::endl;
	std::cout << RED << "a < d: " << GREEN  << (a < d) << RESET << std::endl;
	std::cout << RED << "a <= d: " << GREEN  << (a <= d) << RESET << std::endl;
	std::cout << RED << "b > c: " << GREEN  << (b > c) << RESET << std::endl;
	std::cout << RED << "d >= b: " << GREEN  << (d >= b) << RESET << std::endl;
	std::cout << RED << "a != c: " << GREEN  << (a != c) << RESET << std::endl;
	std::cout << RED << "a == d: " << GREEN  << (a == d) << RESET << std::endl;

	std::cout << "INCREMENT/DECREMENT OF RAWBITS" << std::endl;
	std::cout << RED << "d: " << GREEN  << d.getRawBits() << RESET << std::endl;
	std::cout << RED << "++d: " << GREEN  << (++d).getRawBits() << RESET << std::endl;
	std::cout << RED << "d++: " << GREEN  << (d++).getRawBits() << RESET << std::endl;
	std::cout << RED << "d: " << GREEN  << d.getRawBits() << RESET << std::endl;

	std::cout << RED << "--d: " << GREEN  << (--d).getRawBits() << RESET << std::endl;
	std::cout << RED << "d--: " << GREEN  << (d--).getRawBits() << RESET << std::endl;
	std::cout << RED << "d: " << GREEN  << d.getRawBits() << RESET << std::endl;


	return 0;
}
