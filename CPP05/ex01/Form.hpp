/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:48:19 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/13 12:34:05 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _signGrade;
        const int _execGrade;
    public:
        Form();
        Form(const Form &other);
        Form(const std::string name, const int signGrade, const int execGrade);
        ~Form();
        Form& operator= (const Form &other);

        const std::string& getName() const;
        int getSignGrade() const;
        int getExecGrade() const;
        bool getIsSigned() const;

        void setIsSigned(bool value);

        void beSigned(const Bureaucrat &bureaucrat);

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

std::ostream& operator<< (std::ostream& os, const Form &form);