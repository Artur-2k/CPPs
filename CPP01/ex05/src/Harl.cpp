#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[DEBUG]: I love having extra bacon for my \
	7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO}: I cannot believe adding extra bacon costs more money. You didn't put \
	enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[WARNING]:I think I deserve to have some extra bacon for free. I've been coming for \
	years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ERROR]: This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain (std::string level)
{

	std::map<std::string, void (Harl::*)(void)> type;

	type["DEBUG"] = &Harl::debug;
	type["INFO"] = &Harl::info;
	type["WARNING"] = &Harl::warning;
	type["ERROR"] = &Harl::error;
	try
	{
		(this->*type.at(level))();
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << level << ": bad test"<< std::endl;
	}
}

/** Unordered map is from c++11 	-.-
 * E não é possivel iniciar containers com {...} até o c++11
#include <unordered_map>
void Harl::complain (std::string level)
{

	std::unordered_map<std::string, void (Harl::*)(void)> type = {  {"DEBUG", Harl::debug},
																	{"INFO", Harl::info},
																	{"WARNING", Harl::warning},
																	{"ERROR", Harl::error}     };
	try
	{
		(this->*type.at(level))();
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
}
*/