/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:25:49 by fang              #+#    #+#             */
/*   Updated: 2025/02/16 16:33:25 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.hpp"
#include <iostream>
#include "Intern.hpp"

int main()
{
    Intern josh;
    Bureaucrat Toni("Toni", 10);
    AForm *f1, *f2, *f3;

    std::cout << YELLOW "Toni asks josh to create forms: " RESET << std::endl;
    try
    {
        std::cout << std::endl;
        f1 = josh.makeForm("shrubberry creation", "Farm");
        std::cout << *f1;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    try
    {
        std::cout << std::endl;
        f2 = josh.makeForm("robotomy", "Artur");
        std::cout << *f2;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << std::endl;
        f3 = josh.makeForm("presidential pardon", "Toni");
        std::cout << *f3;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << std::endl;
        Toni.signForm(*f2);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << std::endl;
        Toni.executeForm(*f2);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << std::endl;
        Toni.signForm(*f3);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        Toni.executeForm(*f3);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "Toni: oops" << std::endl;
    }

    delete f1;
    delete f2;
    delete f3;
    return 0;
}
