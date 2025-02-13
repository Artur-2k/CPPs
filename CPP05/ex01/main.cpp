/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:15:27 by fang              #+#    #+#             */
/*   Updated: 2025/02/13 12:30:22 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "iostream"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

int main()
{ 
{  
    std::cout << GREEN "Valid Form" RESET << std::endl;
    try
    {
        Form duck("Valid", 75, 50);
        std::cout << duck;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
    
    std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
{
    std::cout << RED "Invalid too low Form" RESET << std::endl;
    try
    {
        Form duck("Invalid", 151, 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}    
    
    std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
{
    std::cout << RED "Invalid too high Form" RESET << std::endl;
    try
    {
        Form duck("Invalid", 0, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}    

    std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
{
        std::cout << GREEN "Valid trying to sign" RESET << std::endl;
        Bureaucrat foo("Toni", 1);
        Form bar("Valid", 75, 50);
        std::cout << std::endl;

        std::cout << foo;
        std::cout << bar;
        std::cout << std::endl;

        try
        {
            foo.signForm(bar);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
}

    std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
{
        std::cout << RED "Invalid too low trying to sign" RESET << std::endl;
        Bureaucrat foo("Toni", 150);
        Form bar("Valid", 75, 50);
        std::cout << std::endl;

        std::cout << foo;
        std::cout << bar;
        std::cout << std::endl;

        try
        {
            foo.signForm(bar);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
}
    std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
{
        std::cout << RED "Invalid already signed try to sign" RESET << std::endl;
        Bureaucrat foo("Toni", 1);
        Form bar("Valid", 75, 50);
        
        std::cout << foo;
        std::cout << bar;
        std::cout << std::endl;

        std::cout << "First sign" << std::endl;
        foo.signForm(bar);
        std::cout << bar;
        std::cout << std::endl;
        try
        {
            foo.signForm(bar);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
}
    return 0;
}