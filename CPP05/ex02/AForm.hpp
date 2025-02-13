/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:25:45 by fang              #+#    #+#             */
/*   Updated: 2025/02/13 20:38:45 by fang             ###   ########.fr       */
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
        ~AForm();
        AForm& operator= (const AForm &other);

        const std::string& getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getIsSigned() const;

        void setIsSigned(bool value);

        void beSigned(const Bureaucrat &bureaucrat);
        virtual void beExecuted(const Bureaucrat &bureaucrat) = 0;

        class AlreadySigned : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "From is Already Signed";        
                }
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade is Too Low";        
                }
        };
        
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return "Grade is Too High";        
                }
        };
};

std::ostream& operator<< (std::ostream& os, const AForm &form);