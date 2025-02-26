/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:25:45 by fang              #+#    #+#             */
/*   Updated: 2025/02/16 16:34:21 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
    public:
        AForm();
        AForm(const AForm &other);
        AForm(const std::string name, const int signGrade, const int execGrade);
        virtual ~AForm();
        AForm& operator= (const AForm &other);

        const std::string& getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getIsSigned() const;

        void setIsSigned(bool value);

        void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(const Bureaucrat &executer) const = 0;



        class IsntSigned : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class AlreadySigned : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream& operator<< (std::ostream& os, const AForm &form);