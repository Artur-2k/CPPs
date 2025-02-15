/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 20:25:36 by fang              #+#    #+#             */
/*   Updated: 2025/02/15 16:14:30 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <string>
#include <exception>
#include <iostream>
#include "AForm.hpp"

class AForm;

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
    

    void signForm(AForm &form) const;
    void executeForm(const AForm &form);
    
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
