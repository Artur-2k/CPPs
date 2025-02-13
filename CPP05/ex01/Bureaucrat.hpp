/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:23:33 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/13 12:06:45 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat &other);

    const std::string& getName() const;     
    int getGrade() const;

    void incrementGrade();    
    void decrementGrade();
    

    void signForm(Form &form);
    
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw(){
                return "Grade is Too High";
            }
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw(){
                return "Grade is Too Low";
            }
    };
};

std::ostream& operator<<(std::ostream&os, const Bureaucrat &bureaucrat);
