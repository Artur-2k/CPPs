#include "sed.hpp"

int main(int ac, char *av[])
{
	(ac != 4) ? exit(1) : void();

	sed(av);

    std::cout << "GeT SeDed XDDD" << std::endl;
    return 0;
}