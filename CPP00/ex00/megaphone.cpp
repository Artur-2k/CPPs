#include <iostream>
#include <string>
#include <cctype>

int main (int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }

    for (int i = 1; i < ac; i++)
    {
        std::string str = av[i]; 
        for (int j = 0; str[j]; j++)
        {
            if (islower(str[j]))
                str[j] = toupper(str[j]);
        }
        std::cout << str;
    }
    std::cout << std::endl;
    return 0;
}