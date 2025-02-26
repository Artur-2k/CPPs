/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:28:32 by fang              #+#    #+#             */
/*   Updated: 2025/02/16 16:26:13 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

//Default Constructor
Intern::Intern() {}

//Copy Constructor
Intern::Intern(const Intern &other) { (void)other; }

//Destructor
Intern::~Intern() {}

//Copy operator
Intern& Intern::operator= (const Intern &other)
{
    (void)other;
    return *this;
}

// Creators
AForm* Intern::createSCForm(const std::string &target) const
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRRForm(const std::string &target) const
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPPForm(const std::string &target) const
{
    return new PresidentialPardonForm(target);
}

const Intern::creators Intern::array[] = 
{
    {"shrubberry creation", &Intern::createSCForm},
    {"robotomy", &Intern::createRRForm},
    {"presidential pardon", &Intern::createPPForm}
};

AForm* Intern::makeForm(const std::string &formName, const std::string &target)
{
    for (size_t i = 0; i < 3; i++)
    {
        if (formName == array[i].type)
        {
            std::cout << YELLOW "Intern creates " << GREEN << array[i].type << YELLOW <<" form." <<RESET  << std::endl;
            // this is needed cuz creator is a pointer to a MEMBER function
            return (this->*array[i].creator)(target); // what the fuck moment xd
        }
    }
    throw NotAForm(); // not found
}

const char* Intern::NotAForm::what() const throw()
{
    return "Not a Known Form";
}

