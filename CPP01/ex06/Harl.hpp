#pragma once

#include <iostream>
#include <map>

enum levelType
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	INVALID
};

class Harl
{
	private:
		std::map<std::string, void (Harl::*)(void)> type;

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );

	public:
		Harl();
		~Harl();
		void complain (std::string level);
		void filter (std::string level);

};