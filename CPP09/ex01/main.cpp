#include <iostream>
#include "RNP.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Example usage: \"./RNP 1 2 +\"" << std::endl;
        return 1;
    }

    try
    {
        std::string expression(av[1]);
        double result = RNP::calculate(expression);
        std::cout << result << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
    return 0;
}