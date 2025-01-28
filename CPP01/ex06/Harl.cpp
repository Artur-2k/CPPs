/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 22:01:36 by artuda-s          #+#    #+#             */
/*   Updated: 2025/01/28 22:01:37 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	this->type["DEBUG"] = &Harl::debug;
	this->type["INFO"] = &Harl::info;
	this->type["WARNING"] = &Harl::warning;
	this->type["ERROR"] = &Harl::error;
}

Harl::~Harl() {}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\n"
	<< "I really do!"
	<< std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money.\n"
	<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
	<< std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free.\n"
	<< "I've been coming for years whereas you started working here since last month."
	<< std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain (std::string level)
{
	try
	{
		(this->*type.at(level))();
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << level << ": bad test"<< std::endl;
	}
}

int getLevelNum(std::string &level)
{
	if (level == "DEBUG") return DEBUG;
	if (level == "INFO") return INFO;
	if (level == "WARNING") return WARNING;
	if (level == "ERROR") return ERROR;
	return INVALID;
}

void Harl::filter (std::string level)
{
	int lvNum = getLevelNum(level);
	switch (lvNum)
	{
	case DEBUG:
		std::cout << "[DEBUG]" << std::endl;
		this->debug();
		std::cout << "\n[INFO]" << std::endl;
		this->info();
		std::cout << "\n[WARNING]" << std::endl;
		this->warning();
		std::cout << "\n[ERROR]" << std::endl;
		this->error();
		break;
	case INFO:
		std::cout << "[INFO]" << std::endl;
		this->info();
		std::cout << "\n[WARNING]" << std::endl;
		this->warning();
		std::cout << "\n[ERROR]" << std::endl;
		this->error();
		break;
	case WARNING:
		std::cout << "[WARNING]" << std::endl;
		this->warning();
		std::cout << "\n[ERROR]" << std::endl;
		this->error();
		break;
	case ERROR:
		std::cout << "[ERROR]" << std::endl;
		this->error();
		break;

	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		break;
	}

}