/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 22:15:27 by fang              #+#    #+#             */
/*   Updated: 2025/02/13 10:47:53 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    std::cout << GREEN "Valid bureaucrat" RESET << std::endl;
    try
    {
        Bureaucrat duck(std::string("Arturito"), 75);
        std::cout << duck;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
    
    std::cout << "//////////////////////////////////////////" << std::endl;
{
    std::cout << RED "Invalid too low bureaucrat" RESET << std::endl;
    try
    {
        Bureaucrat duck(std::string("Manelito"), 200);
        std::cout << duck;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}    
    
    std::cout << "//////////////////////////////////////////" << std::endl;
{
    std::cout << RED "Invalid too high bureaucrat" RESET << std::endl;
    try
    {
        Bureaucrat duck(std::string("Manfarrico"), 0);
        std::cout << duck;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}    
    
    std::cout << "//////////////////////////////////////////" << std::endl;

{
    std::cout << GREEN "Valid increment and decrement grade" RESET << std::endl;
    try
    {
        Bureaucrat duck(std::string("Tone"), 50);
        std::cout << duck;
        
        std::cout << "incrementGrade:\n";
        duck.incrementGrade();
        std::cout << duck;
        
        std::cout << "decrementGrade:\n";
        duck.decrementGrade();
        std::cout << duck;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}    

    std::cout << "//////////////////////////////////////////" << std::endl;
{
    std::cout << RED "Invalid increment grade" RESET << std::endl;
    try
    {
        Bureaucrat tone(std::string("Maria"), 1);
        std::cout << tone;
        
        std::cout << "incrementGrade:\n";
        tone.incrementGrade();
        std::cout << tone;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
    
    std::cout << "//////////////////////////////////////////" << std::endl;
{
    std::cout << RED "Invalid decrement grade" RESET << std::endl;
    try
    {
        Bureaucrat tone(std::string("Pikachu"), 150);
        std::cout << tone;
        
        std::cout << "decrementGrade:\n";
        tone.decrementGrade();
        std::cout << tone;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}    
    return 0;
}