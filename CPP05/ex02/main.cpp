/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:25:49 by fang              #+#    #+#             */
/*   Updated: 2025/02/15 16:32:23 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
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


int main()
{ 
    char ch;
    std::cout << CLEAR_SCREEN;
    std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
    std::cout << GREEN "Valid ShrubberyCreationForm execution" RESET << std::endl;
    std::cout << GREEN "Burucrat with grade 10 (S:145 & E:137)" RESET << std::endl;

    std::cout << std::endl;
{
    Bureaucrat b("Duck n1", 10);
    ShrubberyCreationForm SCForm("Duck's Target");
    std::cout << SCForm;
    std::cout << std::endl;
    
    try {
        b.signForm(SCForm);
        b.executeForm(SCForm);
    }catch(const std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << SCForm;
}
std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
std::cin >> ch;
std::cout << CLEAR_SCREEN;
std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
    std::cout << RED "Invalid ShrubberyCreationForm execution" RESET << std::endl;
    std::cout << RED "Burucrat with grade 140 (S:145 & E:137)" RESET << std::endl;
    std::cout << std::endl;

{
    Bureaucrat b("Duck n2", 140);
    ShrubberyCreationForm SCForm("Duck2's Target");
    std::cout << SCForm;
    std::cout << std::endl;

    
    try {
        b.signForm(SCForm);
        b.executeForm(SCForm);
    }catch(const std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << SCForm;
}
std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
std::cin >> ch;
std::cout << CLEAR_SCREEN;
std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
    std::cout << RED "Invalid ShrubberyCreationForm execution" RESET << std::endl;
    std::cout << RED "Burucrat with grade 140 (S:145 & E:137)" RESET << std::endl;
    std::cout << std::endl;

{
    Bureaucrat b("Duck n3", 140);
    ShrubberyCreationForm SCForm("Duck3's Target");
    std::cout << SCForm;
    std::cout << std::endl;

    
    try {
        b.signForm(SCForm);
        b.executeForm(SCForm);
    }catch(const std::exception& e){
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << std::endl;
    std::cout << SCForm;
}
std::cout << BLUE "//////////////////////////////////////////" RESET << std::endl;
    return 0;
}