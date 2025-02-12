/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fang <fang@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:21:35 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/12 22:38:01 by fang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("unknown"), _grade(150) {};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name) 
{
    if (grade < 1) throw GradeTooHighException();
    
    if (grade > 150) throw GradeTooLowException();
    
    _grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

///////////////////////////////////////////////////////////////
Bureaucrat Bureaucrat::operator=(const Bureaucrat &other) 
{
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return *this;
}

std::ostream& operator<<(std::ostream&os, const Bureaucrat &bureaucrat)
{
os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
return os;
}

//////////////////////////////////////////////////////////////

const std::string& Bureaucrat::getName() const 
{
    return _name;
}
 
int Bureaucrat::getGrade() const
{
    return _grade;
} 

void Bureaucrat::incrementGrade()
{
    if (_grade == 1) throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade()
{
    if (_grade == 150) throw GradeTooLowException();
    _grade++;
}
