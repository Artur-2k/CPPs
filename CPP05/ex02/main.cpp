/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:25:49 by fang              #+#    #+#             */
/*   Updated: 2025/02/16 14:01:24 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define RESET   "\033[0m"
#define CLEAR_SCREEN "\033[2J\033[1;1H"

/* TODO
 * test robotomy and shruberry
*/

void testForm(Bureaucrat &b, AForm &f, const std::string& description) {
    std::cout << CLEAR_SCREEN;
    std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
    std::cout << description << std::endl;
    std::cout << std::endl;

    std::cout << f;
    std::cout << std::endl;

    try {
        b.signForm(f);
        b.executeForm(f);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << f;
    std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
    std::cin.get();
}


int main() 
{
    // SHRUBBERRY TEST
    {
        Bureaucrat b("Duck n1", 10);
        ShrubberyCreationForm f("Duck1's Target");
        testForm(b, f, GREEN "Valid ShrubberyCreationForm execution\nBurucrat with grade 10 (S:145 & E:137)" RESET);
    }
    {
        Bureaucrat b("Duck n2", 150);
        ShrubberyCreationForm f("Duck2's Target");
        testForm(b, f, RED "Invalid ShrubberyCreationForm sign\nBurucrat with grade 150 (S:145 & E:137)" RESET);
    }
    {
        Bureaucrat b("Duck n3", 140);
        ShrubberyCreationForm f("Duck3's Target");
        testForm(b, f, RED "Invalid ShrubberyCreationForm execution\nBurucrat with grade 140 (S:145 & E:137)" RESET);
    }
 
   // ROBOTOMY TEST 
   {
        Bureaucrat b("Duck n1", 10);
        RobotomyRequestForm f("Duck1's Target");
        testForm(b, f, GREEN "Valid RobotomyRequestForm execution\nBurucrat with grade 10 (S:72 & E:45)" RESET);
    }
    {
        Bureaucrat b("Duck n2", 150);
        RobotomyRequestForm f("Duck2's Target");
        testForm(b, f, RED "Invalid RobotomyRequestForm sign\nBurucrat with grade 150 (S:72 & E:45)" RESET);
    }
    {
        Bureaucrat b("Duck n3", 50);
        RobotomyRequestForm f("Duck3's Target");
        testForm(b, f, RED "Invalid RobotomyRequestForm execution\nBurucrat with grade 50 (S:72 & E:45)" RESET);
    }
      // PARDON TEST 
   {
        Bureaucrat b("Duck n1", 1);
        PresidentialPardonForm f("Duck1's Target");
        testForm(b, f, GREEN "Valid PresidentialPardonForm execution\nBurucrat with grade 1 (S:25 & E:5)" RESET);
    }
    {
        Bureaucrat b("Duck n2", 150);
        PresidentialPardonForm f("Duck2's Target");
        testForm(b, f, RED "Invalid PresidentialPardonForm sign\nBurucrat with grade 150 (S:25 & E:5)" RESET);
    }
    {
        Bureaucrat b("Duck n3", 7);
        PresidentialPardonForm f("Duck3's Target");
        testForm(b, f, RED "Invalid PresidentialPardonForm execution\nBurucrat with grade 7 (S:25 & E:5)" RESET);
    }
    return 0;
}
