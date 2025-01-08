#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);

	Harl satan;
	std::string level = av[1];
	satan.filter(level);

	return 0;
}