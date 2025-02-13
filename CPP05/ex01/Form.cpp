/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:48:19 by artuda-s          #+#    #+#             */
/*   Updated: 2025/02/13 12:35:01 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("unkown"),
            _isSigned(false),
            _signGrade(75),
            _execGrade(25) {}
            
            
Form::Form(const Form &other) : _name(other._name),
                            _isSigned(other._isSigned), 
                            _signGrade(other._signGrade), 
                            _execGrade(other._execGrade) {}

                            
Form::~Form() {}


Form& Form::operator= (const Form &other) {
    if (this != &other)
        this->_isSigned = other._isSigned;
    return *this;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name),
                                                                               _isSigned(false),
                                                                               _signGrade(signGrade),
                                                                               _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
}


const std::string& Form::getName() const { return _name; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecGrade() const { return _execGrade; }
bool Form::getIsSigned() const { return _isSigned; }

void Form::setIsSigned(bool value) { _isSigned = value; }


void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (_signGrade < bureaucrat.getGrade())
        throw GradeTooLowException();
    if (_isSigned)
        throw AlreadySigned();
    setIsSigned(true);
}


std::ostream& operator<< (std::ostream& os, const Form &form)
{
    os  << "Name: " << form.getName() << "\n"
        << "Is signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n"
        << "Sign Grade: " << form.getSignGrade() << "\n"
        << "Execution Grade: " << form.getExecGrade() << std::endl;
    return os;
}