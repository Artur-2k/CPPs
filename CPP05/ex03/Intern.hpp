/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 14:19:58 by fang              #+#    #+#             */
/*   Updated: 2025/02/16 16:12:32 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

//Includes
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "colors.hpp"
#include <string>
#include <iostream>
#include <exception>

class Intern
{
    private:
        typedef AForm* (Intern::*createFormFun)(const std::string &target) const;
        
        struct creators
        {
            const std::string type;
            createFormFun creator;
        };

        static const creators array[];
        
        // Creators
        AForm* createSCForm(const std::string &target) const;
        AForm* createRRForm(const std::string &target) const;
        AForm* createPPForm(const std::string &target) const;

    public:
        //Default Constructor
        Intern();
        //Copy Constructor
        Intern(const Intern &other);
        //Destructor
        ~Intern();
        //Copy Constructor
        Intern& operator= (const Intern &other);

        AForm* makeForm(const std::string &formName, const std::string &target);

        class NotAForm : std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};