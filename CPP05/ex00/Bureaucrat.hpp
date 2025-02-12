/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:23:33 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/12 22:31:17 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <exception>
#include <iostream>
class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
    Bureaucrat() : _name("unknown"), _grade(150) {};
    Bureaucrat(const std::string &name, int grade) : _name(name) 
    {
        if (grade < 1) throw GradeTooHighException();
        
        if (grade > 150) throw GradeTooLowException();
        
        _grade = grade;
    }
    Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}
    ~Bureaucrat() {}
    Bureaucrat operator=(const Bureaucrat &other) 
    {
        if (this != &other)
        {
            this->_grade = other._grade;
        }
        return *this;
    }

    const std::string& getName() const 
    {
        return _name;
    }
     
    int getGrade() const
    {
        return _grade;
    } 

    void incrementGrade()
    {
        if (_grade == 1) throw GradeTooHighException();
        _grade--;
    }
    
    void decrementGrade()
    {
        if (_grade == 150) throw GradeTooLowException();
        _grade++;
    }

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

std::ostream& operator<<(std::ostream&os, const Bureaucrat &bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}